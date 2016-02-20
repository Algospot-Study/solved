#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> m(n);
	for ( int i = 0; i < n; ++i ) {
		int start, end;
		cin >> start >> end;
		m[i] = make_pair( end, start );
	}

	sort( m.begin(), m.end() );

	int endTime = 0;
	int ret = 0;

	for ( int i = 0; i < n; ++i ) { 
		if ( endTime <= m[i].second ) {
			endTime = m[i].first;
			ret++;
		}
	}

	cout << ret << endl;

	return 0;
}