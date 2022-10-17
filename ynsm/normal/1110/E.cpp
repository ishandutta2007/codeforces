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


ll n, a[N], b[N], c[N], d[N];
int main()
{
	scanf("%lld", &n);       

	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for(int i = 0; i <= n; i++)
		c[i] = a[i] - a[i + 1];
	
	for(int i = 1; i <= n; i++)
		scanf("%lld", &b[i]);
	for(int i = 0; i <= n; i++)
		d[i] = b[i] - b[i + 1];
	
	sort(c, c + n);
    sort(d, d + n);
    
    bool ok = (a[1] == b[1] && a[n] == b[n]);
    for(int i = 0; i < n; i++)
    	ok &= (c[i] == d[i]);
	
	if(ok)          
		puts("Yes");
	else
		puts("No");
	return 0;
}