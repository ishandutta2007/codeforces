#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
char s[100010];
char t[100010];
int n,k;
int sa[100010];
int rk[100010];
int h[100010];
int c[100010];
int e[100010];
int nxt[100010];
char f[100010];
int cnt;
ll ans;
void build()
{
	static int x[200010],y[200010],b[100010];
	int i,j,k;
	int sz=26;
	for(i=1;i<=sz;i++)
		b[i]=0;
	for(i=1;i<=n;i++)
		b[x[i]=s[i]-'a'+1]++;
	for(i=2;i<=sz;i++)
		b[i]+=b[i-1];
	for(i=n;i>=1;i--)
		sa[b[x[i]]--]=i;
	for(k=1;k<=n;k<<=1)
	{
		j=0;
		for(i=n-k+1;i<=n;i++)
			y[++j]=i;
		for(i=1;i<=n;i++)
			if(sa[i]>k)
				y[++j]=sa[i]-k;
		for(i=1;i<=sz;i++)
			b[i]=0;
		for(i=1;i<=n;i++)
			b[x[y[i]]]++;
		for(i=2;i<=sz;i++)
			b[i]+=b[i-1];
		for(i=n;i>=1;i--)
			sa[b[x[y[i]]]--]=y[i];
		swap(x,y);
		j=0;
		for(i=1;i<=n;i++)
			if(i==1||y[sa[i]]!=y[sa[i-1]]||y[sa[i]+k]!=y[sa[i-1]+k])
				x[sa[i]]=++j;
			else
				x[sa[i]]=j;
		sz=j;
		if(sz>=n)
			break;
	}
	for(i=1;i<=n;i++)
		rk[sa[i]]=i;
	j=0;
	for(i=1;i<=n;i++)
		if(rk[i]==1)
			h[rk[i]]=0;
		else
		{
			if(j)
				j--;
			k=sa[rk[i]-1];
			while(i+j<=n&&k+j<=n&&s[i+j]==s[k+j])
				j++;
			h[rk[i]]=j;
		}
}
int main()
{
	scanf("%s%s%d",s+1,f+1,&k);
	n=strlen(s+1);
	int i;
	for(i=1;i<=n;i++)
		t[i]=f[s[i]-'a'+1];
	cnt=0;
	for(i=1;i<=n;i++)
	{
		if(t[i]=='0')
		{
			c[i]=1;
			e[++cnt]=i;
		}
		c[i]+=c[i-1];
	}
	nxt[n+1]=n+1;
	for(i=n;i>=1;i--)
		if(t[i]=='0')
			nxt[i]=i;
		else
			nxt[i]=nxt[i+1];
	build();
	ans=0;
	int last=0;
	for(i=1;i<=n;i++)
	{
		last=min(last,h[i]);
		int x=sa[i];
		if(c[n]-c[x-1]<=k)
		{
			ans+=n-x-last+1;
			last=n;
			continue;
		}
		else if(c[x+last-1]-c[x-1]>k)
			continue;
		int y=nxt[x];
		int z=e[c[y]+k]-x+1;
		if(z>last)
		{
			ans+=z-last-1;
			last=z;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}