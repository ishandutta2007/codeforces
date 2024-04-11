#include<bits/stdc++.h>
using namespace std;
const int N=100020,mod=1000000007;
int n,k,a[N]={},d[N]={};
long long ans=0;	//not to pick
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n;++i)
		scanf("%d",d+i);
	ans=max(ans,0ll+a[n]-d[n]);	//pick n alone
	if(k>=2)	//we can take all elements with picking 1~n-1 once
				//E(n-1)=1, E(pick-1)=n, or pick=1 and cancel the change
	{
		long long sum=accumulate(a+1,a+n+1,0ll);
		sum-=*min_element(d+1,d+n);
		ans=max(ans,sum);
	}
	else if(k==1)
	{
		// if E(n-1)=1, we can take 1~n-1 with picking 1~n-1 once
		long long sum=accumulate(a+1,a+n,0ll);
		sum-=*min_element(d+1,d+n);
		ans=max(ans,sum+max(0,a[n]-d[n]));	// pick n, second time
		// if pick n, we need to be careful
		sum=0;
		for(int i=n;i>=2;--i) //E[1]=n, enumerate in [2,n] where to pick
		{
			sum+=a[i];
			ans=max(ans,sum-d[i]);
		}
		sum+=a[1];
		//pick 1, delete the minimal value in a[2]...a[n]
		ans=max(ans,sum-*min_element(a+2,a+n+1)-d[1]);
		//pick 1 and the deleted position
		ans=max(ans,sum-d[1]-*min_element(d+2,d+n+1));
		//pick i,i+1, with E[i]=1
		sort(d+1,d+n+1);
		ans=max(ans,sum-d[1]-d[2]);
	}
	else	//enumerate where to pick, only once
	{
		long long sum=0;
		for(int i=n;i>=1;--i)
		{
			sum+=a[i];
			ans=max(ans,sum-d[i]);
		}
	}
	cout<<ans<<endl;
}