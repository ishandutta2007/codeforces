#include<stdio.h>
#include<memory.h>
#define mod 998244353
int v[1000002],c[1000002],n,m,k,ans=1,pow[1000002];
int l[1000002],r[1000002],x[1000002],l0[1000002],s[1000002],val[1000002];
int main(){
	scanf("%d%d%d",&n,&k,&m);pow[0]=1;
	for(int i=1;i<=n;i++)pow[i]=pow[i-1]<<1,pow[i]-=pow[i]>=mod?mod:0;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&l[i],&r[i],&x[i]);
	for(int i=0;i<k;i++){
		for(int j=1;j<=m;j++)v[j]=x[j]>>i&1;
		memset(s,0,sizeof(s));val[0]=1;
		memset(l0,0,sizeof(l0));
		for(int j=1;j<=m;j++){
			if(v[j]==0){
				if(!l0[r[j]]||l0[r[j]]<l[j])l0[r[j]]=l[j];
			}else{
				s[l[j]]++;s[r[j]+1]--;
			}
		}for(int i=1,lp=0,sum=1;i<=n+1;i++){
			s[i]+=s[i-1];
			val[i]=s[i]?0:sum;sum+=val[i];sum-=sum>=mod?mod:0;
			while(lp<l0[i])sum+=mod-val[lp++],sum-=sum>=mod?mod:0;
		}ans=1ll*ans*val[n+1]%mod;
	}printf("%d",ans);
}