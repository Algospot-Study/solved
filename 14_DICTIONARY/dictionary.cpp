#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> dic(26);
vector<int> result;
vector<bool> visited(26, false);

void dfs(int start) {
	visited[start] = true;

	for (int i = 0; i < dic[start].size(); ++i) {
		int end = dic[start][i];
		if (!visited[end]) {
			dfs(end);
		}
	}

	result.push_back(start);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		dic = vector<vector<int>>(26);
		result.clear();
		visited = vector<bool>(26, false);
		vector<string> str(n);
		for (int i = 0; i < n; i++) {
			cin >> str[i];
		}

		for (int i = 1; i < n; ++i) {
			string one = str[i - 1], two = str[i];

			for (int j = 0; j < min(one.size(), two.size()); ++j) {
				if (one[j] != two[j]) {
					int a = one[j] - 'a';
					int b = two[j] - 'a';
					bool isin = false;
					for (int k = 0; k < dic[a].size(); ++k) {
						if (dic[a][k] == b) {
							isin = true;
							break;
						}
					}
					if (!isin) {
						dic[a].push_back(b);
					}
					break;
				}
			}
		}

		vector<bool> top(26, true);

		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < dic[i].size(); ++j) {
				top[dic[i][j]] = false;
			}
		}

		for (int i = 0; i < 26; ++i) {
			if (top[i] && !dic[i].empty()) {
				dfs(i);
			}
		}

		if (result.empty() && n != 1) {
			cout << "INVALID HYPOTHESIS" << endl;
		}
		else {
			bool invalid = false;
			for (int i = 0; i < result.size(); ++i) {
				for (int j = i + 1; j < result.size(); ++j) {
					for (int k = 0; k < dic[result[i]].size(); ++k) {
						if (dic[result[i]][k] == result[j]) {
							invalid = true;
						}
					}
				}
			}

			if (invalid) {
				cout << "INVALID HYPOTHESIS" << endl;
				continue;
			}

			vector<bool> printed(26, false);
			for (int i = result.size() - 1; i >= 0 ; --i) {
				cout << (char)(result[i] + 'a');
				printed[result[i]] = true;
			}
			for (int i = 0; i < 26; ++i) {
				if (!printed[i]) {
					cout << (char)(i + 'a');
				}
			}
			cout << endl;
		}

	}
	return 0;
}