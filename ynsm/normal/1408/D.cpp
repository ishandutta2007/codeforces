#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 2010, inf = 1e9;
 
int n, m, a[N], b[N], ans;
pii vx[N * N], vy[N * N]; 
bool was[N * N];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &a[i], &b[i]);
	for(int j = 0; j < m; j++){
		int x, y;
		scanf("%d%d", &x, &y);
		for(int i = 0; i < n; i++){       
			int dx = max(0, x - a[i] + 1);
			int dy = max(0, y - b[i] + 1);
			vx[j * n + i] = {dx, j * n + i};
			vy[j * n + i] = {dy, j * n + i};
		}
	}                    
	sort(vx, vx + n * m);
	sort(vy, vy + n * m);
	
	ans = vy[n * m - 1].f;
	for(int i = 0, j = n * m - 1; i < n * m; i++){
		was[vx[i].s] = 1;		
		while(j >= 0 && was[vy[j].s])
			j--;
		if(j >= 0)                        
			ans = min(ans, vx[i].f + vy[j].f);
		else
			ans = min(ans, vx[i].f); 
	}
	printf("%d", ans);
}