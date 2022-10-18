#include<iostream>
using namespace std;
int t,k;
int main()
{
	cin>>t;
	while(t--&&cin>>k)
		for(int i=3;i<=360;i++)
			for(int j=1;j<i-1;j++)
				if(180*j%i==0&&180*j/i==k)
					cout<<i<<endl,i=j=360;
	return 0;
}