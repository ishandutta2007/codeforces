#include<cstdio>
#include<algorithm>
int n,i,fa[200010],k,d[200010];
int main(){
	scanf("%d%d",&n,&k);
	for(i=k+1;i<n;++i)fa[i-k]=i,d[i]=d[i-k]+1;
	for(i=1;i<n;++i)if(!fa[i])fa[i]=n;
	std::sort(d+1,d+n);
	printf("%d\n",d[n-1]+d[n-2]+2);
	for(i=1;i<n;++i)printf("%d %d\n",fa[i],i);
	return 0;
}