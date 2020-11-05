#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "time.h"
#include "movie.h"
#include "timeslot.h"
#include "funcs.h"

Time a;
TimeSlot one;
TimeSlot two;
Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};
Movie movie3 = {"Your Name", ROMANCE, 112};
Movie movie4 = {"My Neighbor Totoro", DRAMA, 88};
Movie movie5 = {"Howl's Moving Castle", ACTION, 119};

//Task A
TEST_CASE ("Task A: Regular Cases"){
  CHECK(minutesSinceMidnight({10,15}) == 615);
  CHECK(minutesSinceMidnight({9,14}) == 554);
  CHECK(minutesSinceMidnight({18,38}) == 1118);
  CHECK(minutesUntil({20,55}, {23,45}) == 170);
  CHECK(minutesUntil({2,11},{11,2}) == 531);
  CHECK(minutesUntil({4,44}, {5,55}) == 71);
}
TEST_CASE ("Task A: Over"){
  CHECK(minutesSinceMidnight({30,34}) == 394);
  CHECK(minutesSinceMidnight({1455,23242}) == 922);
  CHECK(minutesSinceMidnight({10,498523}) == 643);
  CHECK(minutesUntil({112,0}, {112,233}) == 233);
  CHECK(minutesUntil({5434,457},{5444,888}) == 1031);
  CHECK(minutesUntil({1,535}, {72,4}) == 3729);
}
TEST_CASE ("Task A: Zero"){
  CHECK(minutesSinceMidnight({0,0}) == 0);
  CHECK(minutesUntil({0,0},{0,0}) == 0);
}
TEST_CASE ("Task A: Negative"){
  CHECK(minutesUntil({23,45},{20,55}) == -170);
  CHECK(minutesUntil({72,4},{1,535}) == -3729);
  CHECK(minutesUntil({112,233},{112,0}) == -233);
}

//Task B
TEST_CASE ("Task B: Regular Cases"){
  a = addMinutes({22,22},2222);
  CHECK(a.h == 11);
  CHECK(a.m == 24);
  a = addMinutes({2,11},234);
  CHECK(a.h == 6);
  CHECK(a.m == 5);
  a = addMinutes({3,33},78);
  CHECK(a.h == 4);
  CHECK(a.m == 51);
}
TEST_CASE ("Task B: Negative"){
  a = addMinutes({1,11},-8);
  CHECK(a.h == 1);
  CHECK(a.m == 3);
  a = addMinutes({17,34},-391);
  CHECK(a.h == 11);
  CHECK(a.m == 3);
  a = addMinutes({20,48},-239);
  CHECK(a.h == 16);
  CHECK(a.m == 49);
}
TEST_CASE("Task B: Zero"){
  a = addMinutes({22,22},0);
  CHECK(a.h == 22);
  CHECK(a.m == 22);
}

//Task C
TEST_CASE ("Task C"){
  CHECK(getTimeSlot({movie3, {6,0}}) == "Your Name ROMANCE (112 min) [starts at 6:00, ends by 7:52]\n");
  CHECK(getTimeSlot({movie1, {9,15}}) == "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]\n");
  CHECK(getTimeSlot({movie2, {12,15}}) == "Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]\n");
  CHECK(getTimeSlot({movie4, {16,45}}) == "My Neighbor Totoro DRAMA (88 min) [starts at 16:45, ends by 18:13]\n");
  CHECK(getTimeSlot({movie5,{20,0}}) == "Howl's Moving Castle ACTION (119 min) [starts at 20:00, ends by 21:59]\n");
}

//Task D
TEST_CASE ("Task D"){
  one = scheduleAfter({movie3, {13,30}}, movie4);
  CHECK(getTimeSlot(one) == "My Neighbor Totoro DRAMA (88 min) [starts at 15:22, ends by 16:50]\n");
  one = scheduleAfter({movie4, {7,40}}, movie5);
  CHECK(getTimeSlot(one) == "Howl's Moving Castle ACTION (119 min) [starts at 9:08, ends by 11:07]\n");
  one = scheduleAfter({movie5, {18,20}}, movie1);
  CHECK(getTimeSlot(one) == "Back to the Future COMEDY (116 min) [starts at 20:19, ends by 22:15]\n");
}

//Task E
TEST_CASE ("Task E"){
  two = {movie2, {20,0}};
  CHECK(timeOverlap(one, two) == true);
  two = {movie3, {23,45}};
  CHECK(timeOverlap(two, one) == false);
  two = {movie4, {4,50}};
  CHECK(timeOverlap(one, two) == false);
  two = {movie1, {22,15}};
  CHECK(timeOverlap(two, one) == false);
  two = {movie5, {22,14}};
  CHECK(timeOverlap(one, two) == true);
}

