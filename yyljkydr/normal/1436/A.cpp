#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N],s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>s;
		for(int i=1;i<=n;i++)
			cin>>a[i],s-=a[i];
		cout<<(s==0?"YES":"NO")<<"\n";
	}
}