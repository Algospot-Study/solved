#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <cctype>
#include <limits>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k, n; 
		cin >> k >> n;
		queue<int> q;
		ll a = 1983;
		int sum = 0;
		int i = 0;
		ll cnt = 0;
		while (i < n) {
			while (sum >= k) {
				if (sum == k) {
					cnt++;
				}
				sum -= q.front();
				q.pop();
			}
			q.push(a % 10000 + 1);
			sum += q.back();
			a = (a * 214013 + 2531011) % 0x100000000;
			i++;
		}
		cout << cnt << endl;
	}
	return 0;
}