#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,D=998244353;
bool v;
long long n,k,a[N],f[N][3],c,A=1,B=1;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f[0][0]=f[0][2]=1,f[0][1]=0;
	for(int i=1;i<=n;i++)
		f[i][0]=(f[i-1][1]+(k-2)*f[i-1][0])%D,f[i][1]=(k-1)*f[i-1][0]%D,f[i][2]=f[i-1][2]*(k-1)%D;
	for(int i=1;i<=n;i+=2)
		if(a[i]==-1)
			c++;
		else if(!v)
			A=f[c][2],c=0,v=true;
		else if(a[i]!=a[i-c*2-2])
			(A*=f[c][0])%=D,c=0;
		else
			(A*=f[c][1])%=D,c=0;
	if((n+1)/2==c)
		(A*=f[c-1][2]*k%D)%=D;
	else
		(A*=f[c][2])%=D;
	c=0,v=false;
	for(int i=2;i<=n;i+=2)
		if(a[i]==-1)
			c++;
		else if(!v)
			B=f[c][2],c=0,v=true;
		else if(a[i]!=a[i-c*2-2])
			(B*=f[c][0])%=D,c=0;
		else
			(B*=f[c][1])%=D,c=0;
	if(n/2==c)
		(B*=f[c-1][2]*k%D)%=D;
	else
		(B*=f[c][2])%=D;
	cout<<A*B%D<<endl;
	return 0;
}