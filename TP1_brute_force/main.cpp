#include <iostream>
#include <fstream>
#include <cfloat>
#include <string>
#include <chrono>

using namespace std;

// A structure to represent a Point in 2D plane
struct Point
{
    int x, y;
};

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

int main()
{
    auto start = chrono::steady_clock::now();
    ifstream file;
    //TODO: acceder au fichier .txt plus directement
    file.open("C:\\Users\\Simon\\Desktop\\Patate123\\ex10-8.txt");
    if (!file) {
        cerr << "Unable to open file";
        exit(1);
    }
    string firstLine;
    getline(file, firstLine);
    Point P[10];
    string line;
    int i = 0;
    while (getline(file, line))
    {
        size_t pos1 = 0;
        pos1 = line.find(" ");
        string token = line.substr(0, pos1);
        P[i].x = stoi(token);
        P[i].y = stoi(line.substr((pos1,token.length())));
        cout << P[i].x << " " << P[i].y << '\n';
        i++;
    }
    file.close();

    int n = sizeof(P) / sizeof(P[0]);
    cout << "La distance la plus petite entre deux points est: " << bruteForce(P, n) << '\n';
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "temps d'execution: " <<chrono::duration <double, milli> (diff).count() << " ms" << endl;
    return 0;
}