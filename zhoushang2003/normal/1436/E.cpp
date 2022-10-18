#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,a[N],v[N],l[N],s[N];
void C(int k,int l,int r,int x,int y)
{
	if(l==r)
	{
		s[k]=y;
		return;
	}
	int d=(l+r)/2;
	if(x<=d)
		C(2*k,l,d,x,y);
	else
		C(2*k+1,d+1,r,x,y);
	s[k]=min(s[2*k],s[2*k+1]);
}
int Q(int k,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
		return s[k];
	int A=1e9,d=(l+r)/2;
	if(L<=d)
		A=min(A,Q(2*k,l,d,L,R));
	if(R>d)
		A=min(A,Q(2*k+1,d+1,r,L,R));
	return A;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]>1)
			v[1]=1;
		if(a[i]>1&&Q(1,1,n,1,a[i]-1)>l[a[i]])
			v[a[i]]=1;
		l[a[i]]=i,C(1,1,n,a[i],i);
	}
	for(int i=2;i<=n+1;i++)
		if(Q(1,1,n,1,i-1)>l[i])
			v[i]=1;
	for(int i=1;;i++)
		if(!v[i])
		{
			cout<<i;
			return 0;
		}
}