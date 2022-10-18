#include<bits/stdc++.h>
using namespace std;
const int N=7e3+1,M=1e5+1;
int n,T,U[N],t,x,y,z;
bitset<N>p[N],q[N],a[M];
int main()
{
	cin>>n>>T,U[1]=1;
	for(int i=1;i<N;i++)
		for(int j=i*2;j<N;j+=i)
			U[j]^=U[i];
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
		{
			if(i%j==0)
				p[i][j]=1;
			if(j%i==0)
				q[i][j]=U[j/i];
		}
	while(T--&&scanf("%d%d%d",&t,&x,&y))
		if(t==1)
			a[x]=p[y];
		else if(t==2&&scanf("%d",&z))
			a[x]=a[y]^a[z];
		else if(t==3&&scanf("%d",&z))
			a[x]=a[y]&a[z];
		else
			cout<<((a[x]&q[y]).count()&1);
	return 0; 
}