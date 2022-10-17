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
 
string s = "codeforces";
int n = s.size();
ll a[N];
int main(){
	ll x;
	scanf("%lld", &x);
	for(int i = 0; i < n; i++)
		a[i] = 1;
	ll ans = 1;
	int i = 0;
	while(ans < x){
		ans /= a[i];
		a[i]++;
		ans *= a[i];
		i = (i + 1) % n;	
	}
	for(int i = 0; i < n; i++)
		while(a[i]--)
			printf("%c", s[i]);
}