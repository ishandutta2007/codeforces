#include <bits/stdc++.h>

using namespace std;

const int maxn = 200020;
const int inf = 1e9;

struct node
{
	int a[5][5];
	node operator + ( const node b ) const
	{
		node c;
		for( int i = 0 ; i < 5 ; i++ )
			for( int j = 0 ; j < 5 ; j++ )
			{
				c.a[ i ][ j ] = inf;
				for( int k = 0 ; k < 5 ; k++ )
					c.a[ i ][ j ] = min( c.a[ i ][ j ], a[ i ][ k ] + b.a[ k ][ j ] );
			}
		return c;
	}
}e[maxn << 2];

char s[maxn];

int n, Q;

void build(int x, int l, int r)
{
	if( l == r )
	{
		for( int i = 0 ; i < 5 ; i++ )
			for( int j = 0 ; j < 5 ; j++ )
				e[ x ].a[ i ][ j ] = ( i == j ) ? 0 : 1e9;
		if( s[ l ] == '2' )
		{
			e[ x ].a[ 0 ][ 0 ] = 1;
			e[ x ].a[ 0 ][ 1 ] = 0;
		}
		else if( s[ l ] == '0' )
		{
			e[ x ].a[ 1 ][ 1 ] = 1;
			e[ x ].a[ 1 ][ 2 ] = 0;
		}
		else if( s[ l ] == '1' )
		{
			e[ x ].a[ 2 ][ 2 ] = 1;
			e[ x ].a[ 2 ][ 3 ] = 0;
		}
		else if( s[ l ] == '7' )
		{
			e[ x ].a[ 3 ][ 3 ] = 1;
			e[ x ].a[ 3 ][ 4 ] = 0;
		}
		else if( s[ l ] == '6' )
		{
			e[ x ].a[ 3 ][ 3 ] = 1;
			e[ x ].a[ 4 ][ 4 ] = 1;
		}
		return ;
	}
	int mid = l + r >> 1;
	build( x << 1, l, mid );
	build( x << 1 | 1, mid + 1, r );
	e[ x ] = e[ x << 1 ] + e[ x << 1 | 1 ];
}

node query(int x, int l, int r, int ql, int qr)
{
	if( l == ql && r == qr )
		return e[ x ];
	int mid = l + r >> 1;
	if( qr <= mid ) return query( x << 1, l, mid, ql, qr );
	if( ql > mid ) return query( x << 1 | 1, mid + 1, r, ql, qr );
	return query( x << 1, l, mid, ql, mid ) + query( x << 1 | 1, mid + 1, r, mid + 1, qr );
}

int main()
{
	scanf( "%d%d%s", &n, &Q, s + 1 );
	build( 1, 1, n );
	while( Q-- )
	{
		int l, r;
		scanf( "%d%d", &l, &r );
		int ans = query( 1, 1, n, l, r ).a[ 0 ][ 4 ];
		if( ans == inf )
			printf( "-1\n" );
		else
			printf( "%d\n", ans );
	}
}