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

int n;
map<ll, pii> data;

main(){
	
	cin >> n;
	ll cnt = 0;
	REP(i, n){
		ll t,a,b;
		cin >> t;
		if(t == 1){
			cin >> a;
			data[cnt] = pii(0, a);
			cnt ++;
		}else{
			cin >> a >> b;
			data[cnt] = pii(b, a);
			cnt += a*b;
		}
	}
//	FOR(it, data) cout << it->first << ": " << it->second.first << ", " << it->second.second << endl;
	cin >> n;
	REP(i, n){
		ll p;
		map<ll, pii>::iterator tar;
		cin >> p;
		p --;
//		cout << "p:" << p << endl;
		while(tar = data.upper_bound(p), (*--tar).second.first != 0){
			(p-=tar->first) %= tar->second.second;
//			cout << "p:" << p << endl;
		}
		cout << (i?" ":"") << tar->second.second;
//		cout << tar->second.second << endl;
	}
	cout << endl;
	
	return 0;
}