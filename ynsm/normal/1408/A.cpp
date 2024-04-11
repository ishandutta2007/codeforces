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
 
int n, a[3][N], p[N];
void solve(){
	scanf("%d", &n);
	for(int j = 0; j < 3; j++)
		for(int i = 0; i < n; i++)
			scanf("%d", &a[j][i]);
	p[0] = a[0][0];
	for(int i = 1; i + 1 < n; i++)
		for(int j = 0; j < 3; j++)
			if(a[j][i] != p[i - 1])
				p[i] = a[j][i];		
	for(int j = 0; j < 3; j++)
		if(a[j][n - 1] != p[0] && a[j][n - 1] != p[n - 2])
			p[n - 1] = a[j][n - 1];
	for(int i = 0; i < n; i++)
		printf("%d ", p[i]);
	printf("\n");
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}