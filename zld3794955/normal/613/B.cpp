#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100100;
int n,A,c1,c2,a[N]={},num[N]={},ans1,ans2;
long long m,s[N]={},ans=0;
pair<int,int> t[N];
void init()
{
	cin>>n>>A>>c1>>c2>>m;
	//scanf("%d%d%d%d%I64d",&n,&A,&c1,&c2,&m);
	//A=1000000000;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];//scanf("%d",a+i);
		t[i]=make_pair(a[i],i);
	}
	t[n+1]=make_pair(A,n+1);
	sort(t+1,t+n+2);
	for(int i=1;i<=n+1;++i)
	{
		a[i]=t[i].first;
		num[t[i].second]=i;
	}
	for(int i=1;i<=n+1;++i)
		s[i]=s[i-1]+a[i];
}
void work()
{
	if(s[n]+m>=A*1ll*n)
	{
		printf("%I64d\n",n*1ll*c1+A*1ll*c2);
		for(int i=1;i<=n;++i)
			cout<<A<<' ';//printf("%d ",A);
		cout<<endl;//printf("\n");
		return;
	}
	long long x=m;
	for(int i=n;i>=1;--i)
	{
		//cout<<"i="<<i<<" x="<<x<<endl;
		if(x<0)
			break;
		if(a[i]*1ll*i-s[i]<=x)
		{
			long long x2=x-(a[i]*1ll*i-s[i]);
			long long tmp=c1*1ll*(n-i)+c2*1ll*(a[i]+x2/i);
			if(tmp>ans)
				ans=tmp,ans2=i,ans1=(a[i]+x2/i);
		}
		else
		{
			int l=0,r=a[i];
			while(l!=r)
			{
				//cout<<"l="<<l<<" r="<<r<<endl;
				int mid=(l+r+1)>>1;
				int p=upper_bound(a+1,a+i+1,mid)-a-1;
				if(mid*1ll*p-s[p]<=x)
					l=mid;
				else
					r=mid-1;
			}
			long long tmp=c1*1ll*(n-i)+c2*1ll*l;
			if(tmp>ans)
				ans=tmp,ans1=l,ans2=upper_bound(a+1,a+i+1,l)-a-1;
		}
		x-=A-a[i];
	}
	printf("%I64d\n",ans);
	//cout<<ans1<<' '<<ans2<<endl;
	for(int i=1;i<=n;++i)
		a[i]=t[i].first;
	for(int i=1;i<=ans2;++i)
	{
		m-=ans1-a[i];
		a[i]=ans1;
	}
	for(int i=n;i>=1;--i)
	{
		if(m<A-a[i])
			break;
		m-=A-a[i];
		a[i]=A;
	}
	for(int i=1;i<=n;++i)
		cout<<a[num[i]]<<' ';//printf("%d ",a[num[i]]);
	cout<<endl;//printf("\n");
	//cout<<clock()<<endl;
}
#undef int
int main()
{
	init();
	work();
	return 0;
}