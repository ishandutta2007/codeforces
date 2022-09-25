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

int a[1000][1000], b[1000][1000], c[1000], d[1000][1000];
vector <string> s(1000);
vector < vector <int> > res (1000);

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int n, t, i, j, k, m, ii, jj;
	string qq;
	memset (d, 0, sizeof(d));
	cin >> n >> t;
	for (i=0; i<n; i++) cin >> a[i][0] >> b[i][0] >> a[i][1] >> b[i][1];
	cin >> m;
	getline (cin, qq);
	for (i=0; i<m; i++){
	    getline (cin, s[i]);
	    cin >> c[i];
	    getline (cin, qq);
	}
	queue <int> q;
	int curTeam = 0;
	int curP = 0;
	for (i=0; i<m; i++) q.push (i);
	while (!q.empty()){
	    //cerr << curTeam << ' ' << curP << endl;
	    int curT = t;
	    while (curT > 0){
	        if (q.empty()) break;
            int g = q.front();
            q.pop();
            int h = max (1, c[g] - (a[curTeam][curP] + b[curTeam][1-curP]) - d[curTeam][g]);
            int e = min (curT, h);
            d[curTeam][g] += e;
            if (h > curT) q.push (g); else res[curTeam].pb (g);
            curT -= e;
	    }
	    curTeam++;
	    if (curTeam == n) {
	        curTeam = 0;
	        curP = 1 - curP;
	    }

	    /*for (ii=0; ii<n; ii++){
            for (jj=0; jj<m; jj++) cerr << d[ii][jj] << ' ';
            cerr << endl;
	    }
	    cerr << "_________" << endl;*/
	}
	for (i=0; i<n; i++){
	    cout << res[i].size();
	    for (j=0; j<res[i].size(); j++) cout << ' ' << s[res[i][j]];
	    cout << endl;
	}
}