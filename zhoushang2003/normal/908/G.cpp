#import<bits/stdc++.h>
using namespace std;
#define int long long
const int D=1e9+7;
int n,A,c[99],x,u;
string s;
int P(int a,int b)
{
	x=1;
	for(;b;b/=2,a=a*a%D)
		if(b&1)
			x=x*a%D;
	return x;
}
int C(int k,int c,int p)
{
	return P(10,c)*P(100-9*k,p)%D;
}
main()
{
	cin>>s,n=s.size(),s=' '+s;
	for(int i=1;i<=n;c[s[i++]-'0']++)
		for(int j=0;j<s[i]-'0'+(i==n);j++,u=0)
			for(int k=0;k<=9;k++)
				(A+=(C(k,i-u,n-i)-C(k+1,i-u-c[k]-(j==k),n-i))*k)%=D,u+=c[k]+(j==k);
	cout<<(A*P(9,D-2)%D+D)%D;
}