#include<bits/stdc++.h>
using namespace std;

const int N=1e7+1e3+7;

int p[N],vis[N],ptot,d[N],ans[N];

void pre(int n)
{
	fill(ans+1,ans+n+1,1e9);
	vis[1]=1,d[1]=1,ans[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
			p[++ptot]=i,d[i]=i+1;
		for(int j=1;j<=ptot&&i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;
			d[i*p[j]]=d[i]*d[p[j]];
			if(i%p[j]==0)
			{
				int x=i*p[j],y=0;
				while(x%p[j]==0)
					x/=p[j],y++;
				d[i*p[j]]=d[x]*((int)pow(p[j],y+1)-1)/(p[j]-1);
			}
		}
		if(d[i]<=n)
			ans[d[i]]=min(ans[d[i]],i);
	}
}

int main()
{
	pre(1e7);
	int T;
	cin>>T;
	while(T--)
	{
		int x;
		cin>>x;
		cout<<(ans[x]==(int)1e9?-1:ans[x])<<endl;
	}
}