#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,x,l,r,A;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		l=r=A=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			if(x&1)
				x<l?A=1:l=x;
			else
				x<r?A=1:r=x;
		}
		puts(A?"No":"Yes");
	}
}