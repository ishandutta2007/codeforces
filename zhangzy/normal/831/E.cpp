#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define xxx 520233
#define ll long long
using namespace std;
int n,a[xxx];ll ans=0;
vector<int>vec[xxx];

struct BIT{
	int c[xxx];
	void add(int x,int v){
		for (int i=x;i<=n;i+=(i&(-i)))
			c[i]+=v;
	}
	int que(int x){
		if (x<=0) return 0;
		int t=0;
		for (int i=x;i>0;i-=(i&(-i)))
			t+=c[i];
		return t;
	}
}bit;

int p=0;
int dis(int x,int y)
{
	if (x<y) return y-x;
	return y+n-x;
}
void doit(int w)
{
	if (!vec[w].size()) return;
	int mx=0,mw,t,d;
	for (int i=0;i<vec[w].size();i++)
	{
		t=vec[w][i];
		d=dis(p,t);
		if (d>mx)
		{
			mx=d;
			mw=t;
		}
	}
	
	if (p<=mw)
	{
		ans+=bit.que(mw)-bit.que(p);
	}
	else
	{
		ans+=bit.que(n)-bit.que(p)+bit.que(mw);
	}
	
	for (int i=0;i<vec[w].size();i++)
		bit.add(vec[w][i],-1);
	p=mw;
	//printf(" %d %d %d\n",w,p,ans);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		vec[a[i]].push_back(i);
	}
	memset(bit.c,0,sizeof(bit.c));
	for (int i=1;i<=n;i++)
		bit.add(i,1);
	for (int i=1;i<=100000;i++)
		doit(i);
	printf("%I64d",ans);
}