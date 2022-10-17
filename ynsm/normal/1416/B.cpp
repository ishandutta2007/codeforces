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

int n, m, a[N], s, k; 
pair<pii, int > ans[N];
void f(int i, int j, int x){
	a[i] -= i * x;
	a[j] += i * x;
	ans[m++] = {{i, j}, x};
}
void solve(){
	m = 0;
	s = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		s += a[i];
	}
	if(s % n != 0){
		printf("-1\n");
		return;
	}
	k = s / n;
	for(int i = 2; i <= n; i++){
		int need = (i - a[i] % i) % i;
		f(1, i, need);
		f(i, 1, a[i] / i);
	}
	for(int i = 2; i <= n; i++)
		f(1, i, k);	
	printf("%d\n", m);
	for(int i = 0; i < m; i++)
		printf("%d %d %d\n", ans[i].f.f, ans[i].f.s, ans[i].s);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}