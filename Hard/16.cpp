// Joseph F. Engelberger wants to play a new game with N robots (where N is a positive odd integer and N>4). Every robot has a unique integer ID. RIDi refers to the ID of ith robot. For this game, he considers a rectangular field (playground) ABCD with 500 m long and 400 m wide. The coordinate of A, B, C, and D points are (0, 0), (0, 500), (400, 500), and (400, 0) respectively. Joseph places one robot at point A, (N-1)/2 robots at different points on the AD line, and the rest (N-1)/2 robots at different points on the AB line. Si is the source point and Di is the destination point of a robot i. Every robot can move along in a straight line from source to destination. In this game a robot is called winner if it reaches its destination without any collision with other robot. The initial velocity of every robot is 0. At time T the game is started. A robot i starts moving towards its destination point after RIDi mod N second from the starting of the game and its acceleration is (RIDi mod N)+1 cm/s. Write a C++ program to print the ID of all winning robots in ascending order.

// Input instruction: Take the value of N from the user. Along with this, take the ID, coordinate of source and destination points of every robot from the user.

// Input

// 5                                  <-- Value of N

// 12 0 300 400 300                      <-- ID, coordinate of source, coordinate of destination of 1st robot

// 13 0 200 400 200                      <-- ID, coordinate of source, coordinate of destination of 2nd robot

// 11 0 0 400 500            <-- ID, coordinate of source, coordinate of destination of 3rd robot

// 23 200 0 200 500                      <-- ID, coordinate of source, coordinate of destination of 4th robot

// 22 350 0 350 500                      <-- ID, coordinate of source, coordinate of destination of 5th robot

// Output

// 11 12 22

// Test Case 1

// Input

// 5

// 12 0 300 400 300

// 13 0 200 400 200

// 11 0 0 400 500

// 23 200 0 200 500

// 22 350 0 350 500

// Output

// 11 12 22

// steps
// 1. read the number of robots
// 2. read the id, source and destination of every robot
// 3. find the time at which every robot starts moving
// 4. find the acceleration of every robot
// 5. check if robots collide or not in between their source and destination
// 6. find the time at which every robot reaches its destination
// 7. find the winning robots
// 8. print the winning robots
// 9. end

// code
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int id[n];
    int source_x[n];
    int source_y[n];
    int destination_x[n];
    int destination_y[n];
    int start_time[n];
    int acceleration[n];
    int end_time[n];
    for (int i = 0; i < n; i++)
    {
        cin >> id[i] >> source_x[i] >> source_y[i] >> destination_x[i] >> destination_y[i];
        start_time[i] = id[i] % n;
        acceleration[i] = (id[i] % n) + 1;
        end_time[i] = sqrt(pow(destination_x[i] - source_x[i], 2) + pow(destination_y[i] - source_y[i], 2)) / acceleration[i];
    }
    vector<int> winning_robots;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (end_time[i] == end_time[j])
                {
                    count++;
                }
            }
        }
        if (count == 0)
        {
            winning_robots.push_back(id[i]);
        }
    }

    sort(winning_robots.begin(), winning_robots.end());
    for (int i = 0; i < winning_robots.size(); i++)
    {
        cout << winning_robots[i] << " ";
    }
    cout << endl;
    // print the time taken by every robot to reach its destination with its id
    for (int i = 0; i < n; i++)
    {
        cout << id[i] << " " << end_time[i] << endl;
    }

    // pritn the final speed ,  starting time and time taken by every robot to reach its destination with its id in ascending order of id
    for (int i = 0; i < n; i++)
    {
        cout << id[i] << " " << start_time[i] << " " << end_time[i] << " " << acceleration[i] * end_time[i] << endl;
    }

    // check if robots collide or not
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (end_time[i] == end_time[j])
                {
                    cout << "robots " << id[i] << " and " << id[j] << " collide at time " << end_time[i] << endl;
                }
            }
        }
    }

    return 0;
}

// how to check if two robots collide or not
// 1. find the distance between the source and destination of both the robots
// 2. calculate the time required by each robot to reach destination
// 3. if the relative velocity of both the robots is zero then they collide
