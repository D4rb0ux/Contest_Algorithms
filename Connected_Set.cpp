//Даны несколько точек на плоскости, некоторые из которых соединены отрезками. 
//Множество точек называется связанным, если из любой его точки можно перейти в любую точку, 
//перемещаясь только по отрезкам (переходить с отрезка на отрезок возможно только в точках исходного множества). 
//Можно за определенную плату добавлять новые отрезки (стоимость добавления равна длине добавляемого отрезка). 
//Требуется за минимальную стоимость сделать данное множество связанным.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int parent[100000];

void make_set(int vertex) {
    parent[vertex] = vertex;
}

int find_(int vertex) {
    if (vertex == parent[vertex])
        return vertex;
    return parent[vertex] = find_(parent[vertex]);
}

void union_(int x, int y) {
    x = find_(x);
    y = find_(y);
    if (x != y)
        parent[x] = y;
}

int main() {
    int n;
    cin >> n;
    double x, y;
    pair<double, double> points[100];
    vector<pair<double, pair<int, int>>> graph(10000);
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        make_set(i);
        points[i].first = x;
        points[i].second = y;
    }

    int k = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                x = points[i].first - points[j].first;
                y = points[i].second - points[j].second;
                graph[k].first = sqrt(x * x + y * y);
                graph[k].second.first = i;
                graph[k].second.second = j;
                k++;
            }
        }
    }

    graph.resize(k);


    int m;
    double cost = 0;
    cin >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        union_(a, b);
    }

    sort(graph.begin(), graph.end());

    for (int i = 0; i < k; i++) {
        int a = graph[i].second.first;
        int b = graph[i].second.second;
        double l = graph[i].first;
        if (find_(a) != find_(b)) {
            cost += l;
            union_(a, b);
        }
    }
    cout << fixed << setprecision(5) << cost;
}
