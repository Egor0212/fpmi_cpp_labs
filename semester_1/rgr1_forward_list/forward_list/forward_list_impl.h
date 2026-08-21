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

public:
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

    // methods for "ranged-based for loop"
    //
    // 1) non-const version
    ForwardListIterator begin() {
        // your code goes here
    }
    ForwardListIterator end() {
        // your code goes here
    }

    // 2) const version
    // TODO: think about return type
    // (is it exactly ForwardListIterator?)
    ForwardListIterator begin() const {
        // your code goes here
    }
    ForwardListIterator end() const {
        // your code goes here
    }

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

private:
    // your code goes here
};