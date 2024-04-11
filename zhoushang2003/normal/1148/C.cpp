#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
int n,a[N],p[N],A[N*5],B[N*5],t;
void S(int x,int y)
{
	A[++t]=x,B[t]=y,p[a[x]]=y,p[a[y]]=x,swap(a[x],a[y]);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		p[a[i]]=i;
	for(int i=2;i<n;i++)
		if(i<=n/2)
		{
			if(p[i]>n/2)
				S(1,p[i]);
			S(p[i],n),S(i,n);
		}
		else
		{
			if(p[i]<=n/2)
				S(p[i],n);
			S(1,p[i]),S(1,i);
		}
	if(a[1]==n)
		S(1,n);
	cout<<t<<'\n';
	for(int i=1;i<=t;i++)
		cout<<A[i]<<" "<<B[i]<<'\n';
	return 0;
}