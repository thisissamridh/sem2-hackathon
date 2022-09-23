// An array of length at least 3 having distinct integers is oddie iff  second highest odd element lies to the left of the highest odd value. For example, [1, 2, 13, 10,  15, 12, 17] is oddie as the second-highest value 15 lies to the left of highest value 17.
// For every oddie array, we define a odd pair (i,j)  i denotes the index of the second-highest odd value (1-indexed) and j denotes the index of the highest odd value (1-indexed). In the above array, the odd pair is (5, 7) [Assumption: Array index starts from 1].
// Given an array, find the total number of distinct pairs over all its subarrays.

// Input:
// The first line contains an integer N denoting the length of the array. The next line contains N distinct integers denoting the elements of the array.

// Output:
// Output a single integer which is the answer to the problem.

// Constraints:
// 1 <= N <= 106
// 1 <= array elements <= 109
// Array elements are distinct.

// Sample Input

// 5

// 1 3 2 4 5

// Sample Output

// 2

// Explanation

// Let us consider all the subarrays of the given array.
// The subarray [1] ,  subarray [2], subarray [3], subarray [4], subarray [5] are not oddie.
// Subarray [1, 3], subarray [3, 2], subarray [2, 4], subarray [4,5] are not oddie.
// The odd pair for subarray [1, 3, 2] is (1,2).
// The subarray [3, 2, 4] is not oddie.

// The odd pair for subarray [1, 3, 2, 4] is (1,2).
// The odd pair for subarray [1, 3, 2, 4,5] is (2, 5).
// So, there are the 2 distinct pairs, which are (1, 2), and (2, 5).

// Test Case 1:

// Input

// 4

// 1 3 2 4

// Output

// 1

// Explanation

// The subarray [1], subarray [2], subarray [3], subarray [4] are not oddie.
// The subarray [1, 3], subarray [3, 2], subarray [2, 4] are not oddie.
// The odd pair for subarray [1, 3, 2, 4] is (1,2).
// So, there is only 1 distinct pair, which is (1, 2).

// code

// steps to find the total no of distinct pairs in a subarray of an array of distinct integers are as follows:
// 1. read the number of elements in the array
// 2. read the array
// 3. find all the subarrays of the array
// 4. declare a function to check oddie for a subarray
// 5. declare a function to find the odd pair for a subarray
// 6. declare a function to find the total number of distinct pairs in a subarray
// 7. declare a function to find the total number of distinct pairs in all the subarrays
// 8. print the total number of distinct pairs in all the subarrays

#include <iostream>
using namespace std;


// function to create subarray of arrays
void subarray(int arr[], int n, int subarr[][100], int &subarr_size)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                subarr[subarr_size][k - i] = arr[k];
            }
            subarr_size++;
        }
    }
}


// function to check oddie  

bool oddie(int subarr[], int subarr_size)
{
    int max = subarr[0];
    int max_index = 0;
    int second_max = subarr[0];
    int second_max_index = 0;
    for (int i = 0; i < subarr_size; i++)
    {
        if (subarr[i] > max)
        {
            max = subarr[i];
            max_index = i;
        }
    }
    for (int i = 0; i < subarr_size; i++)
    {
        if (subarr[i] > second_max && subarr[i] < max)
        {
            second_max = subarr[i];
            second_max_index = i;
        }
    }
    if (second_max_index < max_index)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// function to find odd pair


int main()
{
    // your code goes here
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int oddie = 0;
            int max = 0;
            int max_index = 0;
            int second_max = 0;
            int second_max_index = 0;
            for (int k = i; k <= j; k++)
            {
                if (a[k] % 2 != 0)
                {
                    oddie = 1;
                    if (a[k] > max)
                    {
                        max = a[k];
                        max_index = k;
                    }
                }
            }
            if (oddie == 1)
            {
                for (int k = i; k <= j; k++)
                {
                    if (a[k] % 2 != 0)
                    {
                        if (a[k] > second_max && a[k] < max)
                        {
                            second_max = a[k];
                            second_max_index = k;
                        }
                    }
                }
                if (second_max_index < max_index)
                {
                    count++;
                }
            }
        }
    }
    cout << count;
    return 0;
}
