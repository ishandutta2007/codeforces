#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
int main()
{
	cin>>a>>b>>c;
	if(a>b)
		cout<<b*2+1+c*2;
	else if(a<b)
		cout<<a*2+1+c*2;
	else
		cout<<a+b+c*2;
	return 0;
}