#include<iostream>
using namespace std;
const int N=1e5;
int n;
long long a[N],f[4];
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		if(s[i]=='h')
			f[0]+=a[i];
		else if(s[i]=='a')
			f[1]=min(f[0],f[1]+a[i]);
		else if(s[i]=='r')
			f[2]=min(min(f[0],f[1]),f[2]+a[i]);
		else if(s[i]=='d')
			f[3]=min(min(f[0],f[1]),min(f[2],f[3]+a[i]));
	cout<<f[3];
	return 0;
}