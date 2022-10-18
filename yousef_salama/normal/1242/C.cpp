#include <bits/stdc++.h>
using namespace std;

const int MAXK = 20;
const int MAXN = 5005;

int k, n[MAXK], a[MAXK][MAXN];
long long s[MAXK];

map <long long, int> mp;

bool good[1 << 15], dp[1 << 15];
int par[1 << 15], sti[1 << 15], stj[1 << 15];

long long res[MAXK];
int indres[MAXK];

int main(){
	scanf("%d", &k);
	
	long long sum = 0;
	for(int i = 0; i < k; i++){
		scanf("%d", &n[i]);
		
		s[i] = 0;
		for(int j = 0; j < n[i]; j++){
			scanf("%d", &a[i][j]);
			sum += a[i][j];
			
			s[i] += a[i][j];
		}
	}
	
	if(sum % k != 0){
		printf("No\n");
		return 0;
	}
	sum /= k;
	
	for(int i = 0; i < k; i++)
	for(int j = 0; j < n[i]; j++){
		mp[a[i][j]] = i;
	}
	
	for(int i = 0; i < k; i++){
		for(int j = 0; j < n[i]; j++){
			int mask = (1 << i), u = i;
			long long b = sum - s[i] + a[i][j];
			
			bool ok = true;
			while(true){
				mask |= (1 << u);
				
				if(!mp.count(b)){
					ok = false;
					break;
				}
				
				u = mp[b];
				
				if(mask & (1 << u)){
					if(u != i || b != a[i][j])ok = false;
					break;
				}
				
				b = sum - s[u] + b;
			}
			
			if(ok){
				good[mask] = true;
				sti[mask] = i;
				stj[mask] = j;
			}
		}
	}
	
	for(int mask = 0; mask < (1 << k); mask++){
		if(mask == 0)dp[mask] = true;
		else{
			dp[mask] = false;
			for(int sub = mask; sub > 0; sub = (sub - 1) & mask)if(good[sub] && dp[mask ^ sub]){
				dp[mask] = true;
				par[mask] = sub;
			}
		}
	}
	
	if(!dp[(1 << k) - 1]){
		printf("No\n");
		return 0;
	}
	
	printf("Yes\n");
	
	int mask = (1 << k) - 1;
	while(mask > 0){
		int sub = par[mask];
		
		int i = sti[sub], j = stj[sub];
		
		int u = i;
		long long b = sum - s[i] + a[i][j];
		
		while(true){
			int nxt = mp[b];
			
			res[nxt] = b;
			indres[nxt] = u;
			
			u = nxt;
			b = sum - s[u] + b;
			
			if(u == i)break;
		}
		
		mask ^= sub;
	}
	
	for(int i = 0; i < k; i++)
		printf("%lld %d\n", res[i], indres[i] + 1);
	
	return 0;
}