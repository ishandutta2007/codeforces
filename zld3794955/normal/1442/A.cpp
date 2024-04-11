#include<bits/stdc++.h>
using namespace std;
const int N=30030;
int T,n,a[N]={};
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		a[0]=a[n+1]=0;
		for(int i=0;i<=n;++i)
			a[i]=a[i+1]-a[i];
		/*
		cout<<n<<endl;
		for(int i=0;i<=n;++i)
			cout<<a[i]<<' ';
		cout<<endl;
		*/
		for(int i=1;i<n;++i)
			if(a[i]<0)
				a[0]+=a[i];
			else
				a[n]+=a[i];
		if(a[0]<0 || a[n]>0)
			puts("NO");
		else
			puts("YES");
	}
}