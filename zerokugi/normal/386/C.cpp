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

char str[300005];
vector<int> idx[27];
main(){
	int x;
	scanf("%s", str);
	int n = strlen(str);
	REP(i, n){
		idx[str[i]-'a'].push_back(i);
	}
	ll ans[27] = {0};
	int ansmax = 0;
	REP(i, n){
		set<int> fir;
		REP(j, 26){
			vector<int>::iterator it = lower_bound(idx[j].begin(), idx[j].end(), i);
			if(it != idx[j].end()) fir.insert(*it);
		}
		int p = i;
		int c = 0;
//		cout << "i=" << i << endl;
		FOR(it, fir){
//			cout << *it << endl;
			ans[c++] += *it-p;
			p = *it;
		}
		ans[c] += n-p;
		ansmax = max(ansmax, c);
	}
	cout << ansmax << endl;
	REP(i, ansmax) cout << ans[i+1] << endl;
	return 0;
}