#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
const int N=1000005;
LL n;
struct hash_map{
    static const int Ti=233,mod=1<<21;
    int cnt,nxt[mod+1],fst[mod+1];
    LL k[mod+1],v[mod+1];
    int Hash(LL x){
        int v=x&(mod-1);
        return v==0?mod:v;    
    }
    void clear(){
        cnt=0;
        memset(fst,0,sizeof fst);
    }
    LL &operator [] (LL x){
        int y=Hash(x);
        for (int p=fst[y];p;p=nxt[p])
            if (k[p]==x)
                return v[p];
        k[++cnt]=x,nxt[cnt]=fst[y],fst[y]=cnt;
        return v[cnt]=0;
    }
}check,use;
LL prime[N],pcnt,vis[N];
void get_prime(){
	memset(vis,0,sizeof vis);
	pcnt=0;
	for (int i=2;i<N;i++){
		if (vis[i])
			continue;
		prime[++pcnt]=i;
		for (int j=i+i;j<N;j+=i)
			vis[j]=1;
	}
}
int Check(LL x){
	if (x<=1)
		return 0;
	for (int i=1;prime[i]*prime[i]<=x&&i<=pcnt;i++)
		if (x%prime[i]==0){
			while (x%prime[i]==0)
				x/=prime[i];
			return x==1?prime[i]:0;
		}
	return x;
}
LL ans=0;
LL fac[N*2],fc=0;
void dfs(LL n,LL *d){
	if (*d>n)
		return;
	if (check[n]&&!use[check[n]])
		ans++;
	if (*d>=n/ *d)
		return;
	for (;*d<n/ *d;d++){
		if (n%*d)
			continue;
		LL &v=use[check[*d]];
		if (!v)
			v=1,dfs(n/ *d,d+1),v=0;
	}
}
int main(){
	get_prime();
	n=read();
	if (n==1)
		return puts("1"),0;
	check.clear();
	for (LL i=1;i*i<=n;i++){
		if (n%i)
			continue;
		LL j=n/i;
		check[i]=Check(i-1);
		check[j]=Check(j-1);
		if (check[i])
			fac[fc++]=i;
		if (i!=j&&check[j])
			fac[fc++]=j;
	}
	use.clear();
	sort(fac,fac+fc);
//	for (int i=0;i<min(fc,1000LL);i++)
//		printf("%d : %lld\n",i,fac[i]);
	fac[fc]=n+1;
	dfs(n,fac);
	printf("%lld",ans);
	return 0;
}