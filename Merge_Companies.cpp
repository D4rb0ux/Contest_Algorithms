//Джон развозит пиццу в компании Кремниевой долины. 
//Бизнес в Кремниевой долине идёт так быстро, что к тому времени, как Джон выставляет счёт за пиццу компании А, 
//может оказаться, что компанию А поглотила компания B, и счёт нужно выставлять уже ей. Джону это порядком надоело, 
//и он просит вас написать программу, которая всегда сможет сказать, какой компании выставлять счёт.

#include<iostream>

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
    parent[y] = x;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        make_set(i);
    char command;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> command;
        if (command == 'm') {
            cin >> a >> b;
            union_(a, b);
        }if (command == 'b') {
            cin >> a;
            cout << find_(a) << "\n";
        }
    }
}
