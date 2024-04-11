#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	
	vector <int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
		
	vector <long long> d(n);
	long long dpos = 0;
	
	d[0] = a[0];
	for(int i = 1; i < n; i++){
		d[i] = a[i] - a[i - 1];
		dpos += max(0LL, d[i]);
	}
	
	printf("%lld\n", max((d[0] + dpos) / 2, (d[0] + dpos) - (d[0] + dpos) / 2));
		
	int q;
	scanf("%d", &q);
	
	while(q--){
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		l--, r--;
		
		if(l > 0)dpos += max(0LL, d[l] + x) - max(0LL, d[l]);
		d[l] += x;
		
		if(r + 1 < n){
			dpos += max(0LL, d[r + 1] - x) - max(0LL, d[r + 1]); 
			d[r + 1] -= x;
		}
		
		printf("%lld\n", max((d[0] + dpos) / 2, (d[0] + dpos) - (d[0] + dpos) / 2));
	}
	return 0;
}