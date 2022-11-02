#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,a[N]={};
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0,v[3]={0,0,0};
	for(int i=1;i<=n;++i)
	{
		if(a[i]==0)
			continue;
		if(ans<1)
			ans=1,v[0]=a[i];
		for(int j=i+1;j<=n;++j)
			if(!(a[i]%10 && a[j]%10) && !(a[i]/10%10 && a[j]/10%10) && !(a[i]/100%10 && a[j]/100%10))
			{
				if(ans<2)
				{
					ans=2;
					v[0]=a[i],v[1]=a[j];
				}
				for(int k=j+1;k<=n;++k)
					if(a[i]<10 && a[j]%10==0 && a[j]!=100 && a[k]==100)
					{
						ans=3;
						v[0]=a[i],v[1]=a[j],v[2]=a[k];
					}
			}
	}
	int s2=count(a+1,a+n+1,0);
	cout<<ans+s2<<endl;
	for(int i=0;i<ans;++i)
		cout<<v[i]<<' ';
	for(int i=1;i<=s2;++i)
		cout<<0<<' ';
	cout<<endl;
	return 0;
}