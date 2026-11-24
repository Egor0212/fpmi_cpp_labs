#include "11_string.h"

#include <algorithm>

// String::String() {}

String::String(size_t n, char sym)
  : size_(n), data_(new char[size_]) {
    // size_ = n;
    // data_ = new char[size_];
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = sym;
    }
}


String::String(const String& other)
  : size_(other.size_), data_(new char[size_]) {

    // for (size_t i = 0; i < size_; ++i) {
    //     data_[i] = other.data_[i];
    // }
    std::copy(other.data_, other.data_ + other.size_, data_);
}


String::String(std::initializer_list<char> list)
  : size_(list.size()), data_(new char[size_]) {
    
    // since c++20
    // for (size_t i = 0; char item : list) {
    //     data_[i] = item;
    //     ++i;
    // }

    std::copy(list.begin(), list.end(), data_);
}


String& String::operator=(const String& other) {
    if (this == &other) {
        return *this;
    }

    // copy-and-swap idiome
    String copy = other;
    Swap(copy);

    // delete[] data_;
    // size_ = other.size_;
    // data_ = new char[size_];
    // std::copy(other.data_, other.data_ + other.size_, data_);

    return *this;
}


void String::Swap(String& other) {
    std::swap(size_, other.size_);
    std::swap(data_, other.data_);
}

size_t String::Size() const {
    return size_;
}

char& String::operator[](size_t index) {
    return data_[index];
}
const char& String::operator[](size_t index) const {
    return data_[index];
}

String::~String() {
    delete[] data_;
    data_ = nullptr;
}


std::ostream& operator<<(std::ostream& out, const String& s) {
    for (size_t i = 0; i < s.Size(); ++i) {
        out << s.operator[](i);
    }
    return out;
}