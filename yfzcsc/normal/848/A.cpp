#include<bits/stdc++.h>
using namespace std;
int f[1000],n,tp;
void dfs(char c,int cost,int p){
	if(!cost)return ;
//	printf("[%d,%d]",cost,p);
	for(int i=p;i>=1;--i)if(cost>=f[i]){
		dfs(c+1,cost-f[i],i);
		for(int j=1;j<=i+1;++j)putchar(c);
		break;
	}
}
int main(){
	scanf("%d",&n);
	if(!n)return puts("a"),0;
	for(tp=1;tp*(tp+1)/2<=n;tp++)
		f[tp]=tp*(tp+1)/2;
	dfs('a',n,tp-1);
}