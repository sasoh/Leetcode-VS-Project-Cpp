#pragma once
#include <vector>
#include <string>

class IntegerSet
{
public:
    IntegerSet();
    IntegerSet(std::vector<int> values);
    IntegerSet unionOfSets(const IntegerSet& rhs);
    IntegerSet intersectionOfSets(const IntegerSet& rhs);
    void insertElement(int k);
    bool isEqualTo(const IntegerSet& rhs) const;
    std::string toString() const;
    friend IntegerSet operator+(const IntegerSet& some, const IntegerSet& other);
    friend IntegerSet operator-(const IntegerSet& some, const IntegerSet& other);
private:
    std::vector<bool> m_ints;
};