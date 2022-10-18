#include<bits/stdc++.h>
using namespace std;
int t,l,r,k;
int main()
{
	cin>>t;
	while(t--&&cin>>l>>r>>k)
		puts((l==r?0:(r+1)/2-l/2)>k||l+r<3?"NO":"YES");
}