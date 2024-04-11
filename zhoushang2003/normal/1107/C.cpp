#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,k,l,c;
long long a[N],A,p[N];
string s;
bool C(int x,int y)
{
	return x>y;
}
int P(int x,int y)
{
	c=0;
	for(int i=x;i<y;i++)
		p[c++]=a[i];
	sort(p,p+c,C);
	for(int i=0;i<min(c,k);i++)
		A+=p[i];
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>s;
	for(int i=1;i<n;i++)
		if(s[i]!=s[i-1])
			P(l,i),l=i;
	P(l,n);
	cout<<A; 
	return 0;
}