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
#define mp(a, b) make_pair(a, b)
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
main(){
	cin >> n;
	double mx = 0;
	vector<double> d;
	REP(i, n){
		double x;
		cin >> x;
		mx = max(mx, x);
		if(x<0.5) d.push_back(x);
	}
	sort(d.rbegin(), d.rend());
	pair<double, int> ans(0.0, 0);
	REP(i, d.size()){
		double sump = 0;
		REP(j, i+1){
			double p = 1;
			REP(k, i+1){
				if(j == k){
					p *= d[k];
				}else{
					p *= 1-d[k];
				}
			}
			sump += p;
		}
//		cout << i << ", " << sump << endl;
		ans = max(ans, pair<double, int>(sump, i));
	}
//	cout << ans.first << ", " << ans.second << endl;
	printf("%.10f\n", max(mx, ans.first));
	return 0;
}