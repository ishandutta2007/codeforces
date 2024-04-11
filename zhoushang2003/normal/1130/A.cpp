#include<iostream>
using namespace std;
int n,m,x,a,b;
int main()
{
	cin>>n;
	m=n;
	while(m--&&cin>>x)
		if(x>0)
			a++;
		else if(x<0)
			b++;
	if(a*2>=n)
		cout<<1;
	else if(b*2>=n)
		cout<<-1;
	else
		cout<<0;
	return 0;
}