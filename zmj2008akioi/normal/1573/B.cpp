#include <cstdio>
int t,n,ans,a[100010],b[100010],pos[100010],pre[100010];
inline int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d",&n);
		for(register int j=0;j<n;++j)scanf("%d",&a[j]);
		for(register int j=0;j<n;++j)scanf("%d",&b[j]),pos[b[j]/2]=j;
		pre[n+1]=1e9;
		for(register int j=n;j>=1;--j)pre[j]=min(pre[j+1],pos[j]);
		ans=1e9;
		for(register int j=0;j<n;++j)ans=min(ans,pre[a[j]/2+1]+j);
		printf("%d\n",ans);
	}
	return 0;
}