#include<stdio.h>
#include<memory.h>
int p[22][22],n,t,f[22],mk[22],d[22],st[102],tp=0,log_[10000002],lw[1000002],a[22];
char c[200002],e[200002];
inline int gf(int p){return p==f[p]?p:(f[p]=gf(f[p]));}
int main(){
	scanf("%d",&t);for(int i=2;i<1e7;i++)log_[i]=log_[i>>1]+1,lw[i]=i&1?0:lw[i>>1]+1;
	while(t--){
		scanf("%d%s%s",&n,c+1,e+1);
		memset(p,0,sizeof(p));memset(mk,0,sizeof(mk));memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)p[c[i]-'a'][e[i]-'a']=1;
		for(int i=0;i<20;i++)f[i]=i;
		for(int i=0;i<20;i++){
			for(int j=0;j<20;j++)if(i!=j&&p[i][j]&&gf(i)!=gf(j))f[f[i]]=f[j];
		}for(int i=0;i<20;i++)gf(i),p[i][i]=0;
		int ans=20,minc=20;for(int i=0;i<20;i++)if(f[i]==i)ans--;
		for(int i=0;i<20;i++){
			for(int j=0;j<20;j++)if(p[i][j])a[i]|=1<<j;
		}
		for(int B=0;B<1048576;B++){
			int cntt=20-__builtin_popcount(B),cnttt=20-cntt;if(cnttt>=minc)continue;memset(d,0,sizeof(d));
			int T=1048575^B;
			for(int i=lw[T],k=T;k;k^=k&-k,i=lw[k])
			for(int j=lw[T],l=T;l;l^=l&-l,j=lw[l])
			if(i!=j&&p[i][j])d[j]++;tp=0;
			for(int i=lw[T],k=T;k;k^=k&-k,i=lw[k])if(!d[i])st[++tp]=i;
			while(tp){
				int t=st[tp--];cntt--;
				for(int i=lw[T&a[t]],k=T&a[t];k;k^=k&-k,i=lw[k])!--d[i]&&(st[++tp]=i);
			}if(!cntt)minc=cnttt;
		}printf("%d\n",ans+minc);
	}
}