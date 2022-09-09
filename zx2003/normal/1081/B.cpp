#include<bits/stdc++.h>
const int N=1e5+5;
int n,a[N],i,j,k,x,b[N];
std::vector<int>ve[N];
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i),ve[a[i]].push_back(i);
	for(i=0;i<n;++i)if(ve[i].size()%(n-i)!=0){puts("Impossible");return 0;}
	for(i=0;i<n;++i)for(j=0;j<ve[i].size();j+=n-i)
		for(++x,k=0;k<n-i;++k)b[ve[i][j+k]]=x;
	puts("Possible");
	for(i=1;i<=n;++i)printf("%d%c",b[i],i==n?'\n':' ');
}