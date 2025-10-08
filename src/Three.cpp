#include <string>
#include "Three.h"

void Three::_removeLeadingZeroes()
{
    while (_number_str[_size - 1] == '0' && _size > 1)
    {
        --_size;
    }
}

Three::Three() : _size(0), _number_str(nullptr) {}

Three::Three(size_t array_size, unsigned char value)
{
    if (value < '0' || value > '2')
    {
        throw std::invalid_argument("Digit has to be in 0-2 range");
    }
    if (array_size < 1)
    {
        throw std::invalid_argument("Array size has to be natural number");
    }

    _size = array_size;
    _number_str = new unsigned char[_size];
    for (size_t i = 0; i < _size; ++i)
    {
        _number_str[i] = value;
    }

    _removeLeadingZeroes();
}

Three::Three(const std::initializer_list<unsigned char>& list)
{
    _size = list.size();
    _number_str = new unsigned char[_size];
    auto it = list.begin();
    for (size_t i = 0; i < _size; ++i)
    {
        unsigned char digit = *(it + i);
        if (digit < '0' || digit > '2')
        {
            throw std::invalid_argument("Digit has to be in 0-2 range");
        } 
        _number_str[_size - i - 1] = digit;
    }

    _removeLeadingZeroes();
}

Three::Three(const std::string& str_value)
{
    if (str_value.size() == 0)
    {
        throw std::invalid_argument("String has to be non-empty");
    }

    _size = str_value.size();
    _number_str = new unsigned char[_size];
    for (size_t i = 0; i < _size; ++i)
    {
        unsigned char digit = str_value[i];
        if (digit < '0' || digit > '2')
        {
            throw std::invalid_argument("Digit has to be in 0-2 range");
        }
        _number_str[_size - i - 1] = digit;
    }

    _removeLeadingZeroes();
}

Three::Three(const Three& other)
{
    _size = other._size;
    _number_str = new unsigned char[_size];
    for (size_t i = 0; i < _size; ++i)
    {
        _number_str[i] = other._number_str[i];
    }
}

Three::Three(Three&& other) noexcept
{
    _size = other._size;
    _number_str = other._number_str;

    other._size = 0;
    other._number_str = nullptr;
}

Three::~Three() noexcept
{
    if (_number_str != nullptr)
    {
        delete[] _number_str;
    }
}

Three Three::add(const Three& other) const
{
    size_t max_size = std::max(_size, other._size);

    Three sum_result;
    sum_result.setSize(max_size + 1);
    sum_result.setNumberStr(new unsigned char[sum_result._size]);

    int sum = 0;

    for (size_t i = 0; i < max_size; ++i)
    {
        if (i < _size)
        {
            sum += _number_str[i] - '0';
        }
        if (i < other._size)
        {
            sum += other._number_str[i] -'0';
        }
        sum_result._number_str[i] = sum % 3 + '0';
        sum /= 3;
    }

    sum_result._number_str[max_size] = sum > 0 ? (sum + '0') : '0';
    sum_result._removeLeadingZeroes();

    return sum_result;
}

Three Three::subtract(const Three& other) const
{
    if (isLessThan(other))
    {
        throw std::logic_error("Substraction cannot be less than zero");
    }

    size_t max_size = std::max(_size, other._size);
    Three sub_result;
    sub_result.setSize(max_size);
    sub_result.setNumberStr(new unsigned char[sub_result._size]);

    int sub = 0;
    int odd = 0;

    for (size_t i = 0; i < max_size; ++i)
    {
        sub = _number_str[i] - '0' - odd;
        if (i < other._size)
        {
            sub -= other._number_str[i] - '0';
        }
        if (sub < 0)
        {
            sub += 3;
            odd = 1;
        }
        else
        {
            odd = 0;
        }

        sub_result._number_str[i] = sub + '0';
    }

    sub_result._removeLeadingZeroes();

    return sub_result;
}

Three Three::copy() const
{
    return Three(*this);
}

bool Three::isEqualTo(const Three& other) const
{
    if (_size != other._size)
    {
        return false;
    }

    for (size_t i = 0; i < _size; ++i)
    {
        if (_number_str[i] != other._number_str[i])
        {
            return false;
        }
    }

    return true;
}

bool Three::isLessThan(const Three& other) const
{
    if (_size != other._size)
    {
        return _size < other._size;
    }

    for (size_t i = 0; i < _size; ++i)
    {
        if (_number_str[_size - i - 1] != other._number_str[other._size - i - 1])
        {
            return _number_str[_size - i - 1] < other._number_str[_size - i - 1];
        }
    }

    return false;
}

bool Three::isGreaterThan(const Three& other) const
{
    if (_size != other._size)
    {
        return _size > other._size;
    }

    for (size_t i = 0; i < _size; ++i)
    {
        if (_number_str[_size - i - 1] != other._number_str[other._size - i - 1])
        {
            return _number_str[_size - i - 1] > other._number_str[_size - i - 1];
        }
    }

    return false;
}

std::string Three::toString() const
{
    if (_number_str == nullptr)
    {
        return "";
    }

    std::string res_str;
    for (size_t i = 0; i < _size; ++i)
    {
        res_str += _number_str[_size - i - 1];
    }

    return res_str;
}

void Three::print() const
{   
    std::cout << toString() << std::endl;
}

size_t Three::getSize() const
{
    return _size;
}

void Three::setSize(size_t size)
{
    this->_size = size;
}

void Three::setNumberStr(unsigned char* _number_str)
{
    this->_number_str = _number_str;
}