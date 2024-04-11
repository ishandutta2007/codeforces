#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int t,n,c,a[N],v[N],s[N],A;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>c)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i],v[a[i]]=1;
		for(int i=1;i<=c;i++)
			s[i]=s[i-1]+v[i];
		A=1;
		for(int i=1;i<=c;i++)
			for(int j=1;j<=c/i;j++)
				if(!v[i]&&v[j]&&s[min(c,(i+1)*j-1)]-s[i*j-1])
					A=0;
		A?puts("Yes"):puts("No");
		for(int i=1;i<=n;i++)
			v[a[i]]=0;
	}
}