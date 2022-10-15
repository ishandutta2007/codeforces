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
int T;
const int maxn=3e5+5;
int n,m,a[maxn];
int num[maxn],lim;
int cnt[maxn];map<int,int>ban[maxn];
vector<int>exi,val[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();
		generate_n(a+1,n,read);
		for(int i=1;i<=n;i++)num[i]=a[i];lim=n;
		sort(num+1,num+n+1);lim=unique(num+1,num+lim+1)-(num+1);
		for(int i=1;i<=n;i++)a[i]=lower_bound(num+1,num+lim+1,a[i])-num;
		for(int i=1;i<=lim;i++){cnt[i]=0;ban[i].clear();}
		for(int i=1;i<=m;i++)
		{
			int x=read(),y=read();
			x=lower_bound(num+1,num+lim+1,x)-num;
			y=lower_bound(num+1,num+lim+1,y)-num;
			ban[x][y]=ban[y][x]=1;
		}
		exi.clear();
		for(int i=1;i<=n;i++)val[i].clear();
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		for(int i=lim;i>=1;i--)
			if(cnt[i])val[cnt[i]].push_back(i);
		for(int i=1;i<=n;i++)if(!val[i].empty())exi.push_back(i);
		ll ans=0;
		for(int i=1;i<=lim;i++)
		{
			for(int &j:exi)
			{
				if(j>cnt[i])break;
				for(int &k:val[j])
				{
					if(i==k||ban[i][k])continue;
					else
					{
						ans=max(ans,(ll)(cnt[i]+j)*(num[i]+num[k]));
						break;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}