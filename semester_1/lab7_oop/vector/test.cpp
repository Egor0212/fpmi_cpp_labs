#include "catch.hpp"

#include "vector_impl.h"

#include <vector>
#include <sstream>

void Check(const Vector& actual, const std::vector<int>& expected) {
    REQUIRE(actual.Size() == expected.size());
    for (size_t i = 0; i < actual.Size(); ++i) {
        REQUIRE(actual[i] == expected[i]);
    }
}

TEST_CASE("Vector has constructors", "[vector]") {
    {
        INFO("default ctor");
        Vector a;
        REQUIRE(a.Size() == 0u);
    }
    {
        INFO("initializet_list ctor");
        Vector a{1, 2, 3, 4};
        Check(a, std::vector<int>{1, 2, 3, 4});
    }
    {
        INFO("size ctor");
        Vector a(5);
        Check(a, std::vector<int>(5));
    }
}

TEST_CASE("Basic methods", "[vector]") {
    Vector a{1, 3, 5};
    REQUIRE(a.Capacity() == 3u);
    Check(a, std::vector<int>{1, 3, 5});

    a.PopBack();
    Check(a, std::vector<int>{1, 3});
    a.Clear();
    REQUIRE(a.Capacity() == 3u);
    Check(a, std::vector<int>());

    a.PushBack(6);
    Check(a, std::vector<int>{6});

    Vector b{3, 4};
    a.Swap(b);
    Check(a, std::vector<int>{3, 4});
    Check(b, std::vector<int>{6});
}

TEST_CASE("Access with []", "[vector]") {
    const Vector a{1, 2, 3};
    REQUIRE(a[0] == 1);
    REQUIRE(a.operator[](1) == 2);
    REQUIRE(a[2] == 3);
    Check(a, std::vector<int>{1, 2, 3});
}

TEST_CASE("Modifications with []", "[vector]") {
    Vector a{3, 7, 8};
    a[0] = 1;
    a.operator[](1) = 2;
    a[2] = 3;
    Check(a, std::vector<int>{1, 2, 3});
}

TEST_CASE("At method", "[vector]") {
    Vector a{1, 2, 5};
    REQUIRE(a.At(1) == 2);
    REQUIRE_THROWS_AS(a.At(3), std::out_of_range);
    REQUIRE_THROWS_AS(a.At(10), std::out_of_range);
    a.At(2) = 3;
    Check(a, std::vector<int>{1, 2, 3});

    const Vector b{1, 2, 3, 4, 5};
    REQUIRE_THROWS_AS(b.At(10), std::out_of_range);
    REQUIRE(b.At(0) == 1);
    REQUIRE(b.At(1) == 2);
    REQUIRE(b.At(2) == 3);
    REQUIRE(b.At(3) == 4);
    Check(b, std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("Reallocations", "[vector]") {
    const int steps = 16;
    Vector actual;
    for (int step = 0; step <= steps; ++step) {
        std::vector<int> expected;
        for (int i = 0; i <= (1 << step); ++i) {
            actual.PushBack(i);
            expected.push_back(i);
        }
        Check(actual, expected);
        REQUIRE(actual.Capacity() == (1u << (step + 1)));
        actual.Clear();
    }
}

TEST_CASE("Reserve", "[vector]") {
    Vector a;
    a.Reserve(5);
    REQUIRE(a.Size() == 0u);
    REQUIRE(a.Capacity() == 5u);

    for (int i = 0; i < 5; ++i) {
        a.PushBack(i);
    }

    REQUIRE(a.Capacity() == 5u);
    a.PushBack(4);
    REQUIRE(a.Capacity() == 10u);
    a.Reserve(3);
    REQUIRE(a.Capacity() == 10u);
    a.Clear();
    REQUIRE(a.Size() == 0u);
    REQUIRE(a.Capacity() == 10u);
}

TEST_CASE("Copy correctness", "[vector]") {
    Vector a;
    Vector b(a);
    b.PushBack(1);
    Check(a, std::vector<int>());
    Check(b, std::vector<int>{1});

    b = b;
    Check(b, std::vector<int>{1});
    a = b;
    Check(a, std::vector<int>{1});

    b = a;
    Check(b, std::vector<int>{1});
    Vector c(b);
    Check(c, std::vector<int>{1});

    Vector d{3, 4, 5};
    Vector e(d);
    Check(e, std::vector<int>{3, 4, 5});
    d.Swap(c);
    Check(e, std::vector<int>{3, 4, 5});
    Check(d, std::vector<int>{1});
    Check(c, std::vector<int>{3, 4, 5});
}

TEST_CASE("Output", "[vector]") {
    {
        INFO("Emty vector output");
        Vector v;
        std::stringstream ss;
        ss << v;
        REQUIRE(ss.str() == "[]");
    }

    {
        INFO("Vector output");
        Vector v{1, 2, 3, 4, 5, 6};
        std::stringstream ss;
        ss << v;
        REQUIRE(ss.str() == "[1, 2, 3, 4, 5, 6]");
    }
}
