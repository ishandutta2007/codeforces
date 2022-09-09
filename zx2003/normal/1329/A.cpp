#include<bits/stdc++.h>
const int N=1e5+5;
void E(){puts("-1");exit(0);}
int n,m,i,j,l[N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d",l+i);
	for(i=1;i<=m;++i)if(l[i]+i-1>n)E();
	long long tot=0;
	for(i=1;i<=m;++i)tot+=l[i];if(tot<n)E();
	for(i=1;i<=m;++i){
		++j;
		for(;n-j+1>tot;++j);
		printf("%d%c",j,i==m?'\n':' ');
		tot-=l[i];
	}
}