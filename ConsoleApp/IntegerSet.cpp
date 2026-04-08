#include "IntegerSet.h"
#include <vector>
#include <format>

IntegerSet::IntegerSet()
{
    m_ints.resize(100, false);
}

IntegerSet::IntegerSet(std::vector<int> values)
{
    m_ints.resize(100, false);
    for (const auto& i : values) {
        m_ints.at(i) = true;
    }
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet& rhs)
{
    IntegerSet s{};
    for (auto i{ 0 }; i < m_ints.size(); ++i) {
        s.m_ints[i] = m_ints[i] || rhs.m_ints[i];
    }

    return s;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& rhs)
{
    IntegerSet s{};
    for (auto i{ 0 }; i < m_ints.size(); ++i) {
        s.m_ints[i] = m_ints[i] && rhs.m_ints[i];
    }
    return s;
}

void IntegerSet::insertElement(int k)
{
    m_ints[k] = true;
}

bool IntegerSet::isEqualTo(const IntegerSet& rhs) const
{
    if (m_ints.size() != rhs.m_ints.size()) return false;
    for (auto i{ 0 }; i < m_ints.size(); ++i) {
        if (m_ints[i] != rhs.m_ints[i]) return false;
    }
    return true;
}

std::string IntegerSet::toString() const
{
    std::string r{};
    for (auto i{ 0 }; i < m_ints.size(); ++i) {
        r.append(std::format("{}", (int)m_ints[i]));
    }
    r.append("\n");
    return r;
}

IntegerSet operator+(const IntegerSet& some, const IntegerSet& other)
{
    IntegerSet r{ some };
    return r.unionOfSets(other);
}

IntegerSet operator-(const IntegerSet& some, const IntegerSet& other)
{
    IntegerSet r{ some };
    for (auto i{ 0 }; i < some.m_ints.size(); ++i) {
        if (other.m_ints[i]) {
            r.m_ints[i] = false;
        }
    }
    return r;
}