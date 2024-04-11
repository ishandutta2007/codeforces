#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n;

vector<int>d,p;

vector<int>vis;

set<int>vip;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		d.clear(),p.clear();
		d.push_back(n);
		for(int i=2;i*i<=n;i++)
			if(n%i==0)
			{
				d.push_back(i);
				if(n!=i*i)
					d.push_back(n/i);
			}
		int x=n;
		for(int i=2;i*i<=x;i++)
			if(x%i==0)
			{
				while(x%i==0)
					x/=i;
				p.push_back(i);
			}
		if(x!=1)
			p.push_back(x);
		sort(d.begin(),d.end());
		sort(p.begin(),p.end());
		if(p.size()==1)
		{
			for(auto x:d)
				printf("%d ",x);
			puts("");
			puts("0");
		}
		else if(p.size()>2)
		{
			vis.clear();
			vis.resize(d.size());
			vip.clear();
			for(int i=0;i<p.size();i++)
				vip.insert(p[i]*p[(i+1)%p.size()]);
			vector<int>ans;
			for(int i=0;i<p.size();i++)
			{
				for(int j=0;j<d.size();j++)
					if(d[j]%p[i]==0&&!vis[j]&&!vip.count(d[j]))
						ans.push_back(d[j]),vis[j]=1;
				ans.push_back(p[i]*p[(i+1)%p.size()]);
			}
			// assert(ans.size()==d.size());
			for(auto x:ans)
				printf("%d ",x);
			puts("");
			puts("0");
		}
		else
		{
			vis.clear();
			vis.resize(d.size());
			vector<int>k(2);
			vector<int>ans;
			int x=n;
			while(x%p[0]==0)
				x/=p[0],k[0]++;
			while(x%p[1]==0)
				x/=p[1],k[1]++;
			if(k[0]==1&&k[1]==1)
			{
				vip.clear();
				vip.insert(p[0]*p[1]);
				for(int i=0;i<d.size();i++)
					if(!vip.count(d[i])&&!vis[i]&&d[i]%p[0]==0)
						ans.push_back(d[i]),vis[i]=1;
				ans.push_back(p[0]*p[1]);
				for(int i=0;i<d.size();i++)
					if(!vip.count(d[i])&&!vis[i]&&d[i]%p[1]==0)
						ans.push_back(d[i]),vis[i]=1;
				for(auto x:ans)
					printf("%d ",x);
				puts("");
				puts("1");
			}
			else
			{
				if(k[0]<k[1])
					swap(k[0],k[1]),swap(p[0],p[1]);
				vip.clear();
				vip.insert(p[0]*p[1]);
				vip.insert(p[0]*p[0]*p[1]);
				for(int i=0;i<d.size();i++)
					if(!vip.count(d[i])&&!vis[i]&&d[i]%p[0]==0)
						ans.push_back(d[i]),vis[i]=1;
				ans.push_back(p[0]*p[1]);
				for(int i=0;i<d.size();i++)
					if(!vip.count(d[i])&&!vis[i]&&d[i]%p[1]==0)
						ans.push_back(d[i]),vis[i]=1;
				ans.push_back(p[0]*p[0]*p[1]);
				for(auto x:ans)
					printf("%d ",x);
				puts("");
				puts("0");
			}
		}
	}
}