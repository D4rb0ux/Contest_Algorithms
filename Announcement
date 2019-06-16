//Нужно сделать объявление по громкой связи, чтобы все сотрудники, работающие в здании, его услышали. 
//Однако у каждого сотрудника свой график. 
//Сколько раз необходимо повторить объявление, чтобы его услышали все хотя бы по одному разу?

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> time(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i].first >> time[i].second;
        if (time[i].first > time[i].second)
            swap(time[i].first, time[i].second);
    }
    sort(time.begin(), time.end(), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });
    pair<int, int> cur = time[0];
    int ans = 1;
    for (int i = 1; i < time.size(); i++) {
        if (!(time[i].first <= cur.second)) {
            cur = time[i];
            ans++;
        }
    }
    cout << ans;
}
