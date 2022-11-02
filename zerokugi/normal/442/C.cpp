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
const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
main(){
	scanf("%d", &n);
	int incp = 2;
	vector<int> st;
	st.push_back(0);
	st.push_back(0);
	ll ans = 0;
	REP(i, n){
		int x;
		scanf("%d", &x);
		if(st.size() == incp){
			if(st.back() <= x) incp++;
			st.push_back(x);
		}else{
			if(st.back() >= x) st.push_back(x);
			else{
				while(st.size() > incp){
					if(st.back() < x){
						st.pop_back();
						ans += min(x, st.back());
//						cout << st.back() << ", " << x << endl;
					}else break;
				}
				if(st.size() == incp){
					if(st.back() <= x) incp++;
				}
				st.push_back(x);
			}
		}
	}
	st.push_back(0);
	st.push_back(0);
//	cout << ans << endl;
//	cout << st << endl;
	int t = max_element(ALL(st)) - st.begin();
	if(st[t] != 0){
		int l=t-1,r=t+1;
		while(st[l] || st[r]){
			int a = st[l] + st[r];
			int b = st[l-1] + st[l];
			int c = st[r] + st[r+1];
			if(a>b && a>c){
				if(st[l] < st[r]){
					ans += st[l];
					r++;
				}else{
					ans += st[r];
					l--;
				}
			}else if(b>c){
				ans += st[--l];
			}else{
				ans += st[++r];
			}
		}
	}
	cout << ans << endl;
	return 0;
}