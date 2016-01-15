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

void print(vector<int> pre, vector<int> in) {
	if (pre.size() == 1) {
		cout << pre[0] << ' ';
		return;
	}
	if (pre.size() == 0) {
		return;
	}

	int root = pre[0];
	int lsize;
	for (int i = 0; i < (int)in.size(); ++i) {
		if (in[i] == root) {
			lsize = i;
			break;
		}
	}

	print(vector<int>(pre.begin() + 1, pre.begin() + 1 + lsize), vector<int>(in.begin(), in.begin() + lsize));
	print(vector<int>(pre.begin() + 1 + lsize, pre.end()), vector<int>(in.begin() + 1 + lsize, in.end()));
	cout << root << ' ';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int>pre(n);
		vector<int>in(n);
		for (int i = 0; i < n; ++i) {
			cin >> pre[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> in[i];
		}

		print(pre, in);
	}
	return 0;
}