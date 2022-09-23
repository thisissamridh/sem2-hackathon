// A teacher asks students to play a game in which students are represented by ‘S’ and are sitting in the form of N rows and M columns. Let u be the maximum weight of the student and v be the smallest weight of the student. If any student’s whose weight is equal to u or v then they disfigure the complete row and column of the matrix. More formally, if any weight is equal to u or v and contains cell number (x, y), that is, S[x][y]=u or S[x][y]=v then, they disfigure all the cells that have row x or column y.

// Your task is to find the number of students left.

// Input format

// The first line contains T denoting the number of test cases.

// The first line of each test case consists of two space-separated integers N and M.

// Next N lines consist of M space-separated integers.

// Output format

// For each test case, print a single integer denoting the left out students.

// Constraints

// 1≤T≤100000

// 1≤N∗M≤1e5

// 1≤S(i,j)≤1e5   ∀i∈[1,N]  ∀j∈[1,M]

// Sum of N×M over all test cases does not exceed 1e6

// Sample Input

// 1

// 3 3

// 8 8 3

// 6 2 4

// 12 1 2

// Sample Output

// 2

// Explanation

// It is clear that max weight of the student is 12 and minimum is 1. Since the cell number of 12 is (3,1) all the cells which have row three and column will be disfigured.

// 8 8 3

// 6 2 4

// 12 1 2

// The minimum weight of the student is 1 so cell number is (3,2) so all the cells which have column number 2 and row number 3 will also be disfigured.

// 8 8 3

// 6 2 4

// 12 1 2

// Only left out weights of the students are 3 and 4 so answer is 2.

// algorithm: steps
// 1. read the number of test cases
// 2. read the number of rows and columns
// 3. read the matrix
// 4. find the minimum and maximum element in the matrix
// 5. find the number of students left

#include <iostream>
using namespace std;

int main()
{
    int t;      // number of test cases
    cin >> t;   // read the number of test cases
    while (t--) // for each test case
    {
        int n, m;                   // number of rows and columns
        cin >> n >> m;              // read the number of rows and columns
        int a[n][m];                // matrix
        for (int i = 0; i < n; i++) // for each row
        {
            for (int j = 0; j < m; j++) // for each column
            {
                cin >> a[i][j]; // read the element
            }
        }

        int min = a[0][0], max = a[0][0]; // minimum and maximum element in the matrix
        for (int i = 0; i < n; i++)       // for each row
        {
            for (int j = 0; j < m; j++) // for each column
            {
                if (a[i][j] < min) // if the element is less than the minimum element
                {
                    min = a[i][j]; // update the minimum element
                }
                if (a[i][j] > max) // if the element is greater than the maximum element
                {
                    max = a[i][j]; // update the maximum element
                }
            }
            // print maximum and minimum element in the matrix
        }

        // // change the min and max element to -1
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         if (a[i][j] == min)
        //         {
        //             a[i][j] = -1;
        //         }
        //         if (a[i][j] == max)
        //         {
        //             a[i][j] = -1;
        //         }
        //     }
        // }

        // copy the array to another array and change the rows and columns of the min and max element to -1
        int b[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                b[i][j] = a[i][j];
            }
        }

        // change the rows and columns of the min and max element to -1 in the copy array
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == min)
                {
                    for (int k = 0; k < m; k++)
                    {
                        b[i][k] = -1;
                    }
                    for (int k = 0; k < n; k++)
                    {
                        b[k][j] = -1;
                    }
                }
                if (a[i][j] == max)
                {
                    for (int k = 0; k < m; k++)
                    {
                        b[i][k] = -1;
                    }
                    for (int k = 0; k < n; k++)
                    {
                        b[k][j] = -1;
                    }
                }
            }
        }

        // find the number of students left
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (b[i][j] != -1)
                {
                    count++;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}
