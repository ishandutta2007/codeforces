#include<bits/stdc++.h>
using namespace std;
char ch[9]={};
int n,h;
int main()
{
	cin>>ch>>n>>h;
	if(ch[0]=='B')
		cout<<n<<endl;
	else
	{
		double ans=n,p=2,rp=0.5;
		for(int i=1;i<=h;++i,p*=2,rp*=0.5)
		{
			double a=1-rp,b=1;
			for(int j=1;j<=n;++j,b*=a)
				ans+=(n-j)*rp*rp*b*(p-p*0.5*(1+(j-1)/(p-1)));
		}
		printf("%.9f\n",ans);
	}
	return 0;
}