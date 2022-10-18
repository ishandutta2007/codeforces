#include<bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
	cin>>n>>k;
	cout<<min(k-1,n-k)+3*n;
	return 0; 
}