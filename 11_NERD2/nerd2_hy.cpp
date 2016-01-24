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
#include <utility>
#include <cstdlib>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;
		map<int, int> m;
		int cnt = 0;

		for ( int i = 0; i < n; ++i ) {
			int p, q;
			scanf_s( "%d%d", &p, &q );

			m.insert( make_pair( p, q ) );

			auto it = m.find( p );
			
			bool erased = false;
			auto e = m.end();
			e--;

			if ( it != e && it != m.end() ) {
				auto af = it;
				af++;

				if ( af->second > it->second ) {
					m.erase( it );
					erased = true;
				}
			}
			if (!erased) {
				while ( true ) {
					if ( it == m.begin() || it == m.end()) {
						break;
					}
					auto bf = it;
					bf--;

					if ( it->second > bf->second ) {
						m.erase( bf );
					}
					else {
						break;
					}
				}
			}
			cnt += m.size();
		}
		cout << cnt << endl;
	}
	return 0;
}