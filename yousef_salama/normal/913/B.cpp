#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, c[MAXN], l[MAXN], p[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d", &p[i]);
		p[i]--;
		
		c[p[i]]++;
	}
	
	for(int i = 0; i < n; i++){
		if(c[i] == 0){
			l[p[i]]++;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(c[i] > 0 && l[i] < 3){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	
	return 0;
}