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
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int n, k;
vector<pii> e;
vector<pii> p;
ll const INF = 1LL<<60;
ll check(int c){
	int rest = 0;
	vector<int> s, t;
	REP(i, n){
		if(p[i].first < c-1) rest ++;
		if(p[i].first == c || p[i].first == c-1) s.push_back(p[i].second);
		else t.push_back(p[i].second);
	}
	sort(s.begin(), s.end());
	ll ans = 0;
//	cout << rest << " " << n-(k-1)-rest << " " << s.size() << endl;
	REP(i, s.size()){
		if(i < n-(k-1)-rest) ans += s[i];
		else t.push_back(s[i]);
	}
	sort(t.begin(), t.end());
//	cout << ans << " ";
	REP(i, c-(n-t.size())){
		if(t.size() <= i) return INF;
		ans += t[i];
	}
//	cout << ans << endl;
	return ans;
}

main(){
	scanf("%d%d", &n, &k);
	if(n+1 == k){
		cout << "0" << endl;
		return 0;
	}
	e = vector<pii>(n);
	p = vector<pii>(n);
	REP(i, n){
		scanf("%d%d", &p[i].first, &p[i].second);
		e[i] = pii(p[i].second, -p[i].first);
	}
	sort(p.begin(), p.end());
	sort(e.begin(), e.end());
	int reqp = p[n-k].first;
	if(n < reqp) cout << "-1" << endl;
	else{
		ll ans = min(check(reqp+2), min(check(reqp+1), check(reqp)));
//		REP(i, reqp+1) ans += e[i].first;
//		cout << ans << " ";
		cout << (ans==INF?-1:ans) << endl;
	}
	return 0;
}