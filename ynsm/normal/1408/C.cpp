#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, d, a[N];
void solve(){
	scanf("%d%d", &n, &d);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	double L = 0, R = d, ans = 0;
	int x = 1, y = 1;
	int l = 0, r = n - 1;
	while(l <= r){
		if((a[l] - L) / x < (R - a[r]) / y){
			double t = (a[l] - L) / x;
			ans += t;
			L += x * t;
			R -= y * t;
			l++;
			x++;			
		}else{
			double t = (R - a[r]) / y;
			ans += t;
			L += x * t;
			R -= y * t;
			r--;
			y++;			
		}		
	}	
	ans += (R - L) / (x + y);
	printf("%.9f\n", ans);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}