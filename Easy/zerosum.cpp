

#include <iostream>
using namespace std;

int main()
{
    int num;               // array size
    cin >> num;            // read the array size
    int m = 1;             // number of subsets
    int zerosumarray[num]; // array to store the elements of the array

    // read the elements of the array
    for (int i = 0; i < num; i++)
    {
        cin >> zerosumarray[i];
    }
    // check the number of subsets
    for (int i = 0; i < num; i++)
    {
        m = m * zerosumarray[i];
    }
    // check if the sum is zero
    if (m < 0)
    {
        cout << "True";
    }
    // if the sum is not zero
    else
    {
        cout << "False";
    }
    return 0;
}
