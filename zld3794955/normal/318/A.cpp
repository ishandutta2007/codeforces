#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main()
{
	cin>>n>>k;
	if(k<=(n+1)/2)
		cout<<2*k-1<<endl;
	else
		cout<<(k-(n+1)/2)*2<<endl;
}