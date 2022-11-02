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

int n, m, k;
int used[52][52];
vector< vector<pii> > ans;

vector<pii> make_root(int x, int y){
	vector<pii> ret;
	ret.push_back(pii(x, y));
	while(x) ret.push_back(pii(-- x, y));
	while(y) ret.push_back(pii(x, -- y));
	reverse(ret.begin(), ret.end());
	return ret;
}

int solve(){
	int cost = 0;
	REP(i, 105){
		REP(j, i+1){
			if(j<m && i-j<n && 0<=i-j && 0<=j && !used[j][i-j]){
				ans.push_back(make_root(i-j, j));
				cost += i+1;
				if(-- k == 0) return cost;
			}
		}
	}
	return cost;
}
main(){
	int i,j;
	cin >> n >> m >> k;
	cout << solve() <<endl;
	reverse(ans.begin(), ans.end());
	REP(i, ans.size())REP(j, ans[i].size()) printf("(%d,%d)%s", ans[i][j].first+1, ans[i][j].second+1, j+1==ans[i].size()?"\n":" ");
	return 0;
}