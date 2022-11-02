#include<bits/stdc++.h>
using namespace std;
long long x,y;
void print(long long c)
{
	for(int i=50;i>=0;--i)
		if(c&(1<<i))
			cout<<1;
		else
			cout<<0;
	cout<<endl;
}
int main()
{	
	cin>>x>>y;
	//print(x);
	//print(y);
	if((x+y)%2)
	{
		puts("0");
		return 0;
	}
	int t=0;
	long long c=0,d=0;
	for(int b=1;b<=50;++b)
	{
		if((x-y)&(1ll<<b))
			c|=(1ll<<(b-1));
	}
	//print(c);
	d=x-c-c;
	//print(d);
	for(int b=0;b<=50;++b)
		if(d&(1ll<<b))
			++t;
	//print(x-c);
	if((c^(x-c))!=y)
		cout<<0<<endl;
	else
		if(c==0)
			cout<<(1ll<<t)-2<<endl;
		else
			cout<<(1ll<<t)<<endl;
	/*int ans2=0;
	for(int i=1;i<x;++i)
		if((i^(x-i))==y)
		{
			
			cout<<"i="<<i<<" x-i="<<(x-i)<<endl;
			print(i);
			print(x-i);
			cout<<endl;
			++ans2;
		}
	cout<<"ans2="<<ans2<<endl;
			*/
	return 0;
}