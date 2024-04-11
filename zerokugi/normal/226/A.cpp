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

ll n, m;
ll mod_pow(ll a,ll b,ll M){
	if(b==0)return 1;
	ll res=mod_pow((a*a)%M,b/2,M);
	if(b&1)res=(res*a)%M;
	return res;
}main(){
	cin >> n >> m;
	cout << (mod_pow(3, n, m) - 1 + m) % m << endl;
	return 0;
}