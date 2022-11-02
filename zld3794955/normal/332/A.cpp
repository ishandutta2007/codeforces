#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=2020,L=2020;
char ch[L]={};
int n,l;
int main()
{	
	cin>>n>>(ch+1);
	l=strlen(ch+1);
	int ans=0;
	for(int i=n+1;i<=l;i+=n)
		ans+=(ch[i-1]==ch[i-2] && ch[i-2]==ch[i-3]);
	cout<<ans<<endl;
	return 0;
}