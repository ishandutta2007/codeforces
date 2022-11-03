#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fbo find_by_order
#define ook order_of_key
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define MOD 1000000007 
#define MID (l+r)/2
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mx 700003
#define pc(x) putchar_unlocked(x);
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

string ss;

int main(){
	int n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> ss;
	n = sz(ss);
	int lo = 0, hi = 1e9, ans = 1e9, mid;
	while(lo <= hi){
		mid = (lo + hi) >> 1;
		string sisa = "";
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(ss[i] == '('){
				if(cnt + 1 > mid)
					sisa += ss[i];
				else cnt++;
			}
			else{
				if(cnt == 0)
					sisa += ss[i];
				else cnt --;
			}
		}
		int hit = 0;
		bool ya = true;
		for(auto i : sisa){
			if(i == '('){
				hit ++;
				if(hit > mid)
					ya = false;
			}
			else hit --;
		}
		if(ya){
			hi = mid - 1;
			ans = mid;
		}
		else lo = mid + 1;
	}
	mid = ans;
	// debug(ans);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(ss[i] == '('){
			if(cnt + 1 > mid)
				cout << 0;
			else{
				cout << 1;
				cnt ++;
			}
		}
		else{
			if(cnt == 0)
				cout << 0;
			else{
				cout << 1;
				cnt --;
			}
		}
	}
}