#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define RFOR(i,c) for(auto i=(c).rbegin();i!=(c).rend();++i)
#define ALL(container) container.begin(), container.end()
#define SZ(container) ((int)container.size())

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n, m;
main(){
	scanf("%d%d", &n, &m);
	vector<int> p(m);
	vector<vi> adj(n+1);
	ll sum=0;
	REP(i, m) scanf("%d", &p[i]);
	p.erase( unique(ALL(p)), p.end() );
	m = p.size();
	REP(i, m-1){
		sum += abs(p[i]-p[i+1]);
		adj[p[i]].push_back(p[i+1]);
		adj[p[i+1]].push_back(p[i]);
	}
	ll pmax = 0;
	REP(i, n+1){
		vi &tar = adj[i];
		if(tar.size() == 0) continue;
		sort(ALL(tar));
		int med = tar[tar.size()/2];
		ll sum = 0;
		REP(j, tar.size()){
			sum += abs(tar[j] - i) - abs(tar[j] - med);
		}
		pmax = max(pmax, sum);
	}
	cout << sum-pmax << endl;
	return 0;
}