#include<bits/stdc++.h>
using namespace std;
int t,n,k;
string s,r;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>k>>s)
		r=s,reverse(s.begin(),s.end()),puts(!k||s==r?"1":"2");
}