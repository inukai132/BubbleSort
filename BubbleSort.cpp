// BubbleSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bubble(vector<int> numbers)
{
	int size = numbers.size();
	int* dataP = numbers.data();
	int* currentPtr = dataP;
	bool sorted = false;
	cout << endl;
	int loops = 0;
	while(!sorted)
	{
		cout << "\rLoop: " << loops++;
		sorted = true;
		int* tempPtr = currentPtr;
		for (int* nextPtr = currentPtr + 1; nextPtr < dataP + size; nextPtr++)
		{
			int current = *currentPtr;
			int next = *nextPtr;
			if (current > next)
			{
				*nextPtr = current;
				*currentPtr = next;
				sorted = false;
			}
			currentPtr = nextPtr;
		}
		currentPtr = tempPtr;
	}
	return numbers;
}

vector<int> doSort(int length, int iterations)
{
	srand(time(NULL));

	vector<int> numbers(length, 0);
	vector<int> numbersSorted(length, 0);
	vector<int> times(iterations, 0);

	cout << endl << endl << endl;

	for (int i = 0; i < iterations; i++)
	{
		cout << "Sort iteration " << i;
		for (int i = 0; i < length; i++)
		{
			int t = rand() % INT16_MAX;
			numbers[i] = t;
		}

		int startTime = clock();

		numbersSorted = bubble(numbers);

		int endTime = clock();

		for (int j = 1; j < length; j++)
		{
			if (numbersSorted[j] < numbersSorted[j - 1])
				return vector<int>(1, -1);
		}

		times[i] = endTime - startTime;
	}

	return times;
}

double average(vector<int> v)
{
	int sum = 0;
	for each (int element in v)
	{
		sum += element;
	}
	return sum / v.size();
}

int main()
{
	int len, iter;
	cout << "How big will the array be? ";
	cin >> len;
	cout << "How many iterations do you want? ";
	cin >> iter;

	vector<int> times = doSort(len, iter);

	if (times[0] == -1)
		cout << "The list was not sorted";
	else
	{
		cout << endl << endl << "Longest clock time was " << *max_element(begin(times), end(times));
		cout << endl << endl << "Smallest clock time was " << *min_element(begin(times), end(times));
		cout << endl << endl << "Average clock time was " << average(times);
	}

	cin >> iter;

	return 0;
}
