#include<bits/stdc++.h>
using namespace std;
int x,y,z,a,b,c;
int main()
{
	cin>>x>>y>>z>>a>>b>>c;
	if(x<=a&&x+y<=a+b&&x+y+z<=a+b+c)
		cout<<"YES";
	else
		cout<<"NO"; 
	return 0;
}