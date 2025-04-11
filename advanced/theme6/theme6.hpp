#include<iostream>
using namespace std;
class TimeSpan;
class DateTime;


int convertToMinutes(int days, int hours, int minutes) {return minutes + hours * 60 + days * 24 * 60;}
bool isLeapYear(int year) {
  if(year%400==0) return true;
  else if(year%100==0) return false;
  else if(year%4==0) return true;
  return false;
}
int convertToDays(int year, int month, int day) {
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int totalDays = 0;
  for(int i=1; i<year; i++) {
    if(isLeapYear(i)) totalDays += 366;
    else totalDays += 365;
  }
  for(int i=1; i<month; i++) {
    if(i==2 && isLeapYear(year)) totalDays += 29;
    else totalDays += daysInMonth[i-1];
  }
  totalDays += day;
  return totalDays;
}
void convertDaysToDate(int totalDays, int &year, int &month, int &day) {
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  year = 1;
  while(true) {
    int daysInYear = isLeapYear(year) ? 366 : 365;
    if (totalDays > daysInYear) {
      totalDays -= daysInYear;
      year++;
    }
    else break;
  }
  month = 1;
  while(true) {
    int daysInCurrentMonth = daysInMonth[month - 1];
    if(month==2 && isLeapYear(year)) daysInCurrentMonth = 29;
    if(totalDays > daysInCurrentMonth) {
      totalDays -= daysInCurrentMonth;
      month++;
    }
    else break;
  }
  day = totalDays;
}


class TimeSpan {
private:
  unsigned int days, hours, minutes;
  bool isPositive;
public:
  TimeSpan(unsigned int days, unsigned int hours, unsigned int minutes) {
    int totalMinutes = convertToMinutes(days, hours, minutes);
    if(totalMinutes>=0) isPositive = true;
    else {
      isPositive = false;
      totalMinutes = 0 - totalMinutes;
    }
    days = totalMinutes / (24 * 60);
    hours = (totalMinutes % (24 * 60)) / 60;
    minutes = totalMinutes % 60;
    this->days = days;
    this->hours = hours;
    this->minutes = minutes;
  }
  TimeSpan calculationPM(const TimeSpan &other, bool isAddition) {
    if(isAddition) {
      if(other.isPositive) return TimeSpan(days+other.days, hours+other.hours, minutes+other.minutes);
      else return TimeSpan(days-other.days, hours-other.hours, minutes-other.minutes);
    }
    else {
      if(other.isPositive) return TimeSpan(days-other.days, hours-other.hours, minutes-other.minutes);
      else return TimeSpan(days+other.days, hours+other.hours, minutes+other.minutes);
    }
  }
  TimeSpan operator+(const TimeSpan &other) {return calculationPM(other, true);}
  TimeSpan operator-(const TimeSpan &other) {return calculationPM(other, false);}
  friend DateTime calculationPM(DateTime &dateTime, TimeSpan &timeSpan, bool isAddition);
  void viewDetails() {
    if(isPositive) cout << "[positive] ";
    else cout << "[negative] ";
    cout << days << " days, " << hours << " hours, " << minutes << " minutes\n";
  }
};
TimeSpan operator"" _d(unsigned long long days) {return TimeSpan(days, 0, 0);}
TimeSpan operator"" _h(unsigned long long hours) {return TimeSpan(0, hours, 0);}
TimeSpan operator"" _m(unsigned long long minutes) {return TimeSpan(0, 0, minutes);}


class DateTime {
private:
  unsigned int year, month, day, hour, minute;
  double timePoint;
public:
  DateTime(unsigned int _year, unsigned int _month, unsigned int _day, unsigned int _hour, unsigned int _minute) : year(_year), month(_month), day(_day), hour(_hour), minute(_minute) {
    timePoint = convertToDays(year, month, day);
    timePoint += (hour / 24) + (minute / 1440);
  }
  bool operator==(const DateTime& other) const {return timePoint==other.timePoint;}
  bool operator!=(const DateTime& other) const {return timePoint!=other.timePoint;}
  bool operator<(const DateTime& other) const {return timePoint<other.timePoint;}
  bool operator<=(const DateTime& other) const {return timePoint<=other.timePoint;}
  bool operator>(const DateTime& other) const {return timePoint>other.timePoint;}
  bool operator>=(const DateTime& other) const {return timePoint>=other.timePoint;}
  TimeSpan operator-(const DateTime& other) const {
    int leftDays = convertToDays(this->year, this->month, this->day), rightDays = convertToDays(other.year, other.month, other.day);
    return TimeSpan(leftDays-rightDays, this->hour-other.hour, this->minute-other.minute);
  }
  friend DateTime calculationPM(DateTime &dateTime, TimeSpan &timeSpan, bool isAddition);
  void viewDetails() {cout << "[datetime] " << "year: " << year << ", month: " << month << ", day: " << day << ", hour: " << hour << ", minute: " << minute << endl;}
};


DateTime calculationPM(DateTime &dateTime, TimeSpan &timeSpan, bool isAddition) {
  int year, month, day;
  TimeSpan t(convertToDays(dateTime.year, dateTime.month, dateTime.day), dateTime.hour, dateTime.minute);
  if(isAddition) t = t + timeSpan;
  else t = t - timeSpan;
  if(!t.isPositive) {
    cerr << "❌ error: default values";
    return DateTime(1,1,1,0,0);
  }
  convertDaysToDate(t.days, year, month, day);
  return DateTime(year, month, day, t.hours, t.minutes);
}
DateTime operator+(DateTime &dateTime, TimeSpan &timeSpan) {return calculationPM(dateTime, timeSpan, true);}
DateTime operator-(DateTime &dateTime, TimeSpan &timeSpan) {return calculationPM(dateTime, timeSpan, false);}


void operation1() {
  cout << "\n💻 time span class + addition/subtraction + user defined literals\n";
  TimeSpan timeSpan = 10_d + 4_h - 10_m;
  timeSpan.viewDetails();
}
void operation2() {
  cout << "\n💻 comparison of a date time class\n";
  DateTime dateTime1(2024, 8, 13, 11, 20), dateTime2(2025, 4, 11, 12, 40);
  // DateTime dateTime1(2024, 8, 13, 11, 20), dateTime2(2024, 8, 13, 11, 20);
  dateTime1.viewDetails();
  dateTime2.viewDetails();
  if(dateTime1 > dateTime2) cout << "[compare] left > right\n";
  else if(dateTime1 == dateTime2) cout << "[compare] equal\n";
  else cout << "[compare] left < right\n";
}
void operation3() {
  cout << "\n💻 adding/subtracting a time span object to/from a date time object\n";
  DateTime dateTime(2024, 8, 13, 11, 20);
  TimeSpan timeSpan(41, 5, 40);
  (dateTime-timeSpan).viewDetails();
}
void operation4() {
  cout << "\n💻 subtracting two date time objects that results in a time span object\n";
  DateTime dateTime1(2024, 8, 13, 11, 20), dateTime2(2020, 4, 11, 12, 40);
  (dateTime1-dateTime2).viewDetails();
}

