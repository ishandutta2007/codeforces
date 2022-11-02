#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t[1010]={};
	cin>>n;
	for(int i=1,x=0;i<=n;++i)
	{
		cin>>x;
		++t[x];
	}
	for(int i=1;i<=1000;++i)
		if(t[i]>(n+1)/2)
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}