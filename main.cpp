/*
 * INSTRUCTION:
 *     This is a Java starting code for hw1_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "Main.java".
 *     But rename it to "main_hw1_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw1_2.cpp
 * Abstract: This program finds the frequencies of integer numbers. where 5
 * vectors and one array are used. After input takes from a user by using for
 * loop to find a number of frequencies and index numbers where that frequency
 * number is located in the original vector. Then the conditional statements
 * check if frequency numbers are sorted by using a built-in function. Then
 * nested for loop stores the frequency of an index number in two variables the
 * inner loop store the frequencies in the new vector and in the last result
 * gets printed it. 
 *ID: 7263 
 *Name: Mohammad Haroon 
 *Date: 02/02/2023
 */

#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v1, v2, v3, v6, v7;

	int num1, num2;

	cin >> num1; // user input

	for (int i = 0; i < num1; i++) {
		cin >> num2;
		v1.push_back(num2); // store the input in vector
	}

	sort(v1.begin(), v1.end()); // sort vector in a ascending order.

	int count = 1; // count variable count the number of frquancy

	for (int i = 0; i < num1; i++) {
		if (v1[i] ==
			v1[i + 1]) { // condation check for duplicates number in vector
			count++;	 // find the duplicates count vairiable increment
		} else if (count == 1) { // if count variable equal one store all
								 // frquancies of one in separate ector
			v2.push_back(v1[i]);
		} else {
			v3.push_back(count); // pushing frquancy to vector
			v6.push_back(
				i); // pushing index number of frquancies element to vector

			count = 1; // decrement count variable back to one
		}
	}

	int arr[v3.size()]; // temp array

	for (int i = 0; i < v3.size(); i++) {
		arr[i] = v3[i]; // copying element of frquancy to array
	}

	if (!is_sorted(arr, arr + v3.size())) { // checking if frqancy numbers are
											// ascending or not
		sort(v3.begin(), v3.end());
		sort(v6.begin(), v6.end(), greater<int>());
	}

	int num3, num4;

	for (int i = 0; i < v6.size(); i++) {
		num3 = v3[i]; // storeing frquancy element in variable
		num4 = v6[i]; // storing index number of frquancy in variable
		for (int i = 0; i < num3; i++) {
			// storing each element according to the frqucny number from orignal
			// vector.
			v7.push_back(v1[num4]);
		}
	}
	v2.insert(
		v2.end(),
		v7.begin(),
		v7.end()); // mergeing frquancy one and other frquancies
	// final result
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i];
		if (i == v2.size() - 1) {
			cout << endl;
		} else {
			cout << " ";
		}
	}

	return (0);
}
