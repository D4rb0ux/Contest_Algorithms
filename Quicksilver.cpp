//Наступила полночь, а значит Чарльз, Людовик и пес Барбос вновь выходят на очередное дело. 
//В этот раз они грабят товарный поезд, перевозящий ценные запасы ртути. В поезде перевозится N видов ртути, 
//причем i-ый вид в количестве wi мг. Чарльз знает, что за wi мг i-ого вида ртути они получат в награду pi условных единиц 
//(но только единожды, т.е. они не могут бесконечно продавать 0 мг). Конечно, если бы это было возможно, наши грабители, 
//не раздумывая, унесли бы все. Однако они знают, что если наберут ртути массой более W мг, 
//то это для них кончится летально, ведь испарения ртути очень ядовиты.
//Поскольку ртуть — жидкая, то любой ее вид можно взять в любом количестве (но не более wi, разумеется). 
//При этом стоимость набранного естественным образом пересчитывается, исходя из стоимости pi за wi мг.
//Помогите Чарльзу, Людовику и Барбосу получить максимальную прибыль и остаться в живых.

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    size_t n, limit;
    size_t total_weight = 0;
    double total_value = 0;
    size_t price, weight;
    cin >> n >> limit;
    vector<pair<size_t, size_t>> price_weight;
    for (int i = 0; i < n; i++) {
        cin >> price >> weight;
        if (weight == 0) {
            total_value += price;
        } else {
            pair<size_t, size_t> p = {price, weight};
            price_weight.push_back(p);
        }
    }
    sort(price_weight.begin(), price_weight.end(), [](pair<size_t, size_t> a, pair<size_t, size_t> b) {
        return (a.first * 1.0 / a.second) > (b.first * 1.0 / b.second);
    });
    int i = 0;
    size_t w, p;
    while (i < n) {
        w = price_weight[i].second, p = price_weight[i].first;
        if (total_weight + w <= limit) {
            total_weight += w;
            total_value += p;
            i++;
        } else {
            total_value += (p * 1.0 / w) * (limit - total_weight);
            i = n;
        }
    }
    cout << fixed << setprecision(6) << total_value;
}
