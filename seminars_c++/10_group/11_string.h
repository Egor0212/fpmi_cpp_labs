#pragma once

#include <initializer_list>
#include <iostream>

class String {
private:
    size_t size_ = 0u;
    char* data_ = nullptr; // m_data
public:
    String() = default;
    String(size_t, char);
    String(const String&);
    String(std::initializer_list<char>);

    String& operator=(const String&);
    char& operator[](size_t);
    const char& operator[](size_t) const;

    size_t Size() const;
    void Swap(String& other);

    ~String();
};


std::ostream& operator<<(std::ostream&, const String&);

