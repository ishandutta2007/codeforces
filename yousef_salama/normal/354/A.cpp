#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, a[MAXN], l, r, Ql, Qr;
int main(){
	scanf("%d %d %d %d %d", &n, &l, &r, &Ql, &Qr);

	int p = 0, q = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		p += a[i];
	}

	int res = 2000000000;
	for(int i = 0; i <= n; i++){
		int x = i, y = n - i;
		if(x < y){
			res = min(res, p * r + q * l + (y - x - 1) * Qr);
		}else if(x == y){
			res = min(res, p * r + q * l);
		}else{
			res = min(res, p * r + q * l + (x - y - 1) * Ql);
		}

		if(i < n){
			p -= a[i];
			q += a[i];
		}
	}
	printf("%d\n", res);

	return 0;
}