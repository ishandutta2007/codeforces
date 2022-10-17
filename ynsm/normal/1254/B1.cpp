#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1000500;

int n, a[N], b[N], k;
ll s, ans = 1e18;
pii c[N];

ll get(){
	ll s = 0;
	for(int i = 0; i < k; i++)
		s += c[i].s;
	ll ss = 0;
	for(int i = 0; i < k; i++){
		ss += c[i].s;
		if(ss + ss > s){
			ll res = 0;
			for(int j = 0; j < k; j++)
				res += 1ll * abs(c[i].f - c[j].f) * c[j].s;
			k = 0;				 
			return res;
		}
	}
}
ll ff(ll x){
	for(int i = 0; i < n; i++)
		b[i] = a[i] % x;
	ll cur = 0;
	k = 0;
	ll res = 0;
	for(int i = 0; i < n; i++){
		if(cur + b[i] < x){
			c[k++] = {i, b[i]};
			cur += b[i];
		    continue;
		}	
		c[k++] = {i, x - cur};
		res += get();
        cur = cur + b[i] - x;
		c[k++] = {i, cur};			
	}
	return res;	
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		s += a[i];
	}
	if(s == 1){
		printf("-1");
		return 0;
	}
	for(int i = 2; 1ll * i * i <= s; i++){
		if(s % i == 0){
			ans = min(ans, ff(i));
			while(s % i == 0)
				s /= i;
		}
	}
	if(s > 1)                     
		ans = min(ans, ff(s));	
	printf("%lld", ans);
	return 0;
}