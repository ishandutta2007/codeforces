#include<bits/stdc++.h>
using namespace std;
const int N=100010,V=202,Inf=1<<30;
struct leg
{
	int l,d;
}a[N]={};
int n,t[V]={};
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i].l);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i].d);
	sort(a+1,a+n+1,[](const leg &l1,const leg &l2){return l1.l>l2.l;});
	int ans=Inf,s=0;
	for(int i=1;i<=n;++i)
		++t[a[i].d];
	//for(int i=1;i<=n;++i)
	//	cout<<a[i].l<<' '<<a[i].d<<endl;
	for(int i=1,p=i; i<=n; i=p)
	{
		while(p<=n && a[p].l==a[i].l)
			--t[a[p++].d];
		
		int s2=0,k=max(0,n-p-p+i+2);
		//cout<<"i="<<i<<" p="<<p<<" k="<<k<<endl;
		for(int j=1;j<=200;++j)
		{
			s2+=min(k,t[j])*j;
			k-=min(k,t[j]);
		}
		ans=min(ans,s+s2);
		
		for(int j=i; j<p; ++j)
			s+=a[j].d;
	}
	printf("%d\n",ans);
	return 0;
}