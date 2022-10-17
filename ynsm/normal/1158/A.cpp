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

int n, m, a[N], b[N];
ll s;
int main()
{
	scanf("%d%d", &n, &m); 
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	sort(a, a + n);
	sort(b, b + m);   
	
	if(a[n - 1] > b[0]){
		printf("-1");
		return 0;
	}

    for(int i = 0; i + 1 < n; i++)
		s += 1ll * a[i] * m;
	for(int i = 0; i < m; i++)
		s += b[i];
	if(a[n - 1] < b[0])
    	s = s + a[n - 1] - a[n - 2];
	printf("%lld", s);
	return 0;
}