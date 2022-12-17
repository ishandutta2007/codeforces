//#pragma GCC optimize(4)
#include<bits/stdc++.h>
using namespace std;
int T,l,r;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>l>>r;
		if(l>=(r+2)/2)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}