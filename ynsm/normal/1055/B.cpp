#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

int n, q, l, ans, a[N];
int main(){
	scanf("%d%d%d", &n, &q, &l);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] >  l)
			ans++;
	}
	for(int i = 1; i < n; i++)
		if(a[i] > l && a[i + 1] > l)
			ans--;
	for(int i = 1; i <= q; i++){
		int t, p, x;
		scanf("%d", &t);
		if(t){
			scanf("%d%d", &p, &x);
			if(a[p] > l)
				continue;
			a[p] += x;          
			if(a[p] > l)
				ans++;
			if(p < n && a[p] > l && a[p + 1] > l)
				ans--;
			if(p > 1 && a[p] > l && a[p - 1] > l)
				ans--;
		}else
			printf("%d\n", ans);
	}

	return 0;
}