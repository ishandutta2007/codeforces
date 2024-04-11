#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
#define N 200100
#define M 510
#define Q 50010
using namespace std;

ll n,m,s,num[N],a[N],be[N],le[M],ri[M],id[N],ans,tmp;

inline ll ask(ll u,ll v,ll w)
{
	ll l,r,mid;
	for(l=u,r=v+1;l<r;)
	{
		mid=((l+r)>>1);
		if(a[mid]<w) l=mid+1;
		else r=mid;
	}
	return l-u;
}

int main()
{
	ll i,j,p,q,t1,t2;
	cin>>n>>m;
	s=sqrt(n);
	for(i=1;i<=n;i++)
	{
		a[i]=num[i]=id[i]=i;
		be[i]=i/s+1;
		if(be[i]>be[i-1])
		{
			le[be[i]]=i;
			ri[be[i-1]]=i-1;
		}
	}
	while(m--)
	{
		scanf("%lld%lld",&p,&q);
		if(p==q)
		{
			printf("%lld\n",ans);
			continue;
		}
		if(p>q) swap(p,q);
		num[p]<num[q]?ans++:ans--;
		if(be[p]==be[q])
		{
			for(i=p+1;i<q;i++)
			{
				if(num[p]>num[i]&&num[i]>num[q]) ans-=2;
				if(num[p]<num[i]&&num[i]<num[q]) ans+=2;
			}
			swap(num[p],num[q]);
			printf("%lld\n",ans);
			continue;
		}
		else
		{
//			if(!m)
//			{
//				cout<<ans<<endl;
				/*
				for(i=1;i<=n;i++)
				{
					cout<<a[i]<<' ';
					if(be[i]!=be[i+1]) puts("");
				}
				for(i=1;i<=n;i++)
				{
					cout<<num[i]<<' ';
					if(be[i]!=be[i+1]) puts("");
				}
				//*/
//				cout<<num[p]<<"    "<<num[q]<<"      "<<ans<<endl;
//				for(i=p+1;be[i]==be[i-1];i++) cout<<num[i]<<" ";puts("");
//				for(i=q-1;be[i]==be[i+1];i--) cout<<num[i]<<" ";puts("");
//			}
			for(i=p+1;be[i]==be[i-1];i++)
			{
				if(num[p]>num[i]&&num[i]>num[q]) ans-=2;
				if(num[p]<num[i]&&num[i]<num[q]) ans+=2;
			}
//			cout<<ans<<endl;
			for(i=q-1;be[i]==be[i+1];i--)
			{
				if(num[p]>num[i]&&num[i]>num[q]) ans-=2;
				if(num[p]<num[i]&&num[i]<num[q]) ans+=2;
			}
//			cout<<ans<<endl;
			for(i=be[p]+1;i<be[q];i++)
			{
				ans+=(ask(le[i],ri[i],num[q])-ask(le[i],ri[i],num[p]))*2;
			}
			printf("%lld\n",ans);
			t1=id[num[p]],t2=id[num[q]];
			swap(num[p],num[q]);
			swap(id[num[p]],id[num[q]]);
			p=t1,q=t2;
			swap(a[p],a[q]);
			for(;a[p]<a[p-1]&&be[p]==be[p-1];p--) swap(a[p],a[p-1]),swap(id[a[p]],id[a[p-1]]);
			for(;a[p]>a[p+1]&&be[p]==be[p+1];p++) swap(a[p],a[p+1]),swap(id[a[p]],id[a[p+1]]);
			for(;a[q]<a[q-1]&&be[q]==be[q-1];q--) swap(a[q],a[q-1]),swap(id[a[q]],id[a[q-1]]);
			for(;a[q]>a[q+1]&&be[q]==be[q+1];q++) swap(a[q],a[q+1]),swap(id[a[q]],id[a[q+1]]);
		}
	}
//	for(i=1;i<=10;i++) cout<<le[i]<<" "<<ri[i]<<endl;
//	for(i=1;i<=n;i++) cout<<num[i]<<" ";puts("");
//	for(i=1;i<=n;i++) cout<<be[i]<<" ";
}