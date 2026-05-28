#include <iostream>
#include <format>
using std::format;
using std::cout;
using std::endl;

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/gregorian/greg_weekday.hpp>
#include <boost/date_time/date_defs.hpp>

namespace meetup {
    class scheduler {
    public:
        scheduler(boost::gregorian::months_of_year month, int year);
        boost::gregorian::date monteenth() const;
        boost::gregorian::date tuesteenth() const;
        boost::gregorian::date wednesteenth() const;
        boost::gregorian::date thursteenth() const;
        boost::gregorian::date friteenth() const;
        boost::gregorian::date saturteenth() const;
        boost::gregorian::date sunteenth() const;
        boost::gregorian::date first_monday() const;
        boost::gregorian::date first_tuesday() const;
        boost::gregorian::date first_wednesday() const;
        boost::gregorian::date first_thursday() const;
        boost::gregorian::date first_friday() const;
        boost::gregorian::date first_saturday() const;
        boost::gregorian::date first_sunday() const;
        boost::gregorian::date second_monday() const;
        boost::gregorian::date second_tuesday() const;
        boost::gregorian::date second_wednesday() const;
        boost::gregorian::date second_thursday() const;
        boost::gregorian::date second_friday() const;
        boost::gregorian::date second_saturday() const;
        boost::gregorian::date second_sunday() const;
        boost::gregorian::date third_monday() const;
        boost::gregorian::date third_tuesday() const;
        boost::gregorian::date third_wednesday() const;
        boost::gregorian::date third_thursday() const;
        boost::gregorian::date third_friday() const;
        boost::gregorian::date third_saturday() const;
        boost::gregorian::date third_sunday() const;
        boost::gregorian::date fourth_monday() const;
        boost::gregorian::date fourth_tuesday() const;
        boost::gregorian::date fourth_wednesday() const;
        boost::gregorian::date fourth_thursday() const;
        boost::gregorian::date fourth_friday() const;
        boost::gregorian::date fourth_saturday() const;
        boost::gregorian::date fourth_sunday() const;
        boost::gregorian::date last_monday() const;
        boost::gregorian::date last_tuesday() const;
        boost::gregorian::date last_wednesday() const;
        boost::gregorian::date last_thursday() const;
        boost::gregorian::date last_friday() const;
        boost::gregorian::date last_saturday() const;
        boost::gregorian::date last_sunday() const;
    private:
        boost::gregorian::date m_date;
    };

    namespace {
        boost::gregorian::date find_first_teenth_day(boost::gregorian::date from, boost::gregorian::greg_weekday::weekday_enum day)
        {
            for (size_t i{ 12 }; i < 20; ++i) {
                auto newDay = from + boost::gregorian::date_duration(i);
                if (newDay.day_of_week() == day) {
                    return newDay;
                }
            }
            return boost::gregorian::date{};
        }

        boost::gregorian::date find_first_day(boost::gregorian::date from, boost::gregorian::greg_weekday::weekday_enum day, int skipFirst = 0)
        {
            for (size_t i{ 0 }; i < 31; ++i) {
                auto newDay = from + boost::gregorian::date_duration(i);
                if (newDay.day_of_week() == day && (skipFirst-- < 1)) {
                    return newDay;
                }
            }
            return boost::gregorian::date{};
        }

        boost::gregorian::date find_last_teenth_day(boost::gregorian::date from, boost::gregorian::greg_weekday::weekday_enum day)
        {
            boost::gregorian::date r{};
            for (size_t i{ 0 }; i < boost::gregorian::gregorian_calendar::end_of_month_day(from.year(), from.month()); ++i) {
                auto newDay = from + boost::gregorian::date_duration(i);
                if (newDay.day_of_week() == day) {
                    r = newDay;
                }
            }
            return r;
        }
    }

    scheduler::scheduler(boost::gregorian::months_of_year month, int year) : m_date{ boost::gregorian::date(year, month, 1) } {}

