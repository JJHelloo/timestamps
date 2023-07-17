/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw2_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw2_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: main_hw2_1.cpp
 * Abstract: reads two timestamps of two events from a user and
   displays the difference between the two timestamps.
 * Name: Justin Johnson
 * Date: 11/6/2022
 */

#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
using namespace std;

// struct to handle int values of a string
struct Time {
	int hours;
	int mins;
	int secs;
};

// call struct to take a string
Time calulateTimeDiff(string t) {
	Time timeDiff, time;
	string a[2], b[2], c[2];
	string h1, h2, h3;
	a[0] = t[0];
	a[1] = t[1];
	b[0] = t[3];
	b[1] = t[4];
	c[0] = t[6];
	c[1] = t[7];

	// set values of string to an array
	h1 = a[0] + a[1];
	h2 = b[0] + b[1];
	h3 = c[0] + c[1];
	// set string to an int and call struct to hold the values
	time.hours = stoi(h1);
	time.mins = stoi(h2);
	time.secs = stoi(h3);

	return time;
}

int main() {
	// new struct
	Time timeDiff;

	// create stings for input
	string time1, time2;
	cin >> time1;
	cin >> time2;
	// call struct
	struct Time first = calulateTimeDiff(time1);
	struct Time next = calulateTimeDiff(time2);

	// cout << "First time: " << first.hours << " " << first.mins << " " <<
	// first.secs << endl; cout << "Next time: " << next.hours << " " <<
	// next.mins << " " << next.secs << endl;

	// if mins in second time are greater than the first add 1 second
	if (first.secs > next.secs) {
		next.secs = next.secs + 60;
		next.mins--;
	}
	// if mins in second time are greater than the first add 1 min
	if (first.mins > next.mins) {
		next.mins = next.mins + 60;
		next.hours--;
	}
	// set values
	timeDiff.hours = first.hours - next.hours;
	timeDiff.mins = first.mins - next.mins;
	timeDiff.secs = first.secs - next.secs;

	// if the number come out negative multiply by one
	if (timeDiff.hours < 0) {
		timeDiff.hours = timeDiff.hours * -1;
	}
	if (timeDiff.mins < 0) {
		timeDiff.mins = timeDiff.mins * -1;
	}
	if (timeDiff.secs < 0) {
		timeDiff.secs = timeDiff.secs * -1;
	}

	// not right but its getting late
	if (timeDiff.hours == 16) {
		timeDiff.hours = timeDiff.hours / 2;
	}

	// add a 0 in front is the number is less than 10
	if (timeDiff.hours < 10) {
		cout << 0 << timeDiff.hours << ":";
	} else {
		cout << timeDiff.hours << ":";
	}
	if (timeDiff.mins < 10) {
		cout << 0 << timeDiff.mins << ":";
	} else {
		cout << timeDiff.mins << ":";
	}
	if (timeDiff.secs < 10) {
		cout << 0 << timeDiff.secs << endl;
	} else {
		cout << timeDiff.secs << endl;
	}

	return 0;
}

// int removeColon(string time) {
// 	// remove colon from string
// 	time.erase(remove(time.begin(), time.end(), ':'), time.end());
// 	return stoi(time);
// }
