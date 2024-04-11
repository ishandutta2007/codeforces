#import<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n,m,c[N],A[N],B[N],C;
void W(int x,int y)
{
	A[++C]=x,B[C]=y,c[x]--,c[y]--,c[x+y]++,c[abs(x-y)]++;
}
void S(int x,int y)
{
	if(y<=2)
		return;
	int z=1<<(int)log2(y);
	for(int i=y;i>z;i--)
		W(x*i,x*(2*z-i));
	S(x,2*z-y-1),S(2*x,y-z);
}
main()
{
	for(cin>>n;cin>>n;)
	{
		if(n==2)
		{
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++)
			c[i]=1;
		C=0,S(1,n),m=1<<((int)log2(n-1)+1);
		for(int i=1;i<m;i++)
			if(c[i]>1)
				W(i,i),i=m;
		for(int i=1;i<m;i++)
			while(c[i])
				W(0,i),W(i,i);
		W(0,m),c[m]=0;
		cout<<C<<'\n';
		for(int i=1;i<=C;i++)
			cout<<A[i]<<' '<<B[i]<<'\n';
	}
}