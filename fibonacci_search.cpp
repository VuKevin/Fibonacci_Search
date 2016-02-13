// Programmer Name: Kevin Vu
// Purpose: Implementing a Fibonacci Search
// Time complexity Information: Each comparison reduces the target array size in half
// using addition and subtraction (arguably less expensive than binary searchs' division computation),
// it has O(log(n)) time complexity

#include <iostream>
#include <cmath>
using namespace std;

template<class T> 
int fibonacci_search(T array[], int size, T value); // Assigned Fxn.
int fibo(int i); // Get the ith index of a Fibo Sequence

int main()
{
	int arr[20] = {2,4,8,9,17,36,44,55,81,84,94,116,221,256,302,356,396,401,434,536};
				//0	1  2 3 4   5 6   7  8  9  10  11  12  13 14  15  16  17  18  19
	int answer = fibonacci_search(arr, 20, 36);
		cout << answer << endl;
	int arr2[20] = { 10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105 };
	int answer2 = fibonacci_search(arr2, 20, 100);
	cout << answer2 << endl;
	// Fibonacci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89,
	// 144, 233, 377, 610, 987, 1597, 2584, 4181,
	// 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811

}


// The Fibonacci search technique is a method of searching a sorted array using a divide and conquer
// algorithm that narrows down possible locations with the aid of Fibonacci numbers.
// Assume: List is already sorted, a returned value of -1 means that the item was not found
template<class T> 
int fibonacci_search(T array[], int size, T value)
{
	// Obtain the largest Fibonacci number Fk closest to size + 1
	int i = 0;
	while (fibo(i) < size + 1)
		i++;
	// Compare which fibo is closer to the value
	if (abs((size + 1) - fibo(i)) > abs((size + 1) - (fibo(i - 1)))) 
		i--;
	int p = fibo(i - 1); // F3
	int q = fibo(i - 2); // F2
	int r = fibo(i - 3); // F1
	bool found = false; // Set up your flag
	int m = ((size + 1) - (p + q));

	if (value > array[p]) // if the value is greater than ARR[P]
		p = p + m;
	while (p != 0 && (!found))
	{
		if (value == array[p])
		{
			cerr << "Found!" << endl;
			found = true;
		}
		if (value < array[p])
		{
			if (r == 0) 
				p = 0; // exit
			else // shift the fibonacci to the left
			{
				p = p - r; 
				int temp = q; 
				q = r; 
				r = temp - r; 
			}
		}
		if (value > array[p])
		{
			if (q == 1) 
				p = 0; // exit
			else // shift the fibonacci to the right
			{
				p = p + r;
				q = q - r;
				r = r - q;
			}
		}
	}
	if (found == false)
	{
		cerr << "Value not found. " << endl;
		p = -1;
	}
	return p;
}


int fibo(int i)
{
	const double phi = (1 + sqrt(5)) / 2;
	int fiboAtI = (int)(round((pow(phi, i) - pow(1 - phi, i)) / sqrt(5)));
	return fiboAtI;
}
