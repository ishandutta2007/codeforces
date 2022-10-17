#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 5050, mod = 1e9 + 7;
 
int n, m, k;
vector< int > v[N];
int a[N], b[N], c[N];
int A[N], B[N], AB[N], p2[N];
ll mx, ans = 1;
void f(ll &x, ll &y, ll a, ll b){
	if(b == 0)
		return;
	if(x < a)
		x = a, y = 0;
	if(x == a)
		y += b;
}
int main()
{
	p2[0] = 1;
	for(int i = 1; i < N; i++)
		p2[i] = p2[i - 1] * 2 % mod;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
	    int x;
		scanf("%d", &x);
		v[x].pb(i);
	}
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		if(y <= v[x].size()){
			a[k] = v[x][y - 1];
			b[k] = v[x][v[x].size() - y];	
			c[k] = x - 1;
			k++;
		}else{
			i--, m--;
		}
	}
	for(int i = 0; i < k; i++){
    	for(int j = 0; j < n; j++){
    		A[j] = 0;
    		B[j] = 0;
    		AB[j] = 0;
    	}
    	for(int j = 0; j < k; j++){
    		if(i == j)
    			continue;
    		if(a[j] < a[i] && b[j] > a[i])
    			AB[c[j]]++;
    		else if(a[j] < a[i])
    			A[c[j]]++;
    		else if(b[j] > a[i])
    			B[c[j]]++;
    	}
    	ll cur = 1;
    	ll cnt = 1;
    	
    	for(int j = 0; j < n; j++){
    		if(j == c[i]){
    			ll x = 0, y = 1;
    			f(x, y, 1, B[j] + AB[j]);
    			cur += x;
    			cnt = cnt * y % mod;
    		}else{
    			ll x = 0, y = 1;
    			f(x, y, 1, A[j] + AB[j]);
    			f(x, y, 1, B[j] + AB[j]);
    			f(x, y, 2, A[j] * AB[j]);
    			f(x, y, 2, B[j] * AB[j]);
    			f(x, y, 2, A[j] * B[j]);
    			f(x, y, 2, AB[j] * (AB[j] - 1));
    			cur += x;
    			cnt = cnt * y % mod;
    		}
    	}
    	if(cur > mx)
    		mx = cur, ans = 0;
    	if(cur == mx)
    		ans = (ans + cnt) % mod;
    }
    for(int i = 0; i < k; i++){
		for(int j = 0; j < n; j++){
    		A[j] = 0;
    		B[j] = 0;
    		AB[j] = 0;
    	}
    	for(int j = 0; j < k; j++){
    		if(i == j)
    			continue;
    		if(a[j] < b[i] && b[j] > b[i])
    			AB[c[j]]++;
    		else if(a[j] < b[i])
    			A[c[j]]++;
    		else if(b[j] > b[i])
    			B[c[j]]++;
    	}
    	ll cur = 1;
    	ll cnt = 1;
    	
    	for(int j = 0; j < n; j++){
    		if(j == c[i]){
    		
    		}else{
    			ll x = 0, y = 1;
    			f(x, y, 1, B[j] + AB[j]);
    			cur += x;
    			cnt = cnt * y % mod;
    		}
    	}
    	if(cur > mx)
    		mx = cur, ans = 0;
    	if(cur == mx)
    		ans = (ans + cnt) % mod;
    }
    printf("%lld %lld", mx, ans);
}