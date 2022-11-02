#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int T,a,b,c,d;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d;
		int sig=(a+b)%2;
		c+=b;
		d+=a;
		if(sig)
		{
			if(d)
				cout<<"Ya ";
			else
				cout<<"Tidak ";
			if(c)
				cout<<"Ya ";
			else
				cout<<"Tidak ";
			cout<<"Tidak Tidak"<<endl;
		}
		else
		{
			cout<<"Tidak Tidak ";
			if(c)
				cout<<"Ya ";
			else
				cout<<"Tidak ";
			if(d)
				cout<<"Ya"<<endl;
			else
				cout<<"Tidak"<<endl;
		}
	}
}