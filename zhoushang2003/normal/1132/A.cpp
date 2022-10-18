#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main()
{
	cin>>a>>b>>c>>d;
	if(c&&!a)
		cout<<0;
	else if(a==d)
		cout<<1;
	else
		cout<<0;
	return 0;
}