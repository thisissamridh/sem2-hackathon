// On a 2D plane, there are m number of points (where m>6). The coordinate of each point is given. The students need to find 6 such points among these m points, such that, they form a regular hexagon. If multiple hexagons exist on the 2D plane, print the coordinates of the 6 points that build the smallest hexagon (In terms of Area).

// Input instruction: Take the value of m from the user. Then take the coordinate of all m points from the user.

// Input

// 10                           <-- Value of m

// -1 0                         <-- Coordinate of 1st point, here -1 0 means (-1, 0)

// -0.5 0.866              <--Coordinate of 2nd point

// 0.5 0.866               <--Coordinate of 3rd point

// 1 0                          <-- Coordinate of 4th point

// 0.5 -0.866              <-- Coordinate of 5th point

// -0.5 -0.866            <-- Coordinate of 6th point

// 2 3                         <-- Coordinate of 7th point

// 10 9                        <-- Coordinate of 8th point

// 4 7                          <-- Coordinate of 9th point

// -8 0                         <--Coordinate of 10th point

// Output

// -1, 0

// -0.5, 0.866

// 0.5, 0.866

// 1, 0

// 0.5, -0.866

// -0.5, -0.866

// Test Case 1

// Input

// 10

// -1 0

// -0.5 0.866

// 0.5 0.866

// 1 0

// 0.5 -0.866

// -0.5 -0.866

// 2 3

// 10 9

// 4 7

// -8 0

// Output

// -1, 0

// -0.5, 0.866

// 0.5, 0.866

// 1, 0

// 0.5, -0.866

// -0.5, -0.866

// steps
// 1. read the number of points
// 2. read the coordinate of every point
// 3. find the distance between every pair of points
// 4. find the perimeter of every hexagon
// 5. find the area of every hexagon
// 6. find the smallest hexagon
// 7. print the smallest hexagon
// 8. end

// code
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int m;
    cin >> m;
    vector<pair<float, float>> points;
    for (int i = 0; i < m; i++)
    {
        float x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }
    float min_area = 1000000000;
    vector<pair<float, float>> min_hexagon; // to store the points of the smallest hexagon
    for (int i = 0; i < m; i++)             // for every point
    {
        for (int j = i + 1; j < m; j++) // for every other point
        {
            for (int k = j + 1; k < m; k++) // for every other point
            {
                for (int l = k + 1; l < m; l++) // for every other point
                {
                    for (int p = l + 1; p < m; p++) // for every other point
                    {
                        for (int q = p + 1; q < m; q++) // for every other point
                        {
                            // check if the points form a hexagon or not with angle 120 degrees between every pair of sides and sides of equal length
                            float d1 = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
                            float d2 = sqrt(pow(points[j].first - points[k].first, 2) + pow(points[j].second - points[k].second, 2));
                            float d3 = sqrt(pow(points[k].first - points[l].first, 2) + pow(points[k].second - points[l].second, 2));
                            float d4 = sqrt(pow(points[l].first - points[p].first, 2) + pow(points[l].second - points[p].second, 2));
                            float d5 = sqrt(pow(points[p].first - points[q].first, 2) + pow(points[p].second - points[q].second, 2));
                            float d6 = sqrt(pow(points[q].first - points[i].first, 2) + pow(points[q].second - points[i].second, 2));

                            if (d1 == d2 && d2 == d3 && d3 == d4 && d4 == d5 && d5 == d6)
                            {
                                // check if the hexagon is the smallest
                                float perimeter = d1 + d2 + d3 + d4 + d5 + d6;
                                float s = perimeter / 2;
                                // Heron's formula for area of a triangle with sides d1, d2, d3 is sqrt(s(s-d1)(s-d2)(s-d3)) where s = (d1+d2+d3)/2 is the semi-perimeter of the triangle
                                float area = sqrt(s * (s - d1) * (s - d2) * (s - d3) * (s - d4) * (s - d5) * (s - d6));
                                if (area < min_area)
                                {
                                    min_area = area;
                                    min_hexagon.clear();
                                    min_hexagon.push_back(points[i]);
                                    min_hexagon.push_back(points[j]);
                                    min_hexagon.push_back(points[k]);
                                    min_hexagon.push_back(points[l]);
                                    min_hexagon.push_back(points[p]);
                                    min_hexagon.push_back(points[q]);
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 6; i++)
        {
            cout << min_hexagon[i].first << ", " << min_hexagon[i].second << endl; // print the smallest hexagon
        }
        // print total no of possible hexagons
        cout << "Total no of possible hexagons: " << (m * (m - 1) * (m - 2) * (m - 3) * (m - 4) * (m - 5)) / 720 << endl;
        // print distance between every pair of points in the smallest hexagon
        cout << "Distance between 1st and 2nd point: " << sqrt(pow(min_hexagon[0].first - min_hexagon[1].first, 2) + pow(min_hexagon[0].second - min_hexagon[1].second, 2)) << endl;
        cout << "Distance between 2nd and 3rd point: " << sqrt(pow(min_hexagon[1].first - min_hexagon[2].first, 2) + pow(min_hexagon[1].second - min_hexagon[2].second, 2)) << endl;
        cout << "Distance between 3rd and 4th point: " << sqrt(pow(min_hexagon[2].first - min_hexagon[3].first, 2) + pow(min_hexagon[2].second - min_hexagon[3].second, 2)) << endl;
        cout << "Distance between 4th and 5th point: " << sqrt(pow(min_hexagon[3].first - min_hexagon[4].first, 2) + pow(min_hexagon[3].second - min_hexagon[4].second, 2)) << endl;
        cout << "Distance between 5th and 6th point: " << sqrt(pow(min_hexagon[4].first - min_hexagon[5].first, 2) + pow(min_hexagon[4].second - min_hexagon[5].second, 2)) << endl;
        cout << "Distance between 6th and 1st point: " << sqrt(pow(min_hexagon[5].first - min_hexagon[0].first, 2) + pow(min_hexagon[5].second - min_hexagon[0].second, 2)) << endl;
        // length of sides of the hexagon
        cout << "Length of 1st side: " << sqrt(pow(min_hexagon[0].first - min_hexagon[1].first, 2) + pow(min_hexagon[0].second - min_hexagon[1].second, 2)) << endl;
        cout << "Length of 2nd side: " << sqrt(pow(min_hexagon[1].first - min_hexagon[2].first, 2) + pow(min_hexagon[1].second - min_hexagon[2].second, 2)) << endl;
        cout << "Length of 3rd side: " << sqrt(pow(min_hexagon[2].first - min_hexagon[3].first, 2) + pow(min_hexagon[2].second - min_hexagon[3].second, 2)) << endl;
        cout << "Length of 4th side: " << sqrt(pow(min_hexagon[3].first - min_hexagon[4].first, 2) + pow(min_hexagon[3].second - min_hexagon[4].second, 2)) << endl;
        cout << "Length of 5th side: " << sqrt(pow(min_hexagon[4].first - min_hexagon[5].first, 2) + pow(min_hexagon[4].second - min_hexagon[5].second, 2)) << endl;
        cout << "Length of 6th side: " << sqrt(pow(min_hexagon[5].first - min_hexagon[0].first, 2) + pow(min_hexagon[5].second - min_hexagon[0].second, 2)) << endl;

        return 0;
    }
}
