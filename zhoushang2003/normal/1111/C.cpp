#include<bits/stdc++.h>
using namespace std;
const int K=1e5+1;
long long n,k,A,B,a[K];
long long S(int l,int r,int x,int y)
{
	if(x>y)
		return A;
	if(l==r)
		return B*(y-x+1);
	int m=(l+r)/2,t=x-1;
	for(int i=x;i<=y;i++)
		if(a[i]<=m)
			t=i;
	return min(B*(y-x+1)*(r-l+1),S(l,m,x,t)+S(m+1,r,t+1,y));
}
int main()
{
	cin>>n>>k>>A>>B;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	sort(a+1,a+k+1);
	cout<<S(1,1<<n,1,k);
	return 0;
}