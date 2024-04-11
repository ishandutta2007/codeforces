#include<bits/stdc++.h>
#define maxn 20
#define S 1024
#define modu 998244353
using namespace std;
typedef long long LL;

int m;
char L[maxn],R[maxn];

int bitcnt[S];

LL sum[S],cnt[S];
LL ts[S],tc[S];

void init()
{
	scanf("%s%s%d",L,R,&m);
	for (int i=0;i<S;++i)
		bitcnt[i]=bitcnt[i>>1]+(i&1);
}

void upd(LL &x,LL y)
{
	x=(x+y)%modu;
}

LL calc(const char *str,bool f)
{
	LL s=0,x=0;
	memset(sum,0,sizeof(sum));
	memset(cnt,0,sizeof(cnt));
	for (int i=0;str[i];++i)
	{
		memcpy(ts,sum,sizeof(sum));
		memset(sum,0,sizeof(sum));
		memcpy(tc,cnt,sizeof(cnt));
		memset(cnt,0,sizeof(cnt));
		
		for (int s=0;s<S;++s)
			for (int c=0;c<=9;++c)
			{
				int ns=(s||c)?(s|(1<<c)):s;
				upd(sum[ns],ts[s]*10+tc[s]*c);
				upd(cnt[ns],tc[s]);
			}
		for (int c=0;c+'0'<str[i];++c)
		{
			int ns=(s||c)?(s|(1<<c)):s;
			sum[ns]+=x*10+c,++cnt[ns];
		}
		s|=1<<(str[i]-'0');
		x=x*10+str[i]-'0';
		
	}
	upd(sum[s],f*x);
	
	LL ans=0;
	for (int s=0;s<S;++s)
	{
		if (sum[s])
//		cout<<s<<" "<<sum[s]<<" "<<bitcnt[s]<<endl;
		if	(bitcnt[s]<=m)
			upd(ans,sum[s]);
	}
	return ans;
}

void solve()
{
	LL ans=calc(R,1)-calc(L,0)+modu;
	printf("%lld\n",ans%modu);
}

int main()
{
	init();
	solve();
	return 0;
}