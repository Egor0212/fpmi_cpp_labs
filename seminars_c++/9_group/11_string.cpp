#include "11_string.h"

#include <algorithm>
#include <ostream>

String::String() {}

String::String(size_t n, char sym)
  : size_(n), data_(size_ > 0 ? new char[size_] : nullptr) {
    //size_ = n;
    //data_ = new char[size_];

    for (size_t i = 0; i < size_; ++i) {
        data_[i] = sym;
    }
}

String::String(const String& other)
  : size_(other.size_), data_(new char[size_]) {

    //for (size_t i = 0; i < other.size_; ++i) {
    //    data_[i] = other.data_[i];
    //}
    std::copy(other.data_, other.data_ + size_, data_);
}


String& String::operator=(const String& other) {
    
    if (this == &other) {
        return *this;
    }
    
    // swap-and-copy
    String copy = other;
    Swap(copy);
    
    //delete[] data_;

    //size_ = other.size_;
    //data_ = new char[size_];
    //std::copy(other.data_, other.data_ + size_, data_);
    
    return *this;
}

char& String::operator[](size_t index) {
    return data_[index];
}

const char& String::operator[](size_t index) const {
    return data_[index];
}


size_t String::Size() const {
    return size_;
}

void String::Swap(String& other) {
    std::swap(size_, other.size_);
    std::swap(data_, other.data_);
}


String::~String() {
    //size_ = 0;
    delete[] data_;
    //data_ = nullptr;
}


std::ostream& operator<<(std::ostream& out, const String& s) {

    for (size_t i = 0; i < s.Size(); ++i) {
        out << s[i];
    }
    return out;
}


