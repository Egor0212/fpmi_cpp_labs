#include "catch.hpp"

#include "forward_list_impl.h"

#include <algorithm>
#include <forward_list>
#include <iterator>
#include <list>
#include <sstream>
#include <type_traits>

void Check(const ForwardList& actual, const std::forward_list<int32_t>& expected) {
    ForwardList::ForwardListIterator actual_it = actual.begin();
    std::forward_list<int32_t>::const_iterator expected_it = expected.begin();
    for (/*nothing*/; actual_it != actual.end() && expected_it != expected.cend();
         ++actual_it, ++expected_it) {
        REQUIRE(*actual_it == *expected_it);
    }
    REQUIRE((actual_it == actual.end() && expected_it == expected.cend()));
}

TEST_CASE("Fool", "[forward_list]") {
    INFO("Don't use std::forward_list or std::list, cheater!")
    STATIC_REQUIRE_FALSE(std::is_same_v<std::forward_list<int32_t>, ForwardList>);
    STATIC_REQUIRE_FALSE(std::is_base_of_v<std::forward_list<int32_t>, ForwardList>);
    STATIC_REQUIRE_FALSE(std::is_same_v<std::list<int32_t>, ForwardList>);
    STATIC_REQUIRE_FALSE(std::is_base_of_v<std::list<int32_t>, ForwardList>);
}

TEST_CASE("ForwardList has ctors", "[forward_list]") {
    STATIC_REQUIRE(std::is_default_constructible_v<ForwardList>);

    INFO("default ctor") {
        ForwardList a;
        REQUIRE(a.Size() == 0u);
        Check(a, std::forward_list<int32_t>());
    }

    INFO("user-defined ctor") {
        ForwardList a(10, 1);
        REQUIRE(a.Size() == 10u);
        Check(a, std::forward_list<int32_t>(10, 1));
    }

    INFO("initializer-list ctor") {
        ForwardList a{1, 2, 3, 4, 5};
        REQUIRE(a.Size() == 5u);
        Check(a, std::forward_list<int32_t>{1, 2, 3, 4, 5});
    }
}

TEST_CASE("Simple push/pop", "[forward_list]") {

    ForwardList a{1};
    REQUIRE(a.Size() == 1u);
    REQUIRE(a.Front() == 1);
    Check(a, std::forward_list<int32_t>{1});

    a.PushFront(2);
    REQUIRE(a.Size() == 2u);
    REQUIRE(a.Front() == 2);
    Check(a, std::forward_list<int32_t>{2, 1});

    a.PopFront();
    REQUIRE(a.Size() == 1u);
    REQUIRE(a.Front() == 1);
    Check(a, std::forward_list<int32_t>{1});

    ForwardList b{1, 2, 3, 1, 5, 1};
    Check(b, std::forward_list<int32_t>{1, 2, 3, 1, 5, 1});

    b.PopFront();
    b.PopFront();
    b.PopFront();
    Check(b, std::forward_list<int32_t>{1, 5, 1});
}

TEST_CASE("Advanced push/pop", "[forward_list]") {

    INFO("push then pop") {
        ForwardList actual;
        std::forward_list<int32_t> expected;
        for (int32_t i = 0; i < 100000; ++i) {
            actual.PushFront(i);
            expected.push_front(i);
        }
        Check(actual, expected);
        for (int32_t i = 0; i < 99999; ++i) {
            actual.PopFront();
            expected.pop_front();
        }
        Check(actual, expected);
        actual.PopFront();
        expected.pop_front();
        Check(actual, expected);
    }

    INFO("push and pop") {
        ForwardList actual;
        std::forward_list<int32_t> expected;
        for (int32_t i = 0; i < 100000; ++i) {
            actual.PushFront(i);
            expected.push_front(i);

            actual.PopFront();
            expected.pop_front();
        }
        Check(actual, expected);
    }
}

TEST_CASE("Finding values", "[forward_list]") {
    ForwardList flist{1, 2, 3, 4, 5, 6};
    REQUIRE(flist.FindByValue(1));
    REQUIRE(flist.FindByValue(2));
    REQUIRE(flist.FindByValue(3));
    REQUIRE(flist.FindByValue(4));
    REQUIRE(flist.FindByValue(5));
    REQUIRE(flist.FindByValue(6));
    REQUIRE_FALSE(flist.FindByValue(10));
    REQUIRE_FALSE(flist.FindByValue(100));
}

TEST_CASE("Copying", "[forward_list]") {
    STATIC_REQUIRE(std::is_copy_constructible_v<ForwardList>);

    ForwardList a{1, 2, 3, 4, 5, 6, 7};

    a = a;
    REQUIRE(a.Size() == 7u);
    Check(a, std::forward_list<int32_t>{1, 2, 3, 4, 5, 6, 7});

    ForwardList b = a;
    REQUIRE(b.Size() == 7u);
    REQUIRE(b.Front() == 1);
    Check(b, std::forward_list<int32_t>{1, 2, 3, 4, 5, 6, 7});

    ForwardList c;
    c = b;
    REQUIRE(c.Size() == 7u);
    REQUIRE(c.Front() == 1);
    Check(c, std::forward_list<int32_t>{1, 2, 3, 4, 5, 6, 7});
}

