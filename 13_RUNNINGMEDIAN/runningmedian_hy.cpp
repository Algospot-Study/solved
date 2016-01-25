#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

long long num;
int a, b;

int generate() {
	long long tmp = num;
	num = ( num * a + b ) % 20090711;
	return (int) tmp;
}

int main() {
	int c;
	cin >> c;
	while ( c-- ) {
		int n;
		cin >> n >> a >> b;

		num = 1983;

		/*
		for ( int i = 0; i < 5; ++i ) {
			cout << generate() << endl;
		}

		continue;
		*/

		priority_queue<int, vector<int>, greater<int>> minh;
		priority_queue<int> maxh;

		int ret = 0;

		for ( int i = 0; i < n; ++i ) {
			if ( minh.empty() ) {
				if ( maxh.empty() ) {
					maxh.push( generate() );
				}
				else {
					int a = maxh.top();
					maxh.pop();
					int b = generate();
					if ( a > b ) {
						maxh.push( b );
						minh.push( a );
					}
					else {
						maxh.push( a );
						minh.push( b );
					}
				}
			}

			else {
				vector<int> arr;
				arr.push_back( minh.top() );
				arr.push_back( maxh.top() );
				arr.push_back( generate() );
				sort( arr.begin(), arr.end() );
				minh.pop();
				maxh.pop();
				if ( minh.size() == maxh.size() ) {
					maxh.push( arr[0] );
					maxh.push( arr[1] );
					minh.push( arr[2] );
				}
				else if (minh.size() + 1 == maxh.size()) {
					maxh.push( arr[0] );
					minh.push( arr[1] );
					minh.push( arr[2] );
				}
				else {
					exit( 1 );
				}
			}

			ret = ( ret + maxh.top() ) % 20090711;
		}

		cout << ret << endl;

	}
	return 0;
}