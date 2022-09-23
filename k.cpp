// Sheldon and Amy are on a date. Sheldon, being the typical geek, asks the Amy to find their friends name based on their qualities.

// Each friend has a name and K qualities (i.e., helpfulness, intelligence, friendliness, and others) which can be rated by an  K-sized tuple (A1, A2, A3, ..., AK). Each quality Ai is an integer between 0 to L inclusive (i.e., a rating of each quality is given between 0 to L inclusive). Sheldon tells Amy about N friends. For each friend, he tells her its name and gives her the K-tuple describing its qualities.

// Then, he plays a quiz with Amy. He gives Amy Q  tuples and ask her which friend they belong to. As Amy is a neurobiologist and does not want to disappoint Sheldon, she tries to answer all the questions correctly. Help her in this task.

// Input:
// The first line contains N, K, L and Q, the number of friends, the size of the K-tuple, the maximum value of any quality and the number of questions that Sheldon asks.
// N lines follow. The next ith line contains a string which is the name of the ith friend and K space separated integer which are the qualities for the ith friend.
// Q lines follow. The next ith line contains K space separated integer denoting a K-tuple.

// Output:
// For each question, output the name of the friend that the K-tuple belongs to.
// It is also possible that Sheldon is asking a trick question and the tuple doesn't describe any friend. In such a case, output "Not my friend :P" (Quotes are for clarity)

// Constraints:
// 1<=N<=100000
// 1<=K<=5
// 1<=L<=15
// 1<=Q<=100000
// 0<=Ai<=L
// 1<=Length of friends name<=10
// Friends name will contain only lowercase alphabets [a-z].

// Note:
// No two friends will have the same K-tuple or name.

// Sample Test case

// 4 3 9 5  // 4 is the number of friends, 3 are their qualities (eg helpfulness, intelligence, caring), 9 is the maximum rating number, 5 is the number of test cases

// leonard 5 1 7

// penny 1 2 3

// howard 9 7 1

// raj 6 9 5

// 9 7 1

// 1 2 3

// 5 1 7

// 1 2 3

// 7 4 5

// Output

// howard

// penny

// leonard

// penny

// Not my friend :P

// Test case 1:

// 5 3 9 5

// baryonyx 5 1 7

// jobaria 1 2 3

// oviraptor 9 7 1

// troodon 6 9 5

// minmi 7 4 5

// 9 7 1

// 1 2 3

// 5 8 8

// 1 2 3

// 7 4 5

// Output

// oviraptor

// jobaria

// Not my friend :P

// jobaria

// minmi

// steps
// 1. read the number of friends, qualities, max rating, number of test cases
// 2. read the name and qualities of each friend
// 3. read the qualities of each test case
// 4. compare the qualities of each test case with the qualities of each friend
// 5. print the name of the friend whose qualities match the qualities of the test case
// 6. if no friend matches the qualities of the test case, print "Not my friend :P"
// 7. repeat steps 3-6 for each test case
// 8. end

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

// function to read the qualities of each friend
void readQualities(vector<int> &qualities, int k)
{
    for (int i = 0; i < k; i++)
    {
        int quality;
        cin >> quality;
        qualities.push_back(quality);
    }
}

// function to create subvector of qualities
vector<int> createSubVector(vector<int> qualities, int start, int end)
{
    vector<int> subVector;
    for (int i = start; i < end; i++)
    {
        subVector.push_back(qualities[i]);
    }
    return subVector;
}

int main()
{
    int n1, k1, l1, q1;
    cin >> n1 >> k1 >> l1 >> q1;

    map<vector<int>, string> mp;

    for (int i1 = 0; i1 < n1; i1++)
    {
        string name;
        cin >> name;
        vector<int> qualities;
        for (int i1 = 0; i1 < k1; i1++)
        {
            int val;
            cin >> val;
            qualities.push_back(val);
        }

        mp[qualities] = name;
    }

    for (int i1 = 0; i1 < q1; i1++)
    {
        vector<int> qualities;
        for (int i1 = 0; i1 < k1; i1++)
        {
            int val;
            cin >> val;
            qualities.push_back(val);
        }

        if (mp.find(qualities) == mp.end())
        {
            cout << "Not my friend :P" << endl;
        }
        else
        {
            cout << mp[qualities] << endl;
        }
    }
}