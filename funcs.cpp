#include <iostream>

#include "time.h"
#include "movie.h"
#include "timeslot.h"
#include "funcs.h"

std::string getTime (Time a){
  std::string result = "";
  if (a.m <= 9){
    return result += std::to_string(a.h) + ":0" +std::to_string(a.m);
  }
  else {
    return result += std::to_string(a.h) + ":" +std::to_string(a.m);
  }
}

//Task A
int minutesSinceMidnight(Time time){
  if (time.h > 24){  //make sure the time is formatted correctly
    time.h = time.h%24;
  }
  if (time.m > 59){
    time.m = time.m%60;
  }
  return time.h*60 + time.m;
}

int minutesUntil(Time earlier, Time later){ 
  int minear = earlier.h*60 + earlier.m; //turn both time into minutes
  int minlat = later.h*60 + later.m;
  return minlat-minear;  //returns difference
}

//Task B
Time addMinutes(Time time0, int min){
  time0.m += min;
  if (time0.m > 59){
    time0.h += time0.m/60;  //add the extra minutes into hours
    time0.h = time0.h%24;   //make sure hour is < 24
    time0.m = time0.m%60;   //make sure min is < 60
  }
  else if (time0.m < 0){
    time0.h += (time0.m/60)-1;  //take away hours to make min (+)
    time0.m = (time0.m%60)+60;  //turn min (+) with the subtracted hour
  }
  if (time0.h >= 24){
    time0.h = time0.h%24;    //make sure hour is 0<=x<24
  }
  else if (time0.h < 0){
    time0.h = (time0.h%24)+24; 
  }
  return time0;
}

//Task C
std::string getMovie (Movie mv){
  std::string g;
  std::string result = ""; //return string based on title, genre, and duration
  switch (mv.genre){
    case ACTION   : g = "ACTION"; break;
    case COMEDY   : g = "COMEDY"; break;
    case DRAMA    : g = "DRAMA";  break;
    case ROMANCE  : g = "ROMANCE"; break;
    case THRILLER : g = "THRILLER"; break; 
  }
  return result += mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
}

std::string getTimeSlot (TimeSlot a){ 
  std::string result = "";
  Time end = addMinutes(a.startTime, a.movie.duration); //calculate end time based on the movie's duration 
  return result += getMovie(a.movie) + " [starts at " + getTime(a.startTime) + ", ends by " + getTime(end) + "]\n";
}

//Task D
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
  Time end = addMinutes(ts.startTime, ts.movie.duration);
  TimeSlot next = {nextMovie, end}; //set the start time as the end time of the last movie
  return next;
}

//Task E
bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
  TimeSlot earlier;
  TimeSlot later;
  if(minutesUntil(ts1.startTime,ts2.startTime) > 0) { //determine which one sstarts earlier
    earlier = ts1;
    later = ts2;
  }
  else {
    later = ts1;
    earlier = ts2;
  }
  Time end1 = addMinutes(earlier.startTime, earlier.movie.duration); //calculate the end time of the earlier movie
  if (minutesUntil(end1,later.startTime) >= 0){ //see if the end time of the earlier time comes before or after the start time of the later movie
    return false;
  }
  else {
    return true;
  }
}
