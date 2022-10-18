#include <bits/stdc++.h>
using namespace std;

const int MAXN = 35;

int n, L;
long long c[MAXN];

int main(){
	scanf("%d %d", &n, &L);
	for(int i = 0; i < n; i++)
		scanf("%lld", &c[i]);

	for(int i = 1; i < n; i++)
		c[i] = min(c[i], 2 * c[i - 1]);
	for(int i = n; i <= 30; i++)
		c[i] = 2 * c[i - 1];
	
	long long res = 1LL << 60, cur = 0;
	for(int i = 30; i >= 0; i--){
		if(L >= (1LL << i)){
			cur += c[i];
			L -= 1LL << i;
		}else{
			res = min(res, cur + c[i]);
		}
	}
	res = min(res, cur);
	
	printf("%lld\n",  res);
	
	return 0;
}