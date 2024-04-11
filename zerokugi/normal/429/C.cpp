#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
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

bool check(vector<int> P){
//	REP(i, P.size()) printf("%d ", P[i]);
//	puts("");

	stack<pii> st;
	st.push(pii(P[0], 0));
	int p = 1;
	while(!st.empty() && p<P.size()){
//		printf("%d %d %d\n", p, st.top().first, st.top().second);
		if(st.top().first-st.top().second <= P[p]){
			if(P.back()) return false;
			P.insert(P.begin()+p, 0);
			P.pop_back();
		}
		if(!st.top().second && st.top().first == P[p]+1) return false;
		st.top().second += P[p]+1;
		st.push(pii(P[p], 0));
		while(!st.empty() && st.top().first-st.top().second == 0){
			st.pop();
		}
		p++;
	}
//		printf("%d %d\n", p, P.size());
	while(!st.empty() && st.top().first-st.top().second == 0){
		st.pop();
	}
	return (p == P.size() && st.empty());
}

main(){
	scanf("%d", &n);
	vector<int> g(n);
	REP(i, n){
		scanf("%d", &g[i]);
		g[i] --;
	}
	sort(g.rbegin(), g.rend());
	int t=0;
	for(;t<n;t++) if(!g[t]) break;
	if(t < 1){
		if(g[t] == 0){
			puts("YES");
			return 0;
		}
	}else if(t <= 11){
		sort(g.begin()+1, g.begin()+t);
		do{
			if(check(g)){
				puts("YES");
				return 0;
			}
		}while(next_permutation(g.begin()+1, g.begin()+t));
	}
	puts("NO");
	return 0;
}