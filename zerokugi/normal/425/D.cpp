#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
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
#define TOLL(x, y) (((ll)x<<20)|(y))


int n;
unordered_set<ll> db;
vector<int> X[100001];
vector<int> Y[100001];

main(){
	scanf("%d", &n);
	ll ans = 0;
	REP(i, n){
		int x, y;
		scanf("%d %d", &x, &y);
		if(X[x].size() < Y[y].size()){
			REP(i, X[x].size()){
				int dy = X[x][i];
				int l = dy - y;
				if(db.count(TOLL(x+l, y)) && db.count(TOLL(x+l, dy))) ans ++;
				if(db.count(TOLL(x-l, y)) && db.count(TOLL(x-l, dy))) ans ++;
			}
		}else{
			REP(i, Y[y].size()){
				int dx = Y[y][i];
				int l = dx - x;
				if(db.count(TOLL(x, y+l)) && db.count(TOLL(dx, y+l))) ans ++;
				if(db.count(TOLL(x, y-l)) && db.count(TOLL(dx, y-l))) ans ++;
			}
		}
		X[x].push_back(y);
		Y[y].push_back(x);
		db.insert(TOLL(x, y));
	}
	cout << ans << endl;
	return 0;
}