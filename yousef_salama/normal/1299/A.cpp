#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, a[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
		
	for(int j = 30; j >= 0; j--){
		int cnt = 0, ind = -1;
		for(int i = 0; i < n; i++){
			if(a[i] & (1 << j)){
				cnt++;
				ind = i;
			}
		}
		
		if(cnt == 1){
			swap(a[ind], a[0]);
			break;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(i > 0)printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	
	return 0;
}