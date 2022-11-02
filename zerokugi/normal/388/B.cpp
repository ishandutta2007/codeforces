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
int g[1001][1001];

void addEdge(int s, int t){
//	printf("add %d-%d\n", s, t);
	if(s > 1001 || t > 1001){
		printf("%d , %d add\n", s, t);
		exit(0);
	}
	g[s][t] = g[t][s] = 1;
}

main(){
	int i,j;
	while(cin >> n){
		REP(i, 1000)REP(j, 1000) g[i][j] = 0;
		vector<int> facts;
		for(int i=0;i<=29;i++){
			if(n&(1<<i)) facts.push_back(i);
		}
		int maxdist = facts[facts.size()-1];
//		REP(i, facts.size()) cout << facts[i] << " ";
//		cout << endl;
		int used = 3;
		addEdge(0, 2);
		REP(i, 30){
			if(i == 0){
				addEdge(2, used);
				addEdge(2, used + 1);
			}else{
				addEdge(used-2, used);
				addEdge(used-1, used);
				addEdge(used-2, used + 1);
				addEdge(used-1, used + 1);
			}
			if(i+1 == 30){
				addEdge(used, 1);
				addEdge(used + 1, 1);
			}
			used += 2;
		}
		REP(i, facts.size()){
			addEdge(0, used++);
			REP(j, 29 - facts[i]){
				addEdge(used-1, used);
				used ++;
			}
			if(facts[i]){
				addEdge(used -1, 63 - facts[i]*2);
				addEdge(used -1, 63 - facts[i]*2+1);
			}else addEdge(used -1, 1);
		}
		printf("%d\n", used);
		REP(i, used){
			REP(j, used) putchar(g[i][j] ? 'Y':'N');
			puts("");
		}
	}
	return 0;
}