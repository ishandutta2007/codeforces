#include<bits/stdc++.h>
using namespace std;
int n,p=1,c;
void C(int l,int r)
{
	if(l==r)
		return;
	C(l,(l+r)/2),C((l+r)/2+1,r);
	for(int i=l;i<=(l+r)/2;i++)
		cout<<i<<' '<<i+(r-l+1)/2<<'\n';
}
int main()
{
	cin>>n;
	while(2*p<=n)
		p*=2,c++;
	cout<<p*c<<'\n',C(1,p),C(n-p+1,n);
	return 0;
}