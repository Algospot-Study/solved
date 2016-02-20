
#include <iostream>
#include <vector>

using namespace std;

int schedule(int &n, int begin[], int end[]) {
    vector<pair<int, int>> order;
    for(int i=0; i<n; i++){
        order.push_back(make_pair(end[i], begin[i]));
    }
    sort(order.begin(), order.end());

    int earliest = 0, selected = 0;
    for(int i =0; i<order.size(); ++i){
        int meetingBegin = order[i].second, meetingEnd = order[i].first;
        if(earliest <= meetingBegin){
            earliest = meetingEnd;
            ++selected;
        }
    }
    return selected;
}

int main() {
    int n;
    int begin[100], end[100];

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> begin[i] >> end[i];
    }
    cout << schedule(n, begin, end) << endl;
}