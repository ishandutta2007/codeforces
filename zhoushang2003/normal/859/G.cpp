#import<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,a[N],p[N],t;
string s;
main()
{
	cin>>n>>s,t=n;
	for(int i=0;i<n;i++)
		a[i]=s[i]-'0';
	for(int i=2;i<=n;i++)
		if(t%i==0)
		{
			while(t%i==0)
				t/=i;
			for(int j=0;j<n;j++)
				p[j]=a[j];
			for(int j=0;j<n;j++)
				a[j]=p[(j+n/i)%n]-p[j];
		}
	for(int i=0;i<n;i++)
		if(a[i])
			return puts("NO"),0;
	puts("YES");
}