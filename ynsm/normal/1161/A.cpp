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

int n, k, a[N], b[N], ans;
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		a[i] = k + 1, b[i] = 0;
	for(int i = 1; i <= k; i++){
		int x;
		scanf("%d", &x);
		if(a[x] == k + 1)
			a[x] = i;
		b[x] = i;		
	}                          
	for(int i = 1; i <= n; i++)
		if(a[i] > b[i])
			ans++;       
	for(int i = 1; i + 1 <= n; i++)
		if(a[i] > b[i + 1])
			ans++;
	for(int i = 1; i + 1 <= n; i++)
		if(a[i + 1] > b[i])
			ans++;
	printf("%d", ans);
	return 0;
}