#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,a[N],p[N],t=98,x,y,A[N];
int main()
{
	srand(time(NULL));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[i]=i;
	while(t--)
	{
		random_shuffle(p+1,p+n+1),x=y=0;
		for(int i=1;i<=n;i++)
			if(__gcd(x,a[p[i]])!=x)
				x=__gcd(x,a[p[i]]),A[p[i]]=1;
			else
				y=__gcd(y,a[p[i]]),A[p[i]]=2;
		if(x==1&&y==1)
		{
			cout<<"YES"<<'\n';
			for(int i=1;i<=n;i++)
				cout<<A[i]<<' ';
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}