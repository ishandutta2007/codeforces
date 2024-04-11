#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
int n; 
int main()
{	
	cin>>n;
	int x1,y1,x2,y2,ans=0;
	for(int i=1;i<=n;++i)
	{
		cin>>x1>>y1>>x2>>y2;
		ans+=(x2-x1+1)*(y2-y1+1);
	}
	cout<<ans<<endl;
	return 0;
}