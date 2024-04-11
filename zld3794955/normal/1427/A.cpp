#include<bits/stdc++.h>
using namespace std;
const int N=55;
int T,n,a[N]={};
bool check()
{
	int s=0;
	for(int i=1;i<=n;++i)
		if((s+=a[i])==0)
			return false;
	return true;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>a[i];
		sort(a+1,a+n+1);
		if(check())
		{
			puts("YES");
			for(int i=1;i<=n;++i)
				cout<<a[i]<<' ';
			cout<<endl;
			continue;
		}
		reverse(a+1,a+n+1);
		if(check())
		{
			puts("YES");
			for(int i=1;i<=n;++i)
				cout<<a[i]<<' ';
			cout<<endl;
			continue;
		}
		else
			puts("NO");
	}
}