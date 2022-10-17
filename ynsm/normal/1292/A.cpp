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
 
int n, q, cnt[2][N], ans;
int main()
{
	scanf("%d%d", &n, &q);
	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		if(cnt[x][y]){
			if(cnt[x ^ 1][y])
				ans--;	
			if(cnt[x ^ 1][y - 1])
				ans--;	
			if(cnt[x ^ 1][y + 1])
				ans--;	
		}else{
			if(cnt[x ^ 1][y])
				ans++;	
			if(cnt[x ^ 1][y - 1])
				ans++;	
			if(cnt[x ^ 1][y + 1])
				ans++;	
		}
		cnt[x][y] ^= 1;
		if(ans)
			puts("NO");
		else
			puts("YES");	
	}
}