#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,a[N]={},s[N]={};
int main()
{
	cin>>n;
	for(int i=2;i<=n;++i)
	{
		cout<<"? 1 "<<i<<endl;
		cin>>s[i];
	}
	cout<<"? 2 "<<n<<endl;
	cin>>s[1];
	s[1]=s[n]-s[1];
	cout<<"! ";
	for(int i=1;i<=n;++i)
		cout<<s[i]-s[i-1]<<' ';
	cout<<endl;
}