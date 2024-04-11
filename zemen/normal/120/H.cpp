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
#define pr 251

using namespace std;

char s[300][300];
int n, k;
int timer = 0;

map <int, int> h;
string qwe[200*386];
vector<int> g[210];
int mt[200*386];
bool used[210];

bool kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int hash (string s){
    int i, res = 0, q = 1;
    for (i=0; i<s.length(); i++){
        res += s[i] * q;
        q *= pr;
    }
    return res;
}

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	scanf ("%d\n", &n);
	int i, j, kk, l, d;
	for (i=0; i<n; i++) gets (s[i]);
	for (i=0; i<n; i++){
	    int m = strlen (s[i]);
        for (j=0; j<m; j++)
            for (kk=j+1; kk<m+1; kk++)
                for (l=kk+1; l<m+2; l++)
                    for (d=l+1; d<m+3; d++){
                        string q = "";
                        q += s[i][j];
                        if (kk < m) q += s[i][kk];
                        if (l < m) q += s[i][l];
                        if (d < m) q += s[i][d];
                        int e = hash (q);
                        map<int, int>::iterator it = h.find(e);
                        if (it != h.end()){
                            g[i].pb(it->second);
                        } else {
                            qwe[timer] = q;
                            h[e] = timer++;
                            g[i].pb(timer - 1);
                        }
                    }
	}
    k = timer;
    //bayan
    for(i = 0; i < k; ++i)
        mt[i] = -1;
	vector<char> used1 (n);
	for (i=0; i<n; ++i)
		for (size_t j=0; j<g[i].size(); ++j)
			if (mt[g[i][j]] == -1) {
				mt[g[i][j]] = i;
				used1[i] = true;
				break;
			}
	for (i=0; i<n; ++i) {
		if (used1[i])  continue;
		memset(used, 0, sizeof(used));
		if (!kuhn (i)) {
            printf("-1");
            return 0;
		}
	}
    int mt_obr[210];
	for (i=0; i<k; ++i)
		if (mt[i] != -1)
            mt_obr[mt[i]] = i;
    for (i = 0; i < n; ++i)
        cout << qwe[mt_obr[i]] << '\n';
}