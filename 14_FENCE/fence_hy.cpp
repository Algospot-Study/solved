#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int maxArea( int start, int end, vector<int>& fence ) {
	if ( start == end ) {
		return fence[start];
	}

	int mid = ( start + end ) / 2;

	int area = -1;

	area = max( area, maxArea( start, mid, fence ) );
	area = max( area, maxArea( mid+1, end, fence ) );

	int left = mid;
	int right = mid + 1;
	int height = min( fence[left], fence[right] );


	while ( true ) {
		area = max( area, height * (right - left + 1) );

		if ( left == start && right == end ) {
			break;
		}

		else if ( left != start && right != end ) {
			int lfence = fence[left - 1];
			int rfence = fence[right + 1];

			if ( lfence < rfence ) {
				right++;
				if ( fence[right] < height ) {
					height = fence[right];
				}
			}
			else {
				left--;
				if ( fence[left] < height ) {
					height = fence[left];
				}
			}
		}

		else if ( left == start ) {
			right++;
			if ( fence[right] < height ) {
				height = fence[right];
			}
		}

		else if ( right == end ) {
			left--;
			if ( fence[left] < height ) {
				height = fence[left];
			}
		}


	}

	return area;
}

int main() {

	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		vector<int> fence(n);

		for ( int i = 0; i < n; ++i ) {
			scanf("%d", &fence[i]);
		}

		cout << maxArea( 0, n - 1, fence ) << endl;
	}

	return 0;

}