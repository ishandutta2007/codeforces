#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>

#define INF (1000000000)
#define PI (acos(-1))
#define EPS (1e-8)

#define pb push_back
#define li long long

using namespace std;

int n, m, a[1000][1000], c1, c2, c3, b[1000][1000], x[10], y[10];

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int i, j, k, l, c1, c2, c3, d1, d2, d3;
	cin >> n >> m;
	for (i=1; i<=n; i++)
        for (j=1; j<=m; j++) cin >> a[i][j];
    cin >> c1 >> c2 >> c3;
    x[0] = c1, x[1] = c2; x[2] = c3;
	sort (x, x+3);
    int res = 0;
    memset (b, 0, sizeof(b));
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++) b[i][j] = a[i][j] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];


    /*for (i=1; i<=n; i++){
        for (j=1; j<=m; j++) cerr << b[i][j] << ' ';
        cerr << endl;
    }*/

    for (i=1; i<n; i++)
        for (j=i+1; j<n; j++){
            d1 = b[i][m]; d2 = b[j][m] - b[i][m]; d3 = b[n][m] - b[j][m];
            y[0] = d1; y[1] = d2; y[2] = d3;
            //cerr << d1 << ' ' << d2 << ' ' << d3 << endl;
            sort (y, y+3);
            //cerr << y[0] << ' ' << y[1] << ' ' << y[2] << endl;
            //cerr << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
            if (x[1] == y[1] && x[2] == y[2] && x[0] == y[0]) res++;
        }

    for (i=1; i<m; i++)
        for (j=i+1; j<m; j++){
            d1 = b[n][i]; d2 = b[n][j]- b[n][i]; d3 = b[n][m] - b[n][j];
            y[0] = d1; y[1] = d2; y[2] = d3;
            sort (y, y+3);
            if (x[1] == y[1] && x[2] == y[2] && x[0] == y[0]) res++;
        }

    cout << res << endl;
}