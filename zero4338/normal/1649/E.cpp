#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5,mod=998244353;
int n,m;
int ans;
int s[maxn],t[maxn];
int fac[maxn],inv[maxn],cnt[maxn];
struct fenwick
{
	int b[maxn];
	int query(int p){int ret=0;for(int i=p;i;i-=i&(-i))ret+=b[i];return ret;}
	int query(int l,int r){return query(r)-query(l-1);}
	void change(int p,int x){for(int i=p;i<=200000;i+=i&(-i))b[i]+=x;}
}tr;
void prework()
{
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;i++)inv[i]=(ll)inv[i-1]*inv[i]%mod;
}
int d;
int main()
{
	n=read();m=read();
	generate_n(s+1,n,read);
	generate_n(t+1,m,read);
	prework();
	for(int i=1;i<=n;i++)cnt[s[i]]++;
	for(int i=1;i<=2e5;i++)if(cnt[i])tr.change(i,cnt[i]);
	d=1;
	for(int i=1;i<=2e5;i++)d=(ll)d*inv[cnt[i]]%mod;
	for(int i=1;i<=m;i++)
	{
		if(i==n+1){(ans+=1)%=mod;break;}
		(ans+=(ll)d*fac[n-i]%mod*tr.query(1,t[i]-1)%mod)%=mod;
		if(cnt[t[i]]==0)break;
		d=(ll)d*cnt[t[i]]%mod;
		cnt[t[i]]--;
		tr.change(t[i],-1);
	}
	printf("%d\n",ans);
	return 0;
}