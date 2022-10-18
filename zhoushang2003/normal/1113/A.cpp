#include<bits/stdc++.h>
using namespace std;
int n,v;
int main()
{
	cin>>n>>v;
	if(n<=v)
		cout<<n-1;
	else
		cout<<v-1+(n-v)*(n-v+1)/2;
	return 0;
}