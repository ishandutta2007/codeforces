#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
const int N=100010,Q=5050;
struct recommond
{
	int l,r,maxv;
	double p;
}r[Q]={};
bool recommond_cmp1(const recommond &r1,const recommond &r2)
{
	return r1.l<r2.l || (r1.l==r2.l && r1.r>r2.r);
}
int n,q,a[N]={};
vector<double> f[Q];
void init()
{
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=q;++i)
		cin>>r[i].l>>r[i].r>>r[i].p;
	r[0]={1,n,0,0};
	sort(r,r+q+1,recommond_cmp1);
}
int work(int s)
{
	int now=s+1,last=r[s].l,L=1;
	vector<int> son;
	while(now<=q && r[now].r<=r[s].r)
	{
		son.push_back(now);
		int next=work(now);
		for(int i=last;i<r[now].l;++i)
			r[s].maxv=max(r[s].maxv,a[i]);
		r[s].maxv=max(r[s].maxv,r[now].maxv);
		last=r[now].r+1;
		now=next;
	}
	for(int i=last;i<=r[s].r;++i)
		r[s].maxv=max(r[s].maxv,a[i]);
	for(auto i:son)
	{
		int delta=min(r[s].maxv-r[i].maxv,(int)f[i].size()-1);
		for(int j=0;j<delta;++j)
			f[i][delta]+=f[i][j];
		f[i].erase(f[i].begin(),f[i].begin()+delta);
		for(auto j=1u;j<f[i].size();++j)
			f[i][j]+=f[i][j-1];
		L=max(L,(int)f[i].size());
	}
	for(int i=0;i<L;++i)
	{
		f[s].push_back(1);
		for(auto j:son)
			f[s].back()*=(i>=(int)f[j].size()) ? f[j].back() : f[j][i];
	}
	adjacent_difference(f[s].begin(),f[s].end(),f[s].begin());
	f[s].push_back(0);
	double l=f[s][0]*(1-r[s].p);
	for(int i=1;i<(int)f[s].size();++i)
	{
		double tmp=f[s][i-1]*r[s].p + f[s][i]*(1-r[s].p);
		f[s][i-1]=l;
		l=tmp;
	}
	f[s].back()=l;
	return now;
}
int main()
{	
	init();
	work(0);
	double ans=r[0].maxv;
	for(auto i=0u;i<f[0].size();++i)
		ans+=f[0][i]*i;
	printf("%.9f\n",ans);
	return 0;
}