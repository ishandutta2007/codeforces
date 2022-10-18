#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
		if(n<20)
		{
			puts("YES");
			for(int i=0;i<n;i++)
				cout<<(int)pow(3,i)<<' ';
			puts("");
		}
		else
			puts("NO");
}