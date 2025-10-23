#ifndef THREE_H
#define THREE_H

#include <iostream>

class Three
{
private:
    size_t _size;
    unsigned char* _number_str;

    void _removeLeadingZeroes();

public:
    Three();
    Three(size_t array_size, unsigned char value = '0');
    explicit Three(const std::initializer_list<unsigned char>& list);
    Three(const std::string& str_value);
    Three(const Three& other);
    Three(Three&& other) noexcept;

    virtual ~Three() noexcept;

    size_t getSize() const;

    Three add(const Three& other) const;
    Three subtract(const Three& other) const;
    Three copy() const;

    bool isEqualTo(const Three& other) const;
    bool isLessThan(const Three& other) const;
    bool isGreaterThan(const Three& other) const;

    void print() const;
    std::string toString() const;
private:
    void setSize(size_t size);
    void setNumberStr(unsigned char* number_str);
};

#endif