#include <iostream>
#include <string>

using namespace std;

string s;
int wa = 0;

string reverse() {
	if (s[wa] == 'b' || s[wa] == 'w') {
		wa++;
		return s.substr(wa-1, 1);
	}
	string one, two, three, four;
	wa++;
	one = reverse();
	two = reverse();
	three = reverse();
	four = reverse();

	return "x" + three + four + one + two;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> s;
		wa = 0;
		cout << reverse() << endl;
	}

	return 0;
} 