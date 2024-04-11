#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

void dfsDist(int i, int p, vector<int>& dists, vector<vector<int> >& grafo, int d) {
	dists[i] = d;
	forn(j, grafo[i].size()) {
		if(grafo[i][j] != p) {
			dfsDist(grafo[i][j], i, dists, grafo, d+1);
		}
	}
}

vector<int> findDists(int i, vector<vector<int> >& grafo) {
	vector<int> ans(grafo.size(), 0);
	dfsDist(i, -1, ans, grafo, 0);
	return ans;
}

int findFarthest(vector<int>& dists) {
	int ans = 0;
	forn(i, dists.size()) if(dists[i] > dists[ans]) ans = i;
	return ans;
}

void dfsAns(int i, int p, vector<int>& distsa, vector<int>& distsb, vector<int>& diams, vector<vector<int> >& grafo, int diam, int a, int b) {
	forn(j, grafo[i].size()) {
		if(grafo[i][j] != p) {
			dfsAns(grafo[i][j], i, distsa, distsb, diams, grafo, diam, a, b);
		}
	}
	if(distsa[i] + distsb[i] > diam) {
		int p = a;
		if(distsb[i] > distsa[i]) p = b;
		cout << i+1 << " " << p+1 << " " << i+1 << endl;
	} else {
		diams[distsa[i]] = i;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int> > grafo(n);
	forn(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}
	
	vector<int> dists1 = findDists(0, grafo);
	int a = findFarthest(dists1);
	vector<int> distsa = findDists(a, grafo);
	int b = findFarthest(distsa);
	vector<int> distsb = findDists(b, grafo);
	
	int diam = distsa[b];
	vector<int> diams(diam+1);
	
	tint ans = 0;
	forn(i, n) {
		if(distsa[i] + distsb[i] > diam) ans += max(distsa[i], distsb[i]);
		else ans += distsb[i];
	}
	cout << ans << endl;
	
	dfsAns(a, -1, distsa, distsb, diams, grafo, diam, a, b);
	
	forn(i, diam) {
		cout << diams[i]+1 << " " << b+1 << " " << diams[i]+1 << endl;
	}
	return 0;
}