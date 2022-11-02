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

int n, m;
int row[5000][5000];
char s[5001];
main(){
	int i,j;
	while(cin >> n >> m){
		REP(y, n){
			scanf(" %s", s);
			int c = 0;
			int x = 0;
			while(s[++x]);
			while(--x>=0){
				if(s[x] == '1') c ++;
				else c = 0;
				row[x][y] = c;
			}
		}
		int ans = 0;
		
		REP(x, m){
			sort(row[x], row[x] + n, greater<int>());
			REP(y, n){
				if(ans < (y+1)*row[x][y]) ans = (y+1)*row[x][y];
			}
		}
		cout << ans << endl;
	}
	return 0;
}