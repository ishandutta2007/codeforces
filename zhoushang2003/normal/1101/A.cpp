#include<iostream>
using namespace std;
int t,l,r,d;
int main()
{
	cin>>t;
	while(t--&&cin>>l>>r>>d)
		if(d<l)
			cout<<d<<endl;
		else
			cout<<(r+d)/d*d<<endl;
	return 0;
}