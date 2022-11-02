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

class J{
	public:
	map<int, int> Q, T;
	int n, m, q; //n = |T|, m = |T and Q|
	J(map<int, int> qts){
		Q = qts;
		n=0;m=0;q=0;
		FOR(it, qts) q += it->second;
	}
	
	void add(int s){
		if(Q[s] > T[s]) m ++;
		T[s] ++;
		n ++;
	}
	void sub(int s){
		if(!T[s]) return ;
		if(Q.count(s) && Q[s] >= T[s]) m --;
		T[s] --;
		n --;
		if(T[s] == 0) T.erase(s);
	}
	bool get(){
		return (m == q && m == n);
	}
};

ll n, m, p;
main(){
	cin >> n >> m >> p;
	vector<int> a(n);
	map<int, int> b;
	REP(i, n) cin >> a[i];
	REP(i, m){
		int x;
		cin >> x;
		b[x] ++;
	}
	vector<int> ans;
	REP(i, p){
		if(n <= i + p*(m-1)) break;
		J c(b);
		ll t = i;
		REP(j, m){
			c.add(a[t]);
			t += p;
		}
		if(c.get()) ans.push_back(t-m*p);
		while(t < n){
			c.sub(a[t-m*p]);
			c.add(a[t]);
			t += p;
			if(c.get()) ans.push_back(t-m*p);
		}
	}
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	REP(i, ans.size()){
		if(i) cout << " ";
		cout << (ans[i] + 1);
	}
	cout << endl;
	return 0;
}