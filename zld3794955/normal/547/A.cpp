#include<bits/stdc++.h>
using namespace std;
const int M=1000010;
#define int long long
int m,h,a,x,y;
int p[2]={},q[2]={},ans[2]={},type[2]={};
int t[M]={};
long long v[M]={},tot=0;
void calc(int pos)
{
	fill(t,t+m,0);
	int tot=0;
	while(t[h]==0)
	{
		t[h]=++tot;
		h=(x*h+y)%m;
	}
	p[pos]=t[h]-1;
	q[pos]=tot-p[pos];
	if(t[a]==0)
	{
		puts("-1");
		exit(0);
	}
	else
	{
		ans[pos]=t[a];
		if(t[a]<=p[pos])
			type[pos]=0;
		else
			type[pos]=1;
	}
}
void merge()
{
	if(type[0]==0 && type[1]==0)
	{
		if(ans[0]==ans[1])
			cout<<ans[0]-1<<endl;
		else
			puts("-1");
	}
	else
		if(type[0]==0 || type[1]==0)
		{
			int side=type[0]==0 ? 0 : 1;
			if(ans[side]<ans[!side] || (ans[side]-ans[!side])%q[!side])
				puts("-1");
			else
				cout<<ans[side]-1<<endl;
		}
		else
		{
			for(int i=0;i<m;++i)
				v[i]=ans[0]+q[0]*i;
			for(int i=0;i<m;++i)
				if(binary_search(v,v+m,ans[1]+q[1]*i))
				{
					cout<<ans[1]+q[1]*i-1<<endl;
					return;
				}
			puts("-1");
		}
}
#undef int
int main()
{
	cin>>m;
	cin>>h>>a>>x>>y;
	calc(0);
	//cout<<p[0]<<' '<<q[0]<<' '<<ans[0]<<' '<<type[0]<<endl;
	cin>>h>>a>>x>>y;
	calc(1);
	//cout<<p[1]<<' '<<q[1]<<' '<<ans[1]<<' '<<type[1]<<endl;
	merge();
	return 0;
}