#include<bits/stdc++.h>
#define N 2010
using namespace std;

int n,ans,num[N],a[N],b[N];

inline int calc()
{
    int i,res=0;
    for(i=1;i<=n;i++) a[i]=a[i-1]+(num[i]==1);
    for(i=1;i<=n;i++) b[i]=b[i-1]+(num[i]==2);
    for(i=0;i<=n;i++) res=max(res,a[i]+b[n]-b[i]);
    return res;
}

int main()
{
    int i,j,t;
    cin>>n;
    for(i=1;i<=n;i++) scanf("%d",&num[i]);
    ans=calc();
    for(i=1;i<=n;i++)
    {
	t=-N;
	for(j=i;j<=n;j++)
	{
	    t=max(t,b[j]-a[j]);
	    ans=max(ans,a[i-1]+b[n]-b[j]+t+a[j]-b[i-1]);
	}
    }
    cout<<ans;
}