// A divide and conquer program in C++ to find the smallest distance from a 
// given set of points. 

#include <iostream>
#include <fstream>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std; 

// A structure to represent a Point in 2D plane 
struct Point 
{ 
	int x, y; 
}; 


/* Following two functions are needed for library function qsort().
Refer: http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */

// Needed to sort array of points according to X coordinate
int compareX(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}
// Needed to sort array of points according to Y coordinate
int compareY(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->y - p2->y);
}

// A utility function to find the distance between two points
float dist(Point p1, Point p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
				(p1.y - p2.y)*(p1.y - p2.y)
			);
}

// A Brute Force method to return the smallest distance between two points
// in P[] of size n
float bruteForce(Point P[], int n) 
{ 
	float min = FLT_MAX; 
	for (int i = 0; i < n; ++i) 
		for (int j = i+1; j < n; ++j) 
			if (dist(P[i], P[j]) < min) 
				min = dist(P[i], P[j]); 
	return min; 
} 

// A utility function to find a minimum of two float values 
float min(float x, float y) 
{ 
	return (x < y)? x : y; 
}


// Driver program to test above functions 
int main() 
{
	Point Points[] = {{413165, 457029}, {821007, 445835}, {156742, 948371}, {623935, 893874}, {294488, 192695}, {470478, 666027}, {960284, 627577}, {989387, 121403}, {746348, 307124}, {876235, 890011}};
	//Point ptsFile[] = {};

    ifstream MyReadFile("test.txt");

    if (MyReadFile.is_open()) {
        std::string line;
        int nbPts;

        MyReadFile>>nbPts;
        Point ptsFile[nbPts];

        MyReadFile.ignore(1, '\n');


        for(int i = 0; i < nbPts; i++)
        {
            string line;
            std::getline(MyReadFile, line);

            std::istringstream lineStream(line);

            string px;
            string py;

            std::getline(lineStream, px, ' ');
            std::getline(lineStream, py, ' ');

            int corx = stoi(px);
            int cory = stoi(py);

            Point point {corx, cory};
            ptsFile[i] = point;

            cout << std::to_string(ptsFile[i].x) + " " + std::to_string(ptsFile[i].y) + "\n ";

        }

        MyReadFile.close();
        cout << std::to_string(ptsFile[0].x) << "\n ";
        cout << (bruteForce(ptsFile, nbPts)) << "\n ";
        cout << (bruteForce(Points, 10));
    }

	return 0; 
} 
