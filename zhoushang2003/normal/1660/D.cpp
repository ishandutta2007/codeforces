#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,a[N],p[N],s[N],A,B,C,l;
int S(int l,int r)
{
	if((p[r]-p[l-1])%2==0&&s[r]-s[l-1]>C)
		C=s[r]-s[l-1],A=l-1,B=n-r;
}
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i],p[i]=p[i-1]+(a[i]<0),s[i]=s[i-1]+(abs(a[i])>1);
		A=n,B=C=l=a[n+1]=0;
		for(int i=1;i<=n+1;i++)
			if(a[i]==0)
			{
				for(int j=l+1;j<i;j++)
					S(l+1,j),S(j,i-1);
				l=i;
			}
		cout<<A<<' '<<B<<'\n';
	}
}