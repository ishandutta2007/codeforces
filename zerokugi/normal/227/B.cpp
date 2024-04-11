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
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define RFOR(i,c) for(auto i=(c).rbegin();i!=(c).rend();++i)
#define ALL(container) container.begin(), container.end()
#define SZ(container) ((int)container.size())

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n, m;
main(){
	scanf("%d", &n);
	vector<int> pos(n);
	REP(i, n){
		int x;
		scanf("%d", &x);
		pos[x-1] = i;
	}
	ll lsum = 0, rsum = 0;
	scanf("%d", &m);
	REP(i, m){
		int x;
		scanf("%d", &x);
		lsum += pos[x-1] + 1;
		rsum += n - pos[x-1];
	}
	cout << lsum << " " << rsum << endl;
	return 0;
}