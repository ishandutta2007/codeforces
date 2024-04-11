#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=1e5+5;
int k,n,m;
int a[maxn];
struct op{double val;int num,typ;};
const bool comp1(const op &a,const op &b){return a.val>b.val;}
const bool comp2(const op &a,const op &b){return a.typ<b.typ;}
op o1[maxn];
vector<op>o2[maxn];
vector<op>f;
vector<op>ans;
int main()
{
	k=read();n=read();m=read();
	for(int i=1;i<=k;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		int t=read(),a=read(),b=read();
		if(t==1&&o1[a].val<b)o1[a]=op{1.0*b,i,1};
		else if(t==2)o2[a].push_back(op{1.0*b,i,2});
		else if(t==3)f.push_back(op{1.0*b,i,3});
	}
	for(int i=1;i<=k;i++)
	{
		if(o1[i].val>a[i])o2[i].push_back(op{o1[i].val-a[i],o1[i].num,o1[i].typ});
		sort(o2[i].begin(),o2[i].end(),comp1);
		double now=a[i];
		for(op j:o2[i])
		{
			f.push_back(op{(j.val+now)/now,j.num,j.typ});
			now+=j.val;
		}
	}
	sort(f.begin(),f.end(),comp1);
	for(op i:f)
	{
		if(ans.size()==m)break;
		ans.push_back(i);
	}
	sort(ans.begin(),ans.end(),comp2);
	printf("%d\n",ans.size());
	for(op i:ans)printf("%d ",i.num);
}