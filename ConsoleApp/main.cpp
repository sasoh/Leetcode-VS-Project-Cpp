//  Your task is to determine the date and time one gigasecond after a certain date.
//  A gigasecond is one thousand million seconds. That is a one with nine zeros after it.
//  If you were born on January 24th, 2015 at 22:00 (10:00 : 00pm), then you would be 
//  a gigasecond old on October 2nd, 2046 at 23 : 46 : 40 (11:46 : 40pm).

#include <boost/date_time/posix_time/posix_time_duration.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/posix_time/time_parsers.hpp>

using namespace boost::posix_time;
using namespace std::string_literals;   

namespace gigasecond {
    static auto advance(ptime from) {
        return from + seconds(1'000'000'000);
    }
}  // namespace gigasecond

int main() {
    const ptime d = time_from_string("2011-04-25 00:00:00");
    
    return 0;
}