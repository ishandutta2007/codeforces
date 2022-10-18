#include<bits/stdc++.h>
using namespace std;
const int N=21;
int n,m,q,x;
string s[N],t[N];
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<m;i++)
		cin>>t[i];
	cin>>q;
	while(q--&&cin>>x)
	{
		x--;
		cout<<s[x%n]<<t[x%m]<<'\n';
	}
	return 0;
}