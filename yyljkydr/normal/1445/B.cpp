#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=1e9+7;

int a[N],b[N];

int T,n,m;

int main()
{
	cin>>T;
	while(T--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		cout<<max(a+b,c+d)<<endl;
	}
}