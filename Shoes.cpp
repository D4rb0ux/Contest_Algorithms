//Сапожник умеет делать сапоги лишь одной модели. Некоторые заказчики готовы дополнительно платить за срочность, 
//но в любом случае на изготовление одной пары у сапожника уходит час. Сапожнику поступило k заказов. 
//Для каждого заказа указано время в часах, через которое его необходимо выполнить, и сумма, 
//которую готов заплатить заказчик за своевременное выполнение заказа. Начав выполнять заказ, 
//сапожник доводит его до конца, не отвлекаясь на прочие заказы (и вообще ни на что). 
//Определите максимально возможную выручку сапожника за выполненные заказы.

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<double, double>> time_value(n);
    for (int i = 0; i < n; i++)
        cin >> time_value[i].first;
    for (int i = 0; i < n; i++)
        cin >> time_value[i].second;
    vector<bool> occupied(n + 1, false);
    sort(time_value.begin(), time_value.end(), [](pair<double, double> a, pair<double, double> b) {
        return a.second > b.second;
    });
    double total_value = 0;
    for (int i = 0; i < n; i++) {
        size_t time = floor(time_value[i].first);
        double value = time_value[i].second;
        if (time != 0) {
            if (!occupied[time]) {
                total_value += value;
                occupied[time] = true;
            } else {
                for (int i = time - 1; i >= 1; i--) {
                    if (!occupied[i]) {
                        total_value += value;
                        occupied[i] = true;
                        break;
                    }
                }
            }
        }
    }
    cout << total_value;
}
