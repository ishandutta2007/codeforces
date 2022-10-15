#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
int n;
map<int,int>cnt;
vector<pair<int,int>>solve(int n)
{
	if(n<=2)return {};
	if(n==(n&(-n)))return solve(n-1);
	else
	{
		int p=1<<(31-__builtin_clz(n));
		vector<pair<int,int>>ret;
		for(int i=1;i<=n-p;i++)ret.push_back({p-i,p+i});
		vector<pair<int,int>>tmp=solve(p-(n-p)-1);
		for(auto &i:tmp)ret.push_back(i);
		tmp=solve(n-p);
		for(auto &i:tmp)ret.push_back({2*i.first,2*i.second});
		return ret;
	}
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		if(n==2){puts("-1");continue;}
		cnt.clear();
		vector<pair<int,int>>ans=solve(n);
		for(int i=1;i<=n;i++)cnt[i]=1;
		for(auto &i:ans)
		{
			cnt[i.first]--;
			cnt[i.second]--;
			cnt[i.first+i.second]++;
			cnt[abs(i.first-i.second)]++;
		}
		int p=1<<(32-__builtin_clz(n));
		if(n==(n&(-n)))p=n;
		if(!cnt[0])
			for(int i=0;i<=p;i++)
				if(cnt.count(i)&&cnt[i]>=2)
				{
					ans.push_back({i,i});
					cnt[0]++;cnt[2*i]++;cnt[i]-=2;
					break;
				}
		for(auto &i:cnt)
		{
			if(i.first==0)continue;
			for(int j=1;j<=i.second;j++)
			{
				int now=i.first;
				while(now!=p)
				{
					ans.push_back({now,0});
					ans.push_back({now,now});
					now*=2;
				}
			}
		}
		for(int i=1;i<=cnt[0];i++)ans.push_back({p,0});
		printf("%lu\n",ans.size());
		for(auto &i:ans)printf("%d %d\n",i.first,i.second);
	}
	return 0;
}