#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

const int maxn = 1e6 + 5;

int g[maxn];

int cal(int n){
	int temp[10];
	int tot = 0;
	while(n > 0){
		temp[++tot] = n % 10;
		n /= 10;
	}
	int ans = 1;
	for(int i = 1;i <= tot;i++){
		if(temp[i] != 0)
			ans = ans * temp[i];
	}
	return ans;
}

void init(){
	for(int i = 1;i < maxn;i++){
		if(i < 10) g[i] = i;
		else{
			g[i] = g[cal(i)];
		}
	}
}

int pre[maxn][10];

int main(){
	init();
	for(int i = 1;i < maxn;i++){
		for(int j = 1;j <= 9;j++){
			pre[i][j] = pre[i - 1][j];
		}
		pre[i][g[i]]++;
	}	
	int Q;
	cin >> Q;
	for(int i = 1;i <= Q;i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",pre[r][k] - pre[l - 1][k]);
	}
	return 0;
}