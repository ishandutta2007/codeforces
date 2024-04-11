#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7,P=998244353;

int T,n,a[N],s[N],ss[N];

int ans;

void solve()
{
	int tmp=a[1];
	n--;
	for(int i=1;i<=n;i++)
		a[i]=a[i+1];
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i],ss[i]=i==1?a[i]:ss[i-2]+a[i];
	int sumc,sump;
	//Case 1:a[1] = C
	sumc=a[1],sump=0;
	{
		for(int i=2;i<=n;i++)//First p at i
		{
			sump=a[i];
			//pcpcpcppppp(c)
			{
				int l=0,r=(n-i+1)/2+1;
				while(r-l>1)
				{
					int mid=(l+r)>>1;
					int sc=s[i-1]+ss[i+mid*2-1]-ss[i-1];
					int sp=tmp+ss[i+mid*2-2]-ss[i-2]+s[n]-s[i+mid*2-1];
					if(sc<sp)
						l=mid;
					else
						r=mid;
				}
				int ct=l;//ct:pcpcpc
				if(l<r&&l)
					ans+=l;//last one is p
				l=0,r=(n-i+1-3)/2+1;//last one is c
				while(r-l>1)
				{
					int mid=(l+r)>>1;
					int sc=s[i-1]+ss[i+mid*2-1]-ss[i-1]+a[n];
					int sp=tmp+ss[i+mid*2-2]-ss[i-2]+s[n-1]-s[i+mid*2-1];
					if(sc<sp)
						l=mid;
					else
						r=mid;
				}
				if(l<r)
					ans+=l;
			}
			//ppppp(c)
			{
				if(s[i-1]<tmp+s[n]-s[i-1])
					ans++;
				if(i<n-1&&s[i-1]+a[n]<tmp+s[n-1]-s[i-1])
					ans++;
			}
		}
	}
	if(tmp>s[n]&&n>0)
		ans++;
}

signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]),s[i]=s[i-1]+a[i],ss[i]=i==1?a[i]:ss[i-2]+a[i];
/*		if(n<=5)
		{
			int all=(1<<n)-1;
			vector<int>vis(n+1);
			int ans=0;
			for(int S=0;S<=all;S++)
			{
				for(int i=1;i<=n;i++)
					vis[i]=0;
				vector<int>c,p;
				int sc=0,sp=0;
				for(int i=1;i<=n;i++)
					if(S&(1<<(i-1)))
						vis[i]=1,c.push_back(i),sc+=a[i];
					else
						p.push_back(i),sp+=a[i];
				if(sc>sp)
					continue;
				int ok=1;
				for(int i=1;i+1<c.size();i++)
					if(c[i]-c[i-1]>c[i+1]-c[i])
						ok=0;
				for(int i=1;i+1<p.size();i++)
					if(p[i]-p[i-1]<p[i+1]-p[i])
						ok=0;
				ans+=ok;
			}
			printf("%lld\n",ans);
			continue;
		}*/
		int sumc,sump;
		ans=0;
		//Case 1:a[1] = C
		sumc=a[1],sump=0;
		{
			for(int i=2;i<=n;i++)//First p at i
			{
				sump=a[i];
				//pcpcpcppppp(c)
				{
					int l=0,r=(n-i+1)/2+1;
					while(r-l>1)
					{
						int mid=(l+r)>>1;
						int sc=s[i-1]+ss[i+mid*2-1]-ss[i-1];
						int sp=ss[i+mid*2-2]-ss[i-2]+s[n]-s[i+mid*2-1];
						if(sc<sp)
							l=mid;
						else
							r=mid;
					}
					int ct=l;//ct:pcpcpcpppppppppp
					if(l<r)
						ans+=l;//last one is p
					l=0,r=(n-i+1-3)/2+1;//last one is c
					while(r-l>1)
					{
						int mid=(l+r)>>1;
						int sc=s[i-1]+ss[i+mid*2-1]-ss[i-1]+a[n];
						int sp=ss[i+mid*2-2]-ss[i-2]+s[n-1]-s[i+mid*2-1];
						if(sc<sp)
							l=mid;
						else
							r=mid;
					}
					if(l<r)//pcpcpcpppppppppc
						ans+=l;
				}
				//ppppp(c)
				{
					if(s[i-1]<s[n]-s[i-1])
						ans++;
					if(i+1<n&&s[i-1]+a[n]<s[n-1]-s[i-1])
						ans++;
				}
				sumc+=a[i];
			}
		}
		//Case 2:a[1] = P
		//PPPPCCCCC
		for(int i=3;i<=n;i++)
			if(s[n]-s[i-1]<s[i-1])
				ans++;
		ans++;//PPPPPPPPPP
		//PC????? use first
		solve();
		printf("%lld\n",ans%P);
	}
}