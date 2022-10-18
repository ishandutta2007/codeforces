#include<bits/stdc++.h>
using namespace std;
int n,A;
int main()
{
	cin>>n;
	for(int i=2;i<n;i++)
		A+=i*(i+1);
	cout<<A;
	return 0;
}