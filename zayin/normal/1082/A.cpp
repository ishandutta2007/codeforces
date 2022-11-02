#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL inf=1LL<<60;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		LL n,x,y,d;
		cin>>n>>x>>y>>d;
		
		LL c=abs(x-y);
		if (c%d==0)
			cout<<c/d<<endl;
		else
		{
			LL ans1=inf,ans2=inf;
			if ((y-1)%d==0)
				ans1=(x-1-1)/d+1+(y-1)/d;
			if ((n-y)%d==0)
				ans2=(n-x-1)/d+1+(n-y)/d;
				
			if (ans1<inf||ans2<inf)
				cout<<min(ans1,ans2)<<endl;
			else
				cout<<-1<<endl;
		}
	}
	return 0;
}