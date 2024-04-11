#include <cstdio>
#include <algorithm>
const int N=1e6,EXT=10;
int T,n,m,c,a,w,bkt[N+EXT],sum[2*N+EXT];
bool tag;
int main(){
	scanf("%d",&T);
	do{
		scanf("%d %d",&n,&c),tag=true;
		for(register int i=1;i<=n;++i)scanf("%d",&w),++bkt[w];
		for(register int i=1;i<=c;++i)sum[i]=sum[i-1]+bkt[i];
		for(register int i=1;i<=c;++i)sum[i+c]=sum[c];
		for(register int i=1;i<=c;++i){
			if(bkt[i])continue;
			for(register int j=1;i*j<=c;++j){
				if(!bkt[j])continue;
				if(sum[j*i-1]!=sum[j*(i+1)-1])tag=false;
			}
		}
		for(register int i=1;i<=c;++i)bkt[i]=0;
		if(tag)puts("Yes");
		else puts("No");
	}while(--T);
	return 0;
}