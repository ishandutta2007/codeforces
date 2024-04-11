#import<bits/stdc++.h>
using namespace std;
int t,x;
int Q(int x,int y)
{
	cout<<'?'<<' '<<x<<' '<<y<<'\n';
	cin>>x;
	return x;
}
main()
{
	cin>>t;
	while(t--)
	{
		x=0;
		for(int i=0;i<30;i++)
			if(Q((1<<i)-x,3*(1<<i)-x)>(1<<i))
				x+=1<<i;
		cout<<'!'<<' '<<x<<'\n'; 
	}
}