#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <cctype>
#include <limits>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
	int c;
	cin >> c;
	getchar();

	while (c--) {
		stack<char> s;
		char c;

		while ((c = getchar()) != '\n') {
			if (c == ')' && !s.empty() && s.top() == '(') {
				s.pop();
			}
			else if (c == '}' && !s.empty() && s.top() == '{') {
				s.pop();
			}
			else if (c == ']' && !s.empty() && s.top() == '[') {
				s.pop();
			}
			else {
				s.push(c);
			}
		}

		if (s.empty()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}