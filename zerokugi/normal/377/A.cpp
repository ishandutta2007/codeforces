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

int h,w,k;
char m[1000][1000];
int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};


void dfs(int x, int y, int &k){
	if(!k || m[y][x] != 'X') return;
	m[y][x] = '.';
	k --;
	REP(i, 4) dfs(x+d[i][1], y+d[i][0], k);
}

main(){
	int i,j;
	
	while(cin >> h >> w >> k){
		int n=0;
		REP(i, h){
			cin >> &m[i+1][1];
			REP(j, w){
				if(m[i+1][j+1] == '.'){
					n ++;
					m[i+1][j+1] = 'X';
				}
			}
		}
		k = n-k;
		REP(i, h)REP(j, w) dfs(j+1, i+1, k);
		REP(i, h) cout << &m[i+1][1] << endl;
		cout << endl;
	}
	return 0;
}