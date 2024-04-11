#include<iostream>
using namespace std;
const int N=1.5e5+1;
int n,f[N],r[N],x,y,g[N];
int F(int k)
{
	if(f[k]==k)
		return k;
	return f[k]=F(f[k]);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		f[i]=r[i]=i;
	n--;
	while(n--&&cin>>x>>y)
		x=F(x),y=F(y),g[r[x]]=y,r[x]=r[y],f[y]=x;
	for(int i=F(1);i;i=g[i])
		cout<<i<<" ";
	return 0;
}