    boost::gregorian::date scheduler::monteenth() const
    {
        return find_first_teenth_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Monday);
    }
    boost::gregorian::date scheduler::tuesteenth() const
    {
        return find_first_teenth_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Tuesday);
    }
    boost::gregorian::date scheduler::wednesteenth() const
    {
        return find_first_teenth_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Wednesday);
    }
    boost::gregorian::date scheduler::thursteenth() const
    {
        return find_first_teenth_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Thursday);
    }
    boost::gregorian::date scheduler::friteenth() const
    {
        return find_first_teenth_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Friday);
    }
    boost::gregorian::date scheduler::saturteenth() const
    {
        return find_first_teenth_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Saturday);
    }
    boost::gregorian::date scheduler::sunteenth() const
    {
        return find_first_teenth_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Sunday);
    }
    boost::gregorian::date scheduler::first_monday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Monday);
    }
    boost::gregorian::date scheduler::first_tuesday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Tuesday);
    }
    boost::gregorian::date scheduler::first_wednesday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Wednesday);
    }
    boost::gregorian::date scheduler::first_thursday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Thursday);
    }
    boost::gregorian::date scheduler::first_friday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Friday);
    }
    boost::gregorian::date scheduler::first_saturday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Saturday);
    }
    boost::gregorian::date scheduler::first_sunday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Sunday);
    }
    boost::gregorian::date scheduler::second_monday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Monday, 1);
    }
    boost::gregorian::date scheduler::second_tuesday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Tuesday, 1);
    }
    boost::gregorian::date scheduler::second_wednesday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Wednesday, 1);
    }
    boost::gregorian::date scheduler::second_thursday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Thursday, 1);
    }
    boost::gregorian::date scheduler::second_friday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Friday, 1);
    }
    boost::gregorian::date scheduler::second_saturday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Saturday, 1);
    }
    boost::gregorian::date scheduler::second_sunday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Sunday, 1);
    }
    boost::gregorian::date scheduler::third_monday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Monday, 2);
    }
    boost::gregorian::date scheduler::third_tuesday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Tuesday, 2);
    }
    boost::gregorian::date scheduler::third_wednesday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Wednesday, 2);
    }
    boost::gregorian::date scheduler::third_thursday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Thursday, 2);
    }
    boost::gregorian::date scheduler::third_friday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Friday, 2);
    }
    boost::gregorian::date scheduler::third_saturday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Saturday, 2);
    }
    boost::gregorian::date scheduler::third_sunday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Sunday, 2);
    }
    boost::gregorian::date scheduler::fourth_monday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Monday, 3);
    }
    boost::gregorian::date scheduler::fourth_tuesday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Tuesday, 3);
    }
    boost::gregorian::date scheduler::fourth_wednesday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Wednesday, 3);
    }
    boost::gregorian::date scheduler::fourth_thursday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Thursday, 3);
    }
    boost::gregorian::date scheduler::fourth_friday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Friday, 3);
    }
    boost::gregorian::date scheduler::fourth_saturday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Saturday, 3);
    }
    boost::gregorian::date scheduler::fourth_sunday() const
    {
        return find_first_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Sunday, 3);
    }
    boost::gregorian::date scheduler::last_monday() const
    {
        return find_last_teenth_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Monday);
    }
    boost::gregorian::date scheduler::last_tuesday() const
    {
        return find_last_teenth_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Tuesday);
    }
    boost::gregorian::date scheduler::last_wednesday() const
    {
        return find_last_teenth_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Wednesday);
    }
    boost::gregorian::date scheduler::last_thursday() const
    {
        return find_last_teenth_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Thursday);
    }
    boost::gregorian::date scheduler::last_friday() const
    {
        return find_last_teenth_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Friday);
    }
    boost::gregorian::date scheduler::last_saturday() const
    {
        return find_last_teenth_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Saturday);
    }
    boost::gregorian::date scheduler::last_sunday() const
    {
        return find_last_teenth_day(m_date, boost::gregorian::greg_weekday::weekday_enum::Sunday);
    }
}  // namespace meetup

int main() {
    const meetup::scheduler meetup{ boost::gregorian::May, 2013 };
    const boost::gregorian::date expected{ 2013, boost::gregorian::May, 13 };
    cout << (expected == meetup.monteenth()) << endl;
    return 0;
}