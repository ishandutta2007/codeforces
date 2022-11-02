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
main(){
	scanf("%d%d", &n, &k);
	vector<int> d(n);
	REP(i, n) scanf("%d", &d[i]);
	int ans = -1000;
	REP(i, n+1)REP(j, i){ // [j, i)
		priority_queue<int> in;
		priority_queue<int> out;
		REP(x, n){
			if(j <= x && x < i) in.push(d[x]);
			else out.push(d[x]);
		}
		REP(x, k){
			if(out.empty()) break;
			in.push(out.top());
			out.pop();
		}
		int sum=0;
		REP(x, i-j){
			sum += in.top();
			in.pop();
		}
		ans = max(sum, ans);
	}
	printf("%d\n", ans);
	return 0;
}