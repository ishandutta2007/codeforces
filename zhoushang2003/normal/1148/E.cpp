#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
struct S
{
	int x,i;
};
int n,a[N],b[N],p[N],q[N],t,d,A[N],B[N],C[N],c;
S w[N];
bool D(S x,S y)
{
	return x.x<y.x;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		w[i]=(S){a[i],i};
	for(int i=1;i<=n;i++)
		cin>>b[i];
	sort(w+1,w+n+1,D),sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
		a[i]=w[i].x;
	for(int i=1;i<=n;i++)
		a[i]-=b[i];
	for(int i=1;i<=n;i++)
		if(a[i]<0)
			p[++t]=i,q[t]=-a[i];
		else
		{
			while(t&&a[i])
			{
				d=min(a[i],q[t]),A[++c]=w[p[t]].i,B[c]=w[i].i,C[c]=d,a[i]-=d,q[t]-=d;
				if(!q[t])
					t--;
			}
			if(a[i])
			{
				cout<<"NO";
				return 0;
			}
		}
	if(t)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<'\n'<<c<<'\n';
	for(int i=1;i<=c;i++)
		cout<<A[i]<<" "<<B[i]<<" "<<C[i]<<'\n';
	return 0;
}