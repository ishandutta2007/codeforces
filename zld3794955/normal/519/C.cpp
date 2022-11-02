#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{	
	cin>>n>>m;
	cout<<min(min(n,m),(n+m)/3)<<endl;
	return 0;
}