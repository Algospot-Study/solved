#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
using namespace std;
typedef int KeyType;
struct Node {
	KeyType key;

	int priority, size;

	Node *left, *right;
	Node( const KeyType& _key ): key( _key ), priority( rand() ), size( 1 ), left( NULL ), right( NULL ) {}
	void setLeft( Node* newLeft ) {
		left = newLeft; calcSize();
	}
	void setRight( Node* newRight ) {
		right = newRight; calcSize();
	}
	void calcSize() {
		size = 1;
		if ( left ) size += left->size;
		if ( right ) size += right->size;
	}
};

typedef pair<Node*, Node*> NodePair;

NodePair split( Node* root, KeyType key ) {
	if ( root == NULL ) return NodePair( NULL, NULL );
	if ( root->key < key ) {
		NodePair rs = split( root->right, key );
		root->setRight( rs.first );
		return NodePair( root, rs.second );

	}
	NodePair ls = split( root->left, key );
	root->setLeft( ls.second );
	return NodePair( ls.first, root );
}
Node* insert( Node* root, Node* node ) {
	if ( root == NULL ) return node;
	if ( root->priority < node->priority ) {
		NodePair splitted = split( root, node->key );
		node->setLeft( splitted.first );
		node->setRight( splitted.second );
		return node;
	}
	else if ( node->key < root->key )
		root->setLeft( insert( root->left, node ) );
	else
		root->setRight( insert( root->right, node ) );
	return root;
}
Node* merge( Node* a, Node* b ) {
	if ( a == NULL ) return b;
	if ( b == NULL ) return a;
	if ( a->priority < b->priority ) {
		b->setLeft( merge( a, b->left ) );
		return b;
	}
	a->setRight( merge( a->right, b ) );
	return a;
}

Node* erase( Node* root, KeyType key ) {
	if ( root == NULL ) return root;
	if ( root->key == key ) {
		Node* ret = merge( root->left, root->right );
		delete root;
		return ret;
	}
	if ( key < root->key )
		root->setLeft( erase( root->left, key ) );
	else
		root->setRight( erase( root->right, key ) );
	return root;
}
Node* kth( Node* root, int k ) {
	int leftSize = 0;
	if ( root->left != NULL ) leftSize = root->left->size;
	if ( k <= leftSize ) return kth( root->left, k );
	if ( k == leftSize + 1 ) return root;
	return kth( root->right, k - leftSize - 1 );
}
int main() {
	int c;
	cin >> c;
	while ( c-- ) {
		int n;
		cin >> n;

		vector<int> arr( n );
		for ( int i = 0; i < n; ++i ) {
			scanf_s( "%d", &arr[i] );
		}

		Node *root = new Node(1);
		
		for ( int i = 2; i <= n; ++i ) {
			Node *node = new Node(i);
			root = insert( root, node );
		}

		vector<int> result( n );

		for ( int i = n - 1; i >= 0; --i ) {
			Node* node = kth( root, root->size - arr[i] );
			int key = node->key;
			result[i] = key;
			root = erase( root, key );
		}

		for ( int i = 0; i < n; ++i ) {
			printf( "%d ", result[i] );
		}
		printf( "\n" );
	}
	return 0;
}