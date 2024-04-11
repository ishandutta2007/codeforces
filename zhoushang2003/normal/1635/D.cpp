#include<bits/stdc++.h>
using namespace std;
const int N=1e6,D=1e9+7;
int n,p,a[N],x,v,f[N],A;
set<int>s;
int main()
{
	cin>>n>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i],s.insert(a[i]);
	for(int i=1;i<=n;i++)
	{
		x=a[i],v=0;
		while(x)
		{
			if(x&1)
				x/=2;
			else if(x%4!=0)
				break;
			else
				x/=4;
			if(s.count(x))
				v=1;
		}
		if(!v)
			f[(int)log2(a[i])+1]++;
	}
	for(int i=1;i<=p;i++)
		(f[i+1]+=f[i])%=D,(f[i+2]+=f[i])%=D,(A+=f[i])%=D;
	cout<<A;
}