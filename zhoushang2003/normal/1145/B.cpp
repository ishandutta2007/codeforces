#include<bits/stdc++.h>
using namespace std;
bool v[100];
int n;
int main()
{
	cin>>n;
	v[1]=v[7]=v[9]=1;
	if((v[n%10]||n>9&&n<30||v[n/10])&&n!=12)
		cout<<"No";
	else
		cout<<"Yes";
	return 0;
}