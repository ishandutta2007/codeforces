#include <cstdio>
#include <cstring>
const long long suyanxu=998244353;
int n,m,sumq,l[60],r[60];
long long ans,f[100010],g[100010],sum[100010],mem[100010];
bool tag=true;
inline int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d %d",&n,&m);
	sumq=m;
	for(register int i=1;!(i>n);++i)scanf("%d %d",&l[i],&r[i]),sumq-=l[i];
	//first use of dp:ai>m
	f[0]=1;
	for(register int i=1;i<=n;++i){
		for(register int j=0;j<=sumq;++j)g[j]=sum[j]=0;
		for(register int j=1;j<=sumq+1;j++)sum[j]=f[j-1]+sum[j-1],sum[j]%=suyanxu;
		for(register int j=0;j<=sumq;j++)g[j]=(sum[j+1]-sum[j-min(r[i]-l[i],j)]+suyanxu)%suyanxu;
        for(register int j=0;j<=sumq;++j)f[j]=g[j];
	}
	for(register int i=0;!(i>sumq);++i)ans+=f[i],ans%=suyanxu;
	for(register int i=m;i>1;--i){
		sumq=m/i,tag=true;
		for(register int j=1;j<=n;++j)sumq-=(l[j]-1)/i+1;
		for(register int j=1;!(j>sumq);++j)f[j]=0;
		for(register int j=1;j<=n;++j)if((l[j]-1)/i+1>r[j]/i)tag=false;
		if(!tag)continue;
		f[0]=1;
		for(register int k=1;k<=n;++k){
		    for(register int j=0;j<=sumq;++j)g[j]=sum[j]=0;
		    for(register int j=1;j<=sumq+1;j++)sum[j]=f[j-1]+sum[j-1],sum[j]%=suyanxu;
		    for(register int j=0;j<=sumq;j++)g[j]=(sum[j+1]-sum[j-min(r[k]/i-((l[k]-1)/i+1),j)]+suyanxu)%suyanxu;
            for(register int j=0;j<=sumq;++j)f[j]=g[j];
		}
		for(register int j=0;j<=sumq;++j)mem[i]+=f[j],mem[i]%=suyanxu;
		for(register int j=2;i*j<=m;++j)mem[i]+=suyanxu-mem[i*j],mem[i]%=suyanxu;
		ans+=suyanxu-mem[i],ans%=suyanxu;
	}
	printf("%lld",ans);
	return 0;
}