#include<bits/stdc++.h>
using namespace std;
const int N=1e6,X[]={-1,0,0,1},Y[]={0,-1,1,0};
int n,u[N],v[N],A[N],B[N],x,y,k,q[N],s,t,r,b[N];
map<pair<int,int>,int>p;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>u[i]>>v[i],p[{u[i],v[i]}]=i;
	for(int i=1;i<=n;i++)
		for(int j=0;j<4;j++)
			if(!p[{x=u[i]+X[j],y=v[i]+Y[j]}])
				A[i]=x,B[i]=y,q[++t]=i,b[i]=1;
	while(s<t)
	{
		k=q[++s];
		for(int i=0;i<4;i++)
			if(!b[x=p[{u[k]+X[i],v[k]+Y[i]}]])
				A[x]=A[k],B[x]=B[k],q[++t]=x,b[x]=1;
	}
	for(int i=1;i<=n;i++)
		cout<<A[i]<<' '<<B[i]<<'\n';
}