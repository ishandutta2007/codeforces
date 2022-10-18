#include<bits/stdc++.h>
using namespace std;
const int M=123;
int n,c[M],A;
string s;
int main()
{
	cin>>n;
	while(n--&&cin>>s)
		c[s[0]]++;
	for(int i=0;i<M;i++)
		A+=(c[i]/2)*(c[i]/2-1)/2+((c[i]+1)/2)*((c[i]+1)/2-1)/2;
	cout<<A;
	return 0;
}