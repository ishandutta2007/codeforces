#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=200200,Q=200200,D=100;
struct query
{
	int l,r,num;
}t[Q]={};
bool query_cmp(const query &q1,const query &q2)
{
	return q1.l>q2.l;
}
int n,q,x[N]={},y[N]={},root[N]={},maxv[N]={},minx[N]={};
long long toend[N]={},ans[Q]={};
int get_root(int r)
{
	if(r!=root[r])
		root[r]=get_root(root[r]);
	return root[r];
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&x[i],&y[i]),root[i]=i,minx[i]=x[i],maxv[i]=x[i]+y[i];
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
		scanf("%d%d",&t[i].l,&t[i].r),t[i].num=i;
	sort(t+1,t+q+1,query_cmp);
}
void work()
{
	int now=n;
	for(int i=1;i<=q;++i)
	{
		while(now && now>=t[i].l)
		{
			int p=now;
			while(p!=n && maxv[p]>=minx[get_root(p+1)])
			{
				int next=get_root(p+1);
				toend[p]=toend[next];
				maxv[next]=max(maxv[p],maxv[next]);
				minx[next]=min(minx[p],minx[next]);
				root[p]=next;
				p=get_root(p);
			}
			int t=get_root(p+1),s=get_root(p);
			if(s!=n)
				toend[p]=toend[t]+minx[t]-maxv[s];
			//cout<<"now="<<now<<endl;
			//for(int i=1;i<=n;++i)
			//	cout<<root[i]<<' '<<minx[i]<<' '<<maxv[i]<<' '<<toend[i]<<endl;
			//cout<<endl;
			--now;
		}
		ans[t[i].num]=toend[get_root(t[i].l)]-toend[get_root(t[i].r)];
	}
	for(int i=1;i<=q;++i)
		printf("%I64d\n",ans[i]);
}
int main()
{	
	init();
	work();
	return 0;
}