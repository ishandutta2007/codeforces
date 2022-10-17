#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=2e6+1e3+7,base=13131,P=1e9+7;

int n,q,ls,ld,k;

char t[N],s[N],w[N],d[N];

constexpr uint64_t mod = (1ull<<61) - 1;

ull add(ull a,ull b)
{
	a+=b;
	a>=mod?a-=mod:0;
	return a;
}

uint64_t mul(uint64_t a, uint64_t b)
{
	uint64_t l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
	uint64_t l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
	uint64_t ret = (l&mod) + (l>>61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
	ret = (ret & mod) + (ret>>61);
	ret = (ret & mod) + (ret>>61);
	return ret-1;
}

ull hw[N],hd[N],pw[N];

ull geth(ull *ha,int l,int r)
{
	return add(ha[r],mod-mul(ha[l-1],pw[r-l+1]));
}

ll pw2[N],cnt[26];

int ex[100001][26];

ll qpow(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

int main()
{
	pw[0]=1;
	pw2[0]=1;
	for(int i=1;i<N;i++)
		pw[i]=mul(pw[i-1],base),pw2[i]=pw2[i-1]*2%P;
	scanf("%d%d",&n,&q);
	scanf("%s%s",s+1,t+1);
	ls=strlen(s+1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<26;j++)
		{
			ex[i][j]=(ex[i-1][j]*2%P+(t[i]-'a'==j))%P;
		}
	while(q--)
	{
		for(int i=0;i<26;i++)
			cnt[i]=0;
		scanf("%d%s",&k,w+1);
		ll ans=0;
		int m=strlen(w+1);
		for(int i=1;i<=m;i++)
			hw[i]=add(mul(hw[i-1],base),w[i]);
		for(int i=1;i<=ls;i++)
			d[i]=s[i];
		int ld=ls,ct=0;
		while(ld<m)
		{
			++ct;
			d[++ld]=t[ct];
			for(int i=ld+1;i<=ld*2-1;i++)
				d[i]=d[i-ld];
			ld=ld*2-1;
		}
		for(int i=1;i<=ld;i++)
			hd[i]=add(mul(hd[i-1],base),d[i]);
		if(k<ct)
		{
			puts("0");
			continue;
		}
		int ins=0;
		for(int i=1;i<=ld-m+1;i++)
			if(geth(hd,i,i+m-1)==hw[m])
				ins++;
		ans=(ans+ins*pw2[k-ct]%P)%P;
		for(int i=0;i<m;i++)
			if(geth(hw,1,i)==geth(hd,ld-i+1,ld)&&geth(hw,i+2,m)==geth(hd,1,m-i-1))
				cnt[w[i+1]-'a']++;
		for(int i=0;i<26;i++)
			ans=(ans+cnt[i]*(ex[k][i]-ex[ct][i]*pw2[k-ct]%P+P)%P+P)%P;
		printf("%lld\n",ans);
	}
}