#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<double, pii> pipii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=(x-1);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#include <complex>
#include <cmath>
#define EPS 1.0e-10
#define PI 3.1415926535897932384 
const ll MOD = 1000000007;
 class NazoTable{
	int N, K;
	vector< vector<int> > d;
	
	int combine(int i, int j){
		return __gcd(i, j);
	}
	
public:
	NazoTable(){}
	NazoTable(vector<int> v){
		N=v.size();
		K = 1;
		while((1<<K)<v.size()) K++;
		v.resize(1<<K);
		d = vector< vector<int> >(K, vector<int>(1<<K));
		for(int k=0;k<K;k++){
			for(int i=0;i<1<<(K-k-1);i++){
				int center = (i<<(k+1)) | (1<<k);
				d[k][center-1] = v[center-1];
				d[k][center  ] = v[center  ];
				for(int j=2;j<=(1<<k);j++) if(center  <N) d[k][center-j] = combine(v[center-j], d[k][center-j+1]);
				for(int j=1;j<(1<<k);j++)  if(center+j<N) d[k][center+j] = combine(d[k][center+j-1], v[center+j]);
			}
		}
	}
	
	int query(int l, int r){ // [l, r]
		r --;
		if(r<l) return 0;
		// index list O(logn)  O(1)
		for(int k=K-1;k>=0;k--) if((l^r)&(1<<k)) return combine(d[k][l], d[k][r]);
		return d[0][l];
	}
};

vector<pii> change;
NazoTable seg;
 
void search(int s, int l, int r, int lv, int rv){
//	printf("search %d %d %d %d %d\n", s, l, r, lv, rv);
	if(r-l <= 1){
		if(rv != lv) change.push_back(pii(l, rv));
	}else{
		int mid = (l+r)/2;
		int ret = seg.query(s, mid);
		if(ret != lv) search(s, l, mid, lv, ret);
		if(ret != rv) search(s, mid, r, ret, rv);
	}
}
int N, M;
main(){
	scanf("%d", &N);
	vector<int> v(N);
	REP(i, N){
		scanf("%d", &v[i]);
	}
	
	seg = NazoTable(v);
	
	scanf("%d", &M);
	vector<int> Q(M);
	unordered_map<int, ll> ans;
	REP(i, M){
		int t;
		scanf("%d", &t);
		ans[t] = 0;
		Q[i] = t;
	}
	REP(i, N){
		if(i && v[i] == v[i-1]){
			change[0].first ++;
		}else{
			change.clear();
			change.push_back(pii(i, v[i]));
			int rv = seg.query(i, N);
			if(v[i] != rv) search(i, i+1, N+1, v[i], rv);
			change.push_back(pii(N, 0));
		}
//		REP(j, change.size()) printf("(%d, %d) ", change[j].first, change[j].second);
//		puts("");
		RREP(j, change.size()-1){
			auto ret = ans.find(change[j].second);
			if(ret != ans.end()) ret->second += change[j+1].first - change[j].first;
		}
	}
	FOR(it, Q) printf("%lld\n", ans[*it]);
//	printf("%d\n", ans);
}