#include<bits/stdc++.h>
using namespace std;
const int N=30,Inf=1<<30;
int n,a[N][3]={},v[3]={},ans=-Inf,s1=0,s2=0;
map<pair<int,int>,pair<int,int> > m;
void init()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i][0]>>a[i][1]>>a[i][2];
}
void tryy1(int t,int state)
{
	if(t>n)
	{
		pair<int,int> f(v[0]-v[1],v[2]-v[1]);
		auto it=m.find(f);
		if(it!=m.end())
		{
			//cout<<"find"<<endl;
			//cout<<f.first<<' '<<f.second<<endl;
			pair<int,int> g=it->second;
			if(ans<g.first+v[1])
			{
				ans=g.first+v[1];
				s1=g.second;
				s2=state;
			}
		}
		return;
	}
	v[0]+=a[t][0];
	v[1]+=a[t][1];
	tryy1(t+1,(state<<2)|1);
	v[1]-=a[t][1];
	v[2]+=a[t][2];
	tryy1(t+1,(state<<2)|2);
	v[0]-=a[t][0];
	v[1]+=a[t][1];
	tryy1(t+1,(state<<2)|3);
	v[1]-=a[t][1];
	v[2]-=a[t][2];
}
void tryy2(int t,int state)
{
	if(t>n/2)
	{
		m[make_pair(v[1]-v[0],v[1]-v[2])]={v[1],state};
		//cout<<v[1]-v[0]<<' '<<v[1]-v[2]<<' '<<endl;
		return;
	}
	v[0]+=a[t][0];
	v[1]+=a[t][1];
	tryy2(t+1,(state<<2)|1);
	v[1]-=a[t][1];
	v[2]+=a[t][2];
	tryy2(t+1,(state<<2)|2);
	v[0]-=a[t][0];
	v[1]+=a[t][1];
	tryy2(t+1,(state<<2)|3);
	v[1]-=a[t][1];
	v[2]-=a[t][2];
}
void work()
{
	tryy2(1,0);
	tryy1(n/2+1,0);
	if(ans==-Inf)
		puts("Impossible");
	else
	{
		int way[N]={};
		int tot=n;
		while(s2)
		{
			way[tot--]=s2&3;
			s2>>=2;
		}
		while(s1)
		{
			way[tot--]=s1&3;
			s1>>=2;
		}
		for(int i=1;i<=n;++i)
		{
			if(way[i]==1)
				puts("LM");
			if(way[i]==2)
				puts("LW");
			if(way[i]==3)
				puts("MW");
		}
	}
}
int main()
{	
	init();
	work();
	return 0;
}