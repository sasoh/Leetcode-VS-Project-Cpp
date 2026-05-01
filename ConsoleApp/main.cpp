//  An IPv6 - Address is the next - generation network address for electronic devices.
//  Compared to an IPv4 address, it is made up of 8 blocks that are 4 hexadecimal digits long, split by colons.
//  An example of an IPv6 address is 2001:0000 : 3c4d : 0015 : 0000 : 0000 : 0db8 : 1a2b
//  
//  To avoid needing to write so many digits, you can short an IPv6 address very easily by removing unneeded zeros.
//  The goal of this puzzle is to compress the IPv6 address, that it gets shortened.
//  The shortened version would look like this : 2001 : 0 : 3c4d : 15::db8 : 1a2b
//  
//  You can see that the leading zeros of all the blocks were removed, and a double colon replaced the longest chains 
//  of blocks that contained zeros only.
//  
//  To find out where the double colon needs to be placed, you simply take a look where the longest streak of zero - only blocks is:
//  2001 : 0000 : 3c4d : 0015 : 0000 : 0000 : 0db8 : 1a2b
//       |------|
//  
//  This is a zero - only block, but not the longest - it can be shortened to simply a 0
//  2001:0 : 3c4d : 0015 : 0000 : 0000 : 0db8 : 1a2b
//                       |-------------|
//  
//  When you find the longest streak, as in the example above, simply replace it with a ::
//  If there are two or more streaks, separate from each other, with the same length, replace the first one starting from the left.
//  The number of zero-only blocks does not matter how many colons you need to use - it is always two colons.
//  
//  The last step is to remove the leading zeros of every block.
//  
//  If everything was successful, then you have your shortened IPv6, in this case: 2001 : 0 : 3c4d : 15::db8 : 1a2b
//  Notes : The double colon may only be used once in the whole address at the longest streak of zero blocks, and only if there are 
//  two or more zero blocks next to each other. The rest of the single blocks that contain zeros only must be represented as only one 
//  zero in the whole block, no matter if they are next to each other.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <format>
#include <map>
#include <utility>
#include <algorithm>
#include <ios>
using namespace std;

constexpr static char kSeparator = ':';

static vector<string> tokenize(const string& input) {
    vector<string> tokenized{};
    istringstream ss{ input };
    string t{};
    while (getline(ss, t, kSeparator)) {
        tokenized.push_back(t);
    }
    return tokenized;
}

static map<int, int> findRanges(const map<int, string>& zeroes) {
    int lastIndex{ zeroes.begin()->first };
    bool streak{ false };
    int streakStart{ 0 };
    map<int, int> ranges{};
    for (auto i{ zeroes.cbegin() }; i != zeroes.cend(); ++i) {
        auto index = i->first;
        if (index == lastIndex + 1 && streak == false) {
            streak = true;
            streakStart = lastIndex;
            ranges.insert({ streakStart, 0 });
        }
        if (index != lastIndex + 1) {
            streak = false;
        }
        if (streak) {
            ranges[streakStart] = index;
        }
        lastIndex = i->first;
    }
    return ranges;
}

static int findLongestRange(const map<int, int>& ranges) {
    int longest{ 0 };
    for (const auto& r : ranges) {
        longest = max(longest, r.second - r.first);
    }
    return longest;
}

static string shorten(const string& input) {
    string shortened{};
    auto tokenizedString = tokenize(input);

    // 1. Remove leading 0s from all tokens
    // 2. Store indices of all tokens with 0s
    map<int, string> zeroes{};
    for (size_t i{ 0 }; i < tokenizedString.size(); ++i) {
        auto& t = tokenizedString[i];
        if (t.size() > 0) {
            int intValue = stoi(t, nullptr, 16);
            if (intValue == 0) {
                tokenizedString[i] = "0";
                zeroes.insert({ i, t });
            }
            else {
                ostringstream ss{};
                ss << hex << intValue;
                tokenizedString[i] = ss.str();
            }
        }
    }

    // 3. Find indices of ranges of neighboring tokens with 0s
    auto ranges = findRanges(zeroes);

    // 4. Find the length of the longest range
    auto longest = findLongestRange(ranges);

    // 5. Replace first longest range tokens with a single empty string
    bool firstFound{ false };
    int longestPrunedAt{ 0 };
    for (const auto& r : ranges) {
        bool isLongest{ r.second - r.first == longest };
        bool shouldPrune{ false };
        if (isLongest && !firstFound) {
            firstFound = true;
            shouldPrune = true;
        }

        if (shouldPrune) {
            for (auto i{ r.second }; i > r.first; --i) {
                tokenizedString.erase(tokenizedString.begin() + i);
            }
            tokenizedString[r.first] = ""s;
            longestPrunedAt = r.first;
        }
    }

    for (size_t i{ 0 }; i < tokenizedString.size(); ++i) {
        auto& token = tokenizedString[i];
        if (token.size() == 0) {
            shortened.push_back(kSeparator);
            shortened.push_back(kSeparator);
        }
        else {
            shortened.append(tokenizedString[i]);
            if (i < tokenizedString.size() - 1 && i + 1 != longestPrunedAt) {
                shortened.push_back(kSeparator);
            }
        }
    }

    return shortened;
}

int main()
{
    string ip = "2001:0000:3c4d:0015:0000:b312:0db8:1a2b"s;
    cout << format("in: {}\nsh: {}\n", ip, shorten(ip));
    //ip = "2001:0000:0000:0015:0000:b312:0db8:1a2b"s;
    //cout << format("in: {}\nsh: {}\n", ip, shorten(ip));
    //ip = "2001:0000:0000:0015:0000:0000:0db8:1a2b"s;
    //cout << format("in: {}\nsh: {}\n", ip, shorten(ip));
    //ip = "2001:0000:0000:0015:0000:0000:0000:1a2b"s;
    //cout << format("in: {}\nsh: {}\n", ip, shorten(ip));
    //ip = "2001:0000:0000:0015:0000:0000:1a2b:0000"s;
    //cout << format("in: {}\nsh: {}\n", ip, shorten(ip));
    //ip = "2001:0000:0000:0015:0000:0000:1a2b:0000"s;
    //cout << format("in: {}\nsh: {}\n", ip, shorten(ip));
    //ip = "0000:2001:0000:0015:0000:0000:1a2b:0000"s;
    //cout << format("in: {}\nsh: {}\n", ip, shorten(ip));

    ip = "0000:0000:0000:0000:0000:0000:0000:0001"s; // expected ::1
    cout << format("in: {}\nsh: {}\n", ip, shorten(ip));
    //ip = "0000:0000:0100:0000:0000:0004:aaaa:0000"s; // expected ::100:0:0:4:aaaa:0
    //cout << format("in: {}\nsh: {}\n", ip, shorten(ip));
    ip = "0000:aaaa:a000:0000:000a:0030:0000:0000"s; // expected 0:aaaa:a000:0:a:30::
    cout << format("in: {}\nsh: {}\n", ip, shorten(ip));
}