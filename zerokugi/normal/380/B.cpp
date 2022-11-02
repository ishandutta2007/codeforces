#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define EPS (1e-9)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
struct qa{
	int t,l,r,x;
	bool operator< (const qa &opp) const {
		if(t != opp.t) return t<opp.t;
		if(l != opp.l) return l<opp.l;
		if(r != opp.r) return r<opp.r;
		return x<opp.x;
	}
};

int next[200001];

main(){
	int n, m;
	set<qa> q;
	cin >> n >> m;
	next[1] = 1;
	for(int i=1;i<200000;i++) next[i+1] = next[i] + 1 + (__builtin_popcount(i) == 1);
	while(m--){
		int t;
		cin >> t;
		if(t == 1){
			int l, r, x;
			cin >> t >> l >> r >> x;
			q.insert((qa){t,l,r,x});
		}else{
			set<int> res;
			int l, r;
			cin >> t >> l;
			r = l;
			FOR(it, q){
				if(it->t < t) continue;
				for(;t < it->t;t++){
					l = next[l];
					r = next[r+1]-1;
				}
				if(!(it->r < l || r < it->l)) res.insert(it->x);
			}
			cout << res.size() << endl;
		}
	}
	return 0;
}