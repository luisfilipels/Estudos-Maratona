//
// Created by luisf on 12/11/2020.
//
// This solution gets 10% of the cases wrong. At least the general idea is correct.
/*
 * The idea behind this solution involves creating a graph. We have one vertex vor each of the walls in the room.
 * We also have one vertex for each of the sensors. If a sensor intersects with another sensor, we create an edge connecting
 * their vertices. If a sensor intersects with a wall, we also create an edge connecting this sensor to the wall that it
 * touched. With this done, we can do two DFS. If we can reach the lower wall starting from the left wall (or vice-versa), then that means
 * there are sensors blocking the path, and we return "N". Likewise, if we can reach the right wall from the upper wall,
 * we also return "N". If neither is the case, we return "S".
 */
#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define Fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
typedef long long ll;

struct Point {
    int x, y;

    Point(int x1, int y1) {
        x = x1;
        y = y1;
    }
};

struct Vertex {
    int idx;

    explicit Vertex(int i) {
        this->idx = i;
    }

    vector<int> neighbors;
};

struct Circle {
    int idx;
    Point p = Point(0, 0);
    int r;

    Circle(int idx, int x, int y, int r) {
        this->idx = idx;
        p = Point(x, y);
        this->r = r;
    }
};

Vertex topWall = Vertex(0), bottomWall = Vertex(2), leftWall = Vertex(3), rightWall = Vertex(1);
unordered_set<int> visited;
unordered_map<int, Vertex> vertices;
unordered_map<int, Circle> circles;
int m, n, k;

void makeNeighbor(int a, int b) {
    vertices.at(a).neighbors.push_back(b);
    vertices.at(b).neighbors.push_back(a);
}

double distanceBetweenCircles (Circle a, Circle b) {
    double item1 = pow(a.p.x - b.p.x, 2);
    double item2 = pow(a.p.y - b.p.y, 2);
    return sqrt(abs(item1 - item2));
}

void dfs(int start) {
    if (visited.count(start) != 0) return;

    visited.insert(start);
    Vertex v = vertices.at(start);


    for (int i : v.neighbors) {
        dfs(i);
    }
}

int main() {

    cin >> m >> n >> k;

    vertices.insert(mp(0, topWall));
    vertices.insert(mp(1, rightWall));
    vertices.insert(mp(2, bottomWall));
    vertices.insert(mp(3, leftWall));

    for (int i = 0; i < k; i++) {
        vertices.insert(mp(i+4, Vertex(i+4)));
    }

    for (int i = 0; i < k; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        circles.insert(mp(i+4, Circle(i+4, x, y, s)));
    }

    // Checking if circle intersects with wall
    for (auto x : circles) {
        Circle c = x.second;
        if (c.r + c.p.y >= m) { // Check upper wall
            makeNeighbor(c.idx, 0);
        }
        if (c.r + c.p.x >= n) {  // Check rightmost wall
            makeNeighbor(c.idx, 1);
        }
        if (c.p.y - c.r <= 0) {  // Check bottom wall
            makeNeighbor(c.idx, 2);
        }
        if (c.p.x - c.r <= 0) {     // Check leftmost wall
            makeNeighbor(c.idx, 3);
        }
    }

    // Check if circles intersect with each other
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (i == j) continue;
            Circle a = circles.at(i+4);
            Circle b = circles.at(j+4);

            if (distanceBetweenCircles(a, b) <= a.r + b.r) {
                makeNeighbor(a.idx, b.idx);
            }
        }
    }

    dfs(0);
    if (visited.count(1) != 0) {
        cout << "N";
        return 0;
    }
    visited.clear();
    dfs(2);
    if (visited.count(3) != 0) {
        cout << "N";
        return 0;
    }
    cout << "S";
    return 0;
}