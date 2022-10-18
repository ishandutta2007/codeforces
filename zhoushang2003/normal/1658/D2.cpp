#include<bits/stdc++.h>
using namespace std;
int t,l,r,a[999999],v,A;
int main()
{
	cin>>t;
	while(t--&&cin>>l>>r)
	{
		for(int i=l;i<=r;i++)
			cin>>a[i];
		for(int i=20;~i;i--)
		{
			sort(a+l,a+r+1),v=0;
			for(int j=l;j<=r;j++)
				if((a[j]>>i&1)!=(j>>i&1))
					v=1,A|=1<<i;
			if(v)
				for(int j=l;j<=r;j++)
					a[j]^=1<<i;
		}
		cout<<A<<'\n',A=0;
	}
}