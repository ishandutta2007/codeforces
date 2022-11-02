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
	vector<ll> a(2*n+1);
	REP(i, n){
		int x;
		scanf("%I64d", &a[i+1]);
	}
	sort(a.begin()+1, a.end(), greater<ll>());
	scanf("%d", &m);
	REP(i, 2*n){
		a[i+1] += a[i];
	}
	vector<ll> memo(100001, -1);
	REP(i, m){
		int x;
		scanf("%d", &x);
		if(memo[x] == -1){
			ll dep = 0;
			ll w = 1;
			ll r = 0;
			ll sum = 0;
			while(r < n){
				sum += (a[min(r+w, (ll)n)] - a[r]) * dep;
				r += w;
				dep ++;
				w *= x;
			}
			memo[x] = sum;
		}
		cout << memo[x];
		if(i == m-1) cout << endl;
		else cout << " ";
	}
	return 0;
}