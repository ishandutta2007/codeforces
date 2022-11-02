#include<bits/stdc++.h>
using namespace std;
long long sum=0,n,s=9;
int main()
{
	cin>>n;
	for(int d=1;d<=10;++d)
	{
		s=min(s,n);
		sum+=s*d;
		n-=s;
		s*=10;
	}
	cout<<sum<<endl;
	return 0;
}