#include<bits/stdc++.h>
using namespace std;

const int N=4e5+1e3+7;

int n,a[N];

bool cmp(int a,int b)
{
	return (a&1)<(b&1);
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	
}