#include<iostream>
using namespace std;
int q,l,r;
int main()
{
	cin>>q;
	while(q--&&cin>>l>>r)
		if(r%2==0&&l%2==0)
			cout<<r-(r-l)/2<<endl;
		else if(r%2==0&&l%2==1)
			cout<<(r-l+1)/2<<endl;
		else if(r%2==1&&l%2==0)
			cout<<-(r-l+1)/2<<endl;
		else
			cout<<-r+(r-l)/2<<endl;
	return 0;
}