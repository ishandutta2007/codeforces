#include<bits/stdc++.h>
using namespace std;

long long m,n,a;

int main()
{
	cin>>m>>n>>a;
	cout<<(m+a-1)/a*((n+a-1)/a);
}