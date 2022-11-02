#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=1010;
int n,m,c1,c2,c3,c4,a[N]={},b[M]={};
int main()
{
	cin>>c1>>c2>>c3>>c4>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=m;++i)
		cin>>b[i];
	int s1=0,s2=0;
	for(int i=1;i<=n;++i)
		s1+=min(c2,c1*a[i]);
	for(int i=1;i<=m;++i)
		s2+=min(c2,c1*b[i]);
	s1=min(s1,c3),s2=min(s2,c3);
	cout<<min(s1+s2,c4)<<endl;
}