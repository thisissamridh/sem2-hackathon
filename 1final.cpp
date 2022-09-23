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
        }

        int b[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                b[i][j] = a[i][j];
            }
        }

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