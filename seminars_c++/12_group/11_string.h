#pragma once

#include <cstdint>
#include <cstddef>
#include <iostream>
#include <initializer_list>

class String {
    size_t size_ = 0;
    char* data_ = nullptr;
public:
    String() = default;
    String(size_t, char);
    String(const String&);
    String(std::initializer_list<char>);

    String& operator=(const String&);

    void Swap(String&);

    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    size_t Size() const;

    ~String();

};

std::ostream& operator<<(std::ostream&, const String&);
