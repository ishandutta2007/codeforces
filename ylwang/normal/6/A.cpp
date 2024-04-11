#include <bits/stdc++.h>
using namespace std;
int f[5];//
int main(){
    for ( int i = 1; i <= 4; i++ )
    scanf ( "%d", &f[i] );
    sort ( f + 1, f + 5 );//
    if ( f[1] + f[2] > f[3] || f[2] + f[3] > f[4] ) printf ( "TRIANGLE\n" );
    else if ( f[1] + f[2] == f[3] || f[2] + f[3] == f[4] ) printf ( "SEGMENT\n" );
    else printf ( "IMPOSSIBLE\n" );
    return 0;
}