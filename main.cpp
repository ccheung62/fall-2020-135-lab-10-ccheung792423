#include <iostream>
#include <cstdlib>

#include "time.h"
#include "movie.h"
#include "timeslot.h"
#include "funcs.h"

int main (){
  //Task A
  std::cout << "Task A\n";
  Time first = {11,22};
  Time sec = {13,40};
  std::cout << "Time A is " << getTime(first) << std::endl;
  std::cout << "\twhich is " << minutesSinceMidnight(first) << " minutes since midnight" << std::endl;
  std::cout << "Time B is " << getTime(sec) << std::endl;
  std::cout << "\twhich is " << minutesSinceMidnight(sec) << " minutes since midnight" << std::endl;
  std::cout << "The interval between them is " << minutesUntil(first, sec) << ".\n";
  std::cout << "-----------------------------------------------\n";
  
  //Task B
  std::cout << "Task B\n";
  first.h = 8;
  first.m = 10;
  std:: cout << "The time now is "<< getTime(first) << std::endl;
  Time update = addMinutes(first,1500);
  std::cout << "\tAfter 1500 minutes ...\n";
  std::cout << "The time now is " << getTime(update) << std::endl;
  std::cout << "-----------------------------------------------\n";

  //Task C
  std::cout << "Task C\n";
  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};
  Movie movie3 = {"Your Name", ROMANCE, 112};
  Movie movie4 = {"My Neighbor Totoro", DRAMA, 88};
  Movie movie5 = {"Howl's Moving Castle", ACTION, 119};

  TimeSlot dawn = {movie3, {6, 0}};
  TimeSlot morning = {movie1, {9, 15}};  
  TimeSlot daytime = {movie2, {12, 15}}; 
  TimeSlot evening = {movie4, {16, 45}};

  std::cout << "The time slots are:\n";
  std::cout << "Dawn: " << getTimeSlot(dawn);
  std::cout << "Morning: " << getTimeSlot(morning);
  std::cout << "Daytime: " << getTimeSlot(daytime);
  std::cout << "Evening: " <<getTimeSlot(evening);
  std::cout << "-----------------------------------------------\n";

  //Task D
  std::cout << "Task D\n";
  std::cout << "The next movie is schedule immediately after evening's movie\n\t";
  TimeSlot night = scheduleAfter(evening, movie5);
  std::cout << "Night: " << getTimeSlot(night);
  std::cout << "-----------------------------------------------\n";

  //Task E
  std::cout << "Task E\n";
  TimeSlot no = {movie2, {19,30}};
  std::cout << "For this movie\n\t" << getTimeSlot(no);
  if (timeOverlap(no, night)){
    std::cout << "It overlapped with the movie schedule at night\n";
  }
  else {
    std::cout << "It did not overlapp with the movie schedule at night\n";
  }

  
  return 0;
}
