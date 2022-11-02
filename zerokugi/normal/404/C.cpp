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

int n, k, x;
main(){
	scanf("%d%d", &n, &k);
	map< int, vector<int> > v;
	int m=0;
	REP(i, n){
		scanf("%d", &x);
		v[x].push_back(i+1);
		m = max(m, x);
	}
	int f = 0;
	REP(i, m) if(v[i].size() == 0 || (v[i+1].size()+v[i].size()-1)/v[i].size() > k - !!i) f = 1;
	if(f || v[0].size() != 1) puts("-1");
	else{
		printf("%d\n", n-1);
		for(int i=1;v[i].size()!=0;i++){
			int j=0;
			FOR(it, v[i]){
				printf("%d %d\n", v[i-1][j++], *it);
				if(j == v[i-1].size()) j = 0;
			}
		}
	}
	return 0;
}