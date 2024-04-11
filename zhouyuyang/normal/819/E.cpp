#include<bits/stdc++.h>
using namespace std;
int sum[100005];
int e[100005][6];
int tot,n;
void work(int n){
	if (n==3){
		sum[++tot]=3;
		e[tot][1]=1;
		e[tot][2]=2;
		e[tot][3]=3;
		sum[++tot]=3;
		e[tot][1]=1;
		e[tot][2]=2;
		e[tot][3]=3;
		return;
	}
	if (n==4){
		sum[++tot]=3;
		e[tot][1]=1;
		e[tot][2]=2;
		e[tot][3]=3;
		sum[++tot]=3;
		e[tot][1]=1;
		e[tot][2]=2;
		e[tot][3]=4;
		sum[++tot]=3;
		e[tot][1]=1;
		e[tot][2]=3;
		e[tot][3]=4;
		sum[++tot]=3;
		e[tot][1]=2;
		e[tot][2]=3;
		e[tot][3]=4;
		return;
	}
	sum[++tot]=3;
	e[tot][1]=1;
	e[tot][2]=n;
	e[tot][3]=n-1;
	sum[++tot]=3;
	e[tot][1]=1;
	e[tot][2]=n;
	e[tot][3]=n-1;
	for (int i=2;i<=n-2;i++){
		int nxt=(i==n-2?2:i+1);
		sum[++tot]=4;
		e[tot][1]=n;
		e[tot][2]=i;
		e[tot][3]=n-1;
		e[tot][4]=nxt;
	}
	work(n-2);
}
int main(){
	scanf("%d",&n);
	work(n);
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++){
		printf("%d",sum[i]);
		for (int j=1;j<=sum[i];j++)
			printf(" %d",e[i][j]);
		puts("");
	}
}