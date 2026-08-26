#pragma once

#include <cstdint>
#include <iostream>
#include <iterator>

class ForwardList {

private:
    struct Node {
        int32_t value_;
        Node* next_;

        explicit Node(int value) : value_(value), next_(nullptr) {
        }
    };

    class ForwardListIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int32_t;
        using pointer = value_type*;
        using reference = value_type&;

        explicit ForwardListIterator(Node* position) : position_(position) {
        }

        ForwardListIterator& operator++() {  // prefix
            if (position_ != nullptr) {
                position_ = position_->next_;
            }
            return *this;
        }

        ForwardListIterator operator++(int) {  // postfix
            ForwardListIterator retval = *this;
            ++(*this);
            return retval;
        }

        bool operator==(const ForwardListIterator& other) const {
            // your code goes here
        }

        bool operator!=(const ForwardListIterator& other) const {
            return !(*this == other);
        }

        reference operator*() const {
            return position_->value_;
        }

        pointer operator->() {
            return &position_->value_;
        }

    private:
        Node* position_;
    };

public:
    // aliases
    // TODO: think about ConstIterator
    // (is it exactly ForwardListIterator?)
    using Iterator = ForwardListIterator;
    using ConstIterator = ForwardListIterator;

    // iterator methods

    // 1) begin, end: non-const version
    Iterator begin();
    Iterator end();

    // 2) begin, end: const version
    ConstIterator begin() const;
    ConstIterator end() const;

    // 3) cbegin, cend
    ConstIterator cbegin() const;
    ConstIterator cend() const;

    // 4) before_begin, cbefore_begin
    // see https://cppreference.com/cpp/container/forward_list/before_begin
    // for more details
    Iterator before_begin();
    ConstIterator before_begin() const;
    ConstIterator cbefore_begin() const;

    // other methods

    // default constructor
    ForwardList();

    // copy constructor
    ForwardList(const ForwardList&);

    // Constructs a ForwardList with `count` copies of elements with value `value`.
    ForwardList(size_t /*count*/, int32_t /*value*/);

    // Constructs a ForwardList with std::initializer_list<int32_t>
    ForwardList(std::initializer_list<int32_t>);

    // operator= overloading
    ForwardList& operator=(const ForwardList&);

    // destructor
    ~ForwardList();

    // insert new element on the top of the list
    void PushFront(int32_t /*value*/);

    // delete first element of the list
    void PopFront();

    // remove every occurrence of an element in the list
    // whose value equals to param `value`,
    // the remaining elements must stay in the same order
    void Remove(int32_t /*value*/);

    // erases all the elements
    void Clear();

    // find list's element by the `value`
    // returns true, if element exists
    // otherwise, returns false
    bool FindByValue(int32_t /*value*/);

    // print list's elements to stream separated by space
    void Print(std::ostream&);

    // get first element of the list
    int32_t Front() const;

    // get size of the list
    size_t Size() const;

    // see
    // https://cppreference.com/cpp/container/forward_list/splice_after
    // for more details
    //
    // overload (1)
    void SpliceAfter(ConstIterator /*pos*/, ForwardList& /*other*/);
    // overload (3)
    void SpliceAfter(ConstIterator /*pos*/, ForwardList& /*other*/, ConstIterator /*it*/);
    // overload (5)
    void SpliceAfter(ConstIterator /*pos*/, ForwardList& /*other*/, ConstIterator /*first*/,
                     ConstIterator /*last*/);

private:
    // your code goes here
};