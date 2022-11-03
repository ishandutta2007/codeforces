// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
#define mx 500003
#define pc(x) putchar_unlocked(x);
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int ans, a[mx], maks[mx], awal[mx], n;

void dnc(int l, int r){
	// cout << l << ' ' << r << endl;
	if(r - l <= 1){
		if(r - l == 0){
			if(a[l] == 1)
				ans ++;
		}
		else if(r - l == 1){
			if(a[l] == 1)
				ans ++;
			if(a[r] == 1)
				ans ++;
			if(a[l] == 1 && a[r] == 2)
				ans ++;
			if(a[l] == 2 && a[r] == 1)
				ans ++;
		}
		return;
	}
	int mid = (l + r) >> 1;
	for(int i = l; i <= r; i++)
		awal[a[i]] = -1;
	for(int i = mid; i <= r; i++){
		if(awal[a[i]] == -1)
			awal[a[i]] = i;
		if(i == mid)
			maks[i] = a[mid];
		else maks[i] = max(maks[i - 1], a[i]);
	}
	int sampai = r;
	for(int i = mid; i <= r; i++){
		if(awal[a[i]] != i){
			sampai = i - 1;
			break;
		}
	}
	for(int i = mid; i <= sampai; i++){
		if(maks[i] == i - mid + 1)
			// debug(i),
			// cout << mid << " -> " << i << endl,
			ans ++;
	}
	for(int i = mid - 1; i >= l; i--){
		maks[i] = max(maks[i + 1], a[i]);
		if(awal[a[i]] == -1){
			awal[a[i]] = i;
		}
		else if(awal[a[i]] > mid){
			sampai = min(sampai, awal[a[i]] - 1);
			awal[a[i]] = i;
		}else{
			break;
		}
		int now = i + maks[i] - 1;
		while(now <= sampai){
			int MAX = max(maks[i], maks[now]);
			if(MAX == now - i + 1){
				ans ++;
				// cout << i << " -> " << now << endl;
				now ++;
			}
			else{
				now = i + MAX - 1;
			}
		}
	}
	dnc(l, mid - 1);
	dnc(mid + 1, r);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	dnc(1, n);
	cout << ans << '\n';
}