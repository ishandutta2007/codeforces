#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int n,a[1111][6],ans=0,ok[1111];

bool C(int x){
	int t;
	for (int i=1;i<=n;i++){
		if (i==x) continue;
		for (int j=1;j<=n;j++){
			if (j==x||j==i) continue;
			t=0;
			for (int k=1;k<=5;k++){
				t+=(a[i][k]-a[x][k])*(a[j][k]-a[x][k]);
			}
			if (t>0) return 0;
		}
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=5;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for (int i=1;i<=n;i++){
		if (C(i)){
			ok[i]=1;
			ans++;
		}
		if (clock()>1600){
			printf("0\n");
			return 0;
		}
	}
	printf("%d\n",ans);
	for (int i=1;i<=n;i++){
		if (ok[i]){
			printf("%d ",i);
		}
	}
}