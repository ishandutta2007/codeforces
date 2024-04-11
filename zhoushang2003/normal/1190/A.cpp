#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long n,m,k,p[N],c,l,r,M,A;
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>p[i];
	c=1;
	while(c<=m)
	{
		l=((p[c]-(c-1)-1)/k)*k+1,r=l+k-1,M=c;
		while(M<=m)
			if(l<=p[M]-(c-1)&&p[M]-(c-1)<=r)
				M++;
			else
				break;
		c=M,A++;
	}
	cout<<A;
	return 0;
}