//  Recite the lyrics to that beloved classic, that field - trip favorite : 99 Bottles of Beer on the Wall.
//  Note that not all verses are identical.
//  3 bottles of beer on the wall, 3 bottles of beer.
//  Take one down and pass it around, 2 bottles of beer on the wall.
//  2 bottles of beer on the wall, 2 bottles of beer.
//  Take one down and pass it around, 1 bottle of beer on the wall.
//  1 bottle of beer on the wall, 1 bottle of beer.
//  Take it down and pass it around, no more bottles of beer on the wall.
//  No more bottles of beer on the wall, no more bottles of beer.
//  Go to the store and buy some more, 99 bottles of beer on the wall.

#include <iostream>
#include <format>
#include <string>
#include <sstream>
using std::format;
using std::cout;
using std::endl;
using namespace std::string_literals;

namespace beer_song {
    std::string verse(int bottles) {
        if (bottles == 0) {
            return "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n"s;
        }
        if (bottles == 1) {
            return "1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n"s;
        }
        std::stringstream v{};
        v << bottles << " bottles of beer on the wall, " << bottles << " bottles of beer.\n";
        v << "Take one down and pass it around, " << bottles - 1;
        if (bottles == 2) {
            v << " bottle of beer on the wall.\n";
        }
        else {
            v << " bottles of beer on the wall.\n";
        }
        return v.str();
    }
    std::string sing(int from, int to = 0) {
        std::stringstream s{};

        for (int i{ from }; i >= to; --i) {
            s << verse(i);
            if (from - to > 1 && i > to) {
                s << "\n";
            }
        }

        return s.str();
    }
}  // namespace beer_song

int main() {
    //cout << beer_song::verse(1) << endl;
    cout << beer_song::sing(8, 6) << endl;
    return 0;
}