#include <iostream>
#include <cstdio>
using namespace std;

// function to create subarray of arrays
void subarray(int oddpairarray[], int n, int subarr[][100], int &subarr_size)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                subarr[subarr_size][k - i] = oddpairarray[k];
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

int main()
{
    int range;    // length of array
    cin >> range; // read array
    int oddpairarray[range];
    int find = 0, count = 0;
    for (int i = 0; i < range; i++)
    {
        cin >> oddpairarray[i];
    }

    for (int i = range - 1; i >= 0; i--)
    {
        if ((oddpairarray[i] % 2 == 1 || oddpairarray[i] == 1) && oddpairarray[i] < find)
        {
            count++;
            find = oddpairarray[i];
        }
        else if (oddpairarray[i] % 2 == 1)
        {
            find = oddpairarray[i];
        }
    }
    cout << count;
}