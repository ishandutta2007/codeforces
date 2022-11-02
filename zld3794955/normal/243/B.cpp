#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=100010;
int n,m,h,t,d[N]={};
vector<int> s[N];
void init()
{
	scanf("%d%d%d%d",&n,&m,&h,&t);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		s[u].push_back(v);
		s[v].push_back(u);
	}
}
void work()
{
	for(int i=1;i<=n;++i)
	{
		if((int)s[i].size()<=h)
			continue;
		for(auto p:s[i])
			d[p]=true;
		d[i]=true;
		
		for(auto p:s[i])
		{
			if((int)s[p].size()<=t)
				continue;
			d[p]=false;
			int tot=0,x=s[i].size()-h-1;
			
			vector<int> k;
			for(auto q:s[p])
			{
				if(q==i)
					continue;
				if(d[q])
				{
					if(x)
					{
						--x,++tot;
						d[q]=false;
						k.push_back(q);
					}
				}
				else
					++tot;
			}
			if(tot>=t)
			{
				puts("YES");
				printf("%d %d\n",i,p);
				for(auto tmp:s[i])
					if(d[tmp])
					{
						printf("%d ",tmp);
						if((--h)==0)
							break;
					}
				puts("");
				for(auto tmp:s[p])
					if(!d[tmp])
					{
						printf("%d ",tmp);
						if((--t)==0)
							break;
					}
				puts("");
				return;
			}
			for(auto q:k)
				d[q]=true;
			d[p]=true;
		}
		
		for(auto p:s[i])
			d[p]=false;
		d[i]=false;
	}
	puts("NO");
}
int main()
{
	//freopen("B.in","r",stdin);
	init();
	work();
	cerr<<clock()<<endl;
}