TEST_CASE("Clear", "[forward_list]") {
    ForwardList a;
    a.Clear();
    REQUIRE(a.Size() == 0u);
    Check(a, std::forward_list<int32_t>());

    ForwardList b{1, 2, 3, 4, 5, 6};
    ForwardList c = b;

    b.Clear();
    REQUIRE(a.Size() == 0u);
    Check(b, std::forward_list<int32_t>());

    REQUIRE(c.Size() == 6u);
    Check(c, std::forward_list<int32_t>{1, 2, 3, 4, 5, 6});
}

TEST_CASE("Iterator basics", "[forward_list]") {

    ForwardList a{1, 2, 3, 4, 5, 6};
    REQUIRE(std::distance(a.begin(), a.end()) == 6);

    ForwardList::ForwardListIterator it = a.begin();
    REQUIRE(*it == 1);
    REQUIRE(*(it.operator->()) == 1);
    ++it;
    REQUIRE(*it == 2);
    REQUIRE(*(it.operator->()) == 2);

    ForwardList::ForwardListIterator it2 = a.begin();
    it2++;
    REQUIRE(*it2 == 2);
    REQUIRE(*(it.operator->()) == 2);
    REQUIRE(it == it2);

    ForwardList::ForwardListIterator it3 = a.begin();
    REQUIRE(it != it3);
    REQUIRE(it2 != it3);
}

TEST_CASE("Modifications with iterators", "[forward_list]") {

    ForwardList a{1, 3, 5};
    *(a.begin().operator->()) = 3;
    *((++a.begin()).operator->()) = 4;

    Check(a, std::forward_list<int32_t>{3, 4, 5});
    ForwardList::ForwardListIterator it = a.begin();
    ++it;
    REQUIRE(*it == 4);
}

TEST_CASE("Iterator loop", "[forward_list]") {

    ForwardList a{1, 2, 3, 4, 5, 6};

    INFO("usage in std::copy") {
        ForwardList::ForwardListIterator it = a.begin();
        ++it;

        std::stringstream sstream;
        std::copy(it, a.end(), std::ostream_iterator<int32_t>(sstream));
        REQUIRE(sstream.str() == "23456");
    }

    INFO("usage in for-loop") {
        std::stringstream sstream;
        for (auto iter = a.begin(); iter != a.end(); ++iter) {
            sstream << *iter;
        }
        REQUIRE(sstream.str() == "123456");
    }

    INFO("usage in for-each") {
        std::stringstream sstream;
        for (int32_t item : a) {
            sstream << item;
        }
        REQUIRE(sstream.str() == "123456");
    }

    Check(a, std::forward_list<int32_t>{1, 2, 3, 4, 5, 6});
}

TEST_CASE("Remove(single elements)", "[forward_list]") {

    ForwardList a{1, 2, 3, 4, 5, 6};

    a.Remove(4);
    REQUIRE(a.Size() == 5u);
    REQUIRE(a.Front() == 1);
    Check(a, std::forward_list<int32_t>{1, 2, 3, 5, 6});

    a.Remove(1);
    REQUIRE(a.Size() == 4u);
    REQUIRE(a.Front() == 2);
    Check(a, std::forward_list<int32_t>{2, 3, 5, 6});

    a.Remove(6);
    REQUIRE(a.Size() == 3u);
    REQUIRE(a.Front() == 2);
    Check(a, std::forward_list<int32_t>{2, 3, 5});
}

TEST_CASE("Remove(repeated elements)", "[forward_list]") {

    ForwardList a{1, 1, 1, 5, 2, 5, 1, 8, 1};

    a.Remove(1);
    REQUIRE(a.Size() == 4u);
    REQUIRE(a.Front() == 5);
    Check(a, std::forward_list<int32_t>{5, 2, 5, 8});

    a.Remove(5);
    REQUIRE(a.Size() == 2u);
    REQUIRE(a.Front() == 2);
    Check(a, std::forward_list<int32_t>{2, 8});
}

TEST_CASE("Output", "[forward_list]") {

    INFO("empty list output") {
        ForwardList a;
        std::stringstream sstream;
        a.Print(sstream);
        REQUIRE(sstream.str().empty());
    }

    INFO("single-element list oputput") {
        ForwardList a{6};
        std::stringstream sstream;
        a.Print(sstream);
        REQUIRE(sstream.str() == "6");
    }

    INFO("many elements list output") {
        ForwardList a{1, 2, 3, 4, 5, 6};
        std::stringstream sstream;
        a.Print(sstream);
        REQUIRE(sstream.str() == "1 2 3 4 5 6");
    }
}
