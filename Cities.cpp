//Петя и Вася играют в города. Правила игры такие:
//Петя называет любой город;
//Вася называет любой город, до которого можно доехать на машине из города, который назвал Петя;
//Петя называет любой город, до которого можно доехать на машине из последнего города, который назвал Вася;
//И т.д.
//Города, называемые игроками, не должны повторяться. Если игрок не может назвать ни одного города по указанным выше правилам, 
//этот игрок проиграл.
//Считается, что из города А можно доехать на машине до города B, 
//если существует последовательность городов (A, x1, …, xk, B), такая, 
//что между любыми двумя соседними городами в этой последовательности есть автомобильная дорога.
//Петя слышал, что недавно боты OpenAI победили пятёрку профессиональных игроков в Доту. 
//Петя хочет написать такого же бота для игры в города, чтобы бот играл за Петю и всегда выигрывал. 
//За помощью Петя обратился к вам.

#include<iostream>

using namespace std;

int parent[100000];
int components[100000];

void make_set(int vertex) {
    parent[vertex] = vertex;
    components[vertex] = 1;
}

int find_(int vertex) {
    if (vertex == parent[vertex])
        return vertex;
    return parent[vertex] = find_(parent[vertex]);
}

void union_(int x, int y) {
    x = find_(x);
    y = find_(y);
    if (x != y) {
        if (x < y) {
            parent[y] = x;
            components[x] += components[y];
        }
        else {
            parent[x] = y;
            components[y] += components[x];
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    char command;
    int a, b, ans;
    for (int i = 0; i < m; i++) {
        cin >> command;
        if (command == 'a') {
            cin >> a >> b;
            union_(a, b);
        }
        if (command == 'c') {
            int ans = -1;
            for (int k = 1; k <= n; k++) {
                if (components[find_(k)] % 2 != 0) {
                    ans = k;
                    break;
                }
            }
            cout << ans << endl;
        }
    }
}
