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
#define mx 3000003
#define pc(x) putchar_unlocked(x);
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

long long t, n, p[mx], cnt[mx], a[mx];

int main(){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	for(long long i = 2; i <= 2e6; i++){
		if(!p[i])
			for(long long j = i; j <= 2e6; j += i)
				if(!p[j])
					p[j] = i;
	}
	long long t;
	cin >> t;
	while(t --){
		cin >> n;
		set<long long> FF;
		long long N = 1;
		for(long long i = 1; i <= n; i++){
			long long x;
			cin >> x;
			a[i] = x;
			while(x > 1){
				long long fak = p[x], hit = 0;
				while(x % fak == 0){
					x /= fak;
					hit ++;
				}
				if(hit > cnt[fak]){
					cnt[fak] = hit;
				}
				FF.insert(fak);
			}
		}
		long long fak = 1;
		if(sz(FF) == 1){
			for(long long i : FF)
				cnt[i] ++;
		}
		bool ya = true;
		int nn = n + 2;
		for(long long i = 1; i <= 2e6; i++){
			if(nn % (cnt[i] + 1) == 0)
				nn /= cnt[i] + 1;
			else ya = false;
		}
		if(ya){
			for(long long i = 1; i <= 2e6; i++){
				for(int j = 1; j <= cnt[i]; j++)
					N = N * i;
				cnt[i] = 0;
			}
			for(int i = 1; i <= n; i++){
				if(N % a[i] > 0)
					ya = false;
			}
			sort(a + 1, a + n + 1);
			long long NN = a[1] * a[n];
			bool ya = true;
			for(int i = 1; i <= n; i++){
				if(a[i] * a[n - i + 1] != NN){
					ya = false;
				}
			}
			if(!ya || NN != N){
				cout<<-1<<endl;
			}
			else cout << N << endl;
		}
		else cout << -1 << endl;
		for(long long i = 1; i <= 2e6; i++){
			cnt[i] = 0;
		}

	}
}