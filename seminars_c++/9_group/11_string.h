#pragma once

#include <cstddef>
#include <iostream>

class String {
    size_t size_ = 0u;
    char* data_ = nullptr; // m_data

public:
    String();
    String(size_t, char);
    
    // RULE OF THREE
    String(const String&);
    String& operator=(const String&);

    size_t Size() const;
    void Swap(String&);

    char& operator[](size_t); // s[5] = '4';
    const char& operator[](size_t) const;
    
    ~String();
};


std::ostream& operator<<(std::ostream&, const String&);

