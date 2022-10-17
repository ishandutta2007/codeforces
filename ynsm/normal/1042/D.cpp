#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
ll n, a[N], ans, t;

void solve(int l, int r){
	if(l > r)
		return ;			
	int m = (l+r)/2;
	ll x = a[m];
	vector< ll > vl,vr;
	for(int i = m - 1; i >= l; i--){
		x+=a[i];
		vl.pb(x);
		if(x < t)
			ans++;
	}
	x = a[m];

	for(int i = m + 1; i <= r; i++){
		x+=a[i];
		vr.pb(x);
		if(x < t)
			ans++;
	}                         
	if(a[m] < t)
		ans++;
	
	sort(vl.begin(),vl.end());
	sort(vr.begin(),vr.end());
	
	for(int i = 0, j = vr.size() - 1; i < vl.size() ;i++){
		while( j>=0 && vl[i] + vr[j] - a[m]>= t )
			j--;
		ans+=j+1;
	}
	solve(l,m-1);
	solve(m+1,r);
}
int main(){    
    cin >> n >> t;
    for(int i = 0; i < n; i++)
    	cin >> a[i];
	solve(0, n - 1);
	cout << ans;
	return 0;
}