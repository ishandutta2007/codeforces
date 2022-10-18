#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,a[N],p[N],v,l,r,A[N],B[N],c,q[N],s;
void T(int x,int y)
{
	A[++c]=x,B[c]=y;
	for(int i=n;i>x;i--)
		a[i+2]=a[i];
	a[x+1]=a[x+2]=y,n+=2;
}
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i],p[i]=a[i];
		sort(p+1,p+n+1),v=c=s=0,l=1;
		for(int i=1;i<=n;i+=2)
			if(p[i]!=p[i+1])
				v=1;
		if(v||n&1)
		{
			puts("-1");
			continue;
		}
		while(l<n)
		{
			for(int i=l+1;i<=n;i++)
				if(a[i]==a[l])
					r=i,i=n;
			for(int i=r;i<2*r-l-1;i++)
				T(i,a[l+i-r+1]);
			q[++s]=2*r-2*l,l=2*r-l;
		}
		cout<<c<<'\n';
		for(int i=1;i<=c;i++)
			cout<<A[i]<<' '<<B[i]<<'\n';
		cout<<s<<'\n';
		for(int i=1;i<=s;i++)
			cout<<q[i]<<' ';
		puts("");
	}
}