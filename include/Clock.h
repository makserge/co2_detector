#include <time.h>

#define NTP_SERVER "pool.ntp.org"

time_t now;
tm tm;

void initClock() {
  configTime(0, 0, NTP_SERVER); // 0, 0 because we will use TZ in the next line
  setenv("TZ", TIMEZONE, 1); // Set environment variable with your time zone
  tzset();
}

void showClock() {
  time(&now);
  localtime_r(&now, &tm);
  char buf[20];
  sprintf(buf, "%02d:%02d %02d/%02d/%d", tm.tm_hour, tm.tm_min, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
  showTime(buf);
}