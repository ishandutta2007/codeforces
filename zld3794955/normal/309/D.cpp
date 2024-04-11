#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;
int main()
{
	cin>>n>>m;
	for(int a=m+1;a<=(n+1)/2;++a)
	{
		int k=n+1-a,c=k+k+k,v=3*a*k,x=1+(n%2==0 || a<(n+1)/2);
		for(int b=a+m+1;b<=n-m+a;++b)
		{
			while(c>m+k && b*c>=v)
				--c;
			if(c<=m+k)
				break;
			ans+=(min(c-k,n-m)-m)*x;
		}
	}
	cout<<ans*3<<endl;
	return 0;
}