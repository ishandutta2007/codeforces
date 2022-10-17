#include<bits/stdc++.h>
using namespace std;

int T,n;

map<int,int>vis;

int main()
{
	cin>>T;
	while(T--)
	{
		int x;
		cin>>n>>x;
		cout<<(n<=2?1:(n-3)/x+2)<<endl;
	}
}