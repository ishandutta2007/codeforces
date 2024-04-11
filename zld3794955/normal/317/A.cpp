#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
long long x,y,m,ans=0;
int main()
{	
	cin>>x>>y>>m;
	if(x>y)
		swap(x,y);
	if(y>=m)
		puts("0");
	else
		if(y<=0)
			puts("-1");
		else
		{
			if(x<0)
			{
				ans+=(-x)/y;
				x%=y;
			}
			while(y<m)
			{
				x+=y;
				if(x>y)
					swap(x,y);
				++ans;
			}
			cout<<ans<<endl;
		}
	return 0;
}