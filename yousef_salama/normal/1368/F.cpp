#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, f[MAXN];

int main(){
	scanf("%d", &n);
	
	int m = 1, mx = 0;
	for(int i = 1; i <= n; i++){
		int cur = n - (n + i - 1) / i - i + 1;
		
		if(cur > mx){
			mx = cur;
			m = i;
		}
	}
	
	int c = 0;
	while(c < mx){
		vector <int> v;
		for(int i = 0; i < n; i++){
			if(i % m != 0 && f[i] == 0){
				f[i] = 1;
				v.push_back(i + 1);
				c++;
			}
		}
		
		printf("%d", (int)v.size());
		for(int i = 0; i < (int)v.size(); i++){
			printf(" %d", v[i]);
		}
		printf("\n");
		fflush(stdout);
		
		int x;
		scanf("%d", &x);
		x--;
		
		for(int i = 0; i < (int)v.size(); i++){
			if(f[(x + i) % n] == 1){
				f[(x + i) % n] = 0;
				c--;
			}
		}
	}
	printf("0\n");
	
	return 0;
}