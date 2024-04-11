#include <cstdio>
#include <stack>
int t,n,m,p,ans,ncost,cost[410],psum[410],sum[410][410],rsum[410][410],map[410][410];
char str[410];
std::stack<int> stack;
inline int min(int x,int y){
	return x<y?x:y;
}
inline int count(int lx,int ly,int rx,int ry){
	return psum[rx-1]-psum[lx]+rx-lx-1-(rsum[rx-1][ly]-rsum[lx][ly])+rx-lx-1-(rsum[rx-1][ry]-rsum[lx][ry])+ry-ly-1-(sum[lx][ry-1]-sum[lx][ly])+ry-ly-1-(sum[rx][ry-1]-sum[rx][ly]);
}
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d %d",&n,&m);
		for(register int i=1;i<=n;++i){
			scanf("%s",str+1);
			for(register int j=1;j<=m;++j)map[i][j]=str[j]-'0';
		}
		ans=1e9;
		for(register int i=1;i<=n;++i)for(register int j=1;j<=m;++j)sum[i][j]=sum[i][j-1]+map[i][j];
		for(register int i=1;i<=m;++i)for(register int j=1;j<=n;++j)rsum[j][i]=rsum[j-1][i]+map[j][i];
		for(register int i=1;i<=m-3;++i){
			for(register int j=i+3;j<=m;++j){
				p=0,ncost=1e9;
				for(register int k=1;k<=n;++k)psum[k]=psum[k-1]+sum[k][j-1]-sum[k][i];
				for(register int k=n;k>=5;--k)if(count(1,i,k,j)<ncost)ncost=count(1,i,k,j),stack.push(k);
				for(register int k=1;k<=n-4;++k){
					while(p<k+4)p=stack.top(),stack.pop();
					ans=min(ans,count(k,i,p,j));
				}
				while(stack.size())stack.pop();
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
6 6
101110
000011
010101
100101
010100
000101
*/