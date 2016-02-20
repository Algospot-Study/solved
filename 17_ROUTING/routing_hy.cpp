#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <queue>
#include <cstdio>

using namespace std;

const int MAXN = 10000;
const double INF = 987654321;
int n, m;

vector<pair<int, double>> adj[MAXN];

double dijkstra( int start, int end ) {
	vector<double> dist( n, INF );

	dist[start] = 0;

	priority_queue<pair<double, int>> pq;
	pq.push( make_pair(0, start) );
	while ( !pq.empty() ) {
		double cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();

		if ( cost > dist[here] ) {
			continue;
		}

		for ( int i = 0; i < adj[here].size(); ++i ) {
			int there = adj[here][i].first;
			double nextDist = adj[here][i].second;

			if ( dist[there] > cost + nextDist ) {
				dist[there] = cost + nextDist;

				pq.push( make_pair( -dist[there], there ) );
			}
		}
	}

	return pow(10, dist[end]);
}

int main() {
	int t;
	cin >> t;
	while ( t-- ) {
		cin >> n >> m;

		for ( int i = 0; i < n; ++i ) {
			adj[i].clear();
		}

		for ( int i = 0; i < m; ++i ) {
			int a, b;
			double c;
			cin >> a >> b >> c;
			adj[a].push_back( make_pair( b, log10( c ) ) );
			adj[b].push_back( make_pair( a, log10( c ) ) );
		}

		printf("%.10lf\n", dijkstra( 0, n - 1 ));
	}
	return 0;
}