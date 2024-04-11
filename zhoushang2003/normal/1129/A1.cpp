#include<iostream>
using namespace std;
const int N=5001; 
int n,m,x,y,c[N],p[N],A;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i]=N;
	while(m--&&cin>>x>>y)
		c[x]++,p[x]=min(p[x],(y+n-x)%n);
	for(int i=1;i<=n;i++)
	{
		A=0;
		for(int j=1;j<=n;j++)
			if(c[j])
				A=max(A,(j+n-i)%n+(c[j]-1)*n+p[j]);
		cout<<A<<" ";
	}
	return 0; 
}