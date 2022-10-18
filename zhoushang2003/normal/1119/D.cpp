#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long n,m,c[N],s[N],l,r,k;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+n+1),n--;
	for(int i=1;i<=n;i++)
		c[i]=c[i+1]-c[i];
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+c[i];
	cin>>m;
	while(m--&&cin>>l>>r)
	{
		k=r-l+1;
		l=1,r=n;
		while(l<r)
			if(c[(l+r)/2]>=k)
				r=(l+r)/2;
			else
				l=(l+r)/2+1;
		if(c[l]<k)
			cout<<s[n]+k<<" ";
		else
			cout<<s[l-1]+k*(n-l+2)<<" ";
	}
	return 0;
}