#include<bits/stdc++.h>
using namespace std;
int main()
{
	int p,ans=0;
	cin>>p;
	for(int i=1;i<p;++i)
	{
		int s=1;
		bool flag=true;
		for(int j=1;j<p-1;++j)
		{
			s=s*i%p;
			if(s==1)
			{
				flag=false;
				break;
			}
		}
		ans+=flag;
	}
	cout<<ans<<endl;
}