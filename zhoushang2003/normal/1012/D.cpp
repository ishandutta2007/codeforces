#import<bits/stdc++.h>
using namespace std;
const int N=2e6,X[2][4]={{0,0,0,1},{1,1,1,1}},Y[2][4]={{2,1,0,1},{2,1,2,3}};
int n,m,p[N],q[N],x,y,b,A[N],B[N],C;
string s,t,u,v;
void L()
{
	n=m=0;
	for(int i=0;i<s.size();i++)
		if(i==s.size()||s[i]!=s[i+1])
			p[++n]=i+1;
	for(int i=0;i<t.size();i++)
		if(i==t.size()||t[i]!=t[i+1])
			q[++m]=i+1;
	if(n>m)
		swap(n,m),swap(p,q),swap(s,t),b^=1;
}
void S(int x,int y)
{
	u=s.substr(0,x),v=t.substr(0,y),s=v+s.substr(x,s.size()-x),t=u+t.substr(y,t.size()-y),A[++C]=(b?y:x),B[C]=(b?x:y),L();
}
main()
{
	cin>>s>>t,L();
	if(m-n>1)
		x=s[0]!=t[0],y=m-n,S(p[X[x][y&3]],q[(y+Y[x][y&3])/2]);
	if(s[0]==t[0])
		S(0,q[1]);
	while(n<m)
		S(p[n],q[n]);
	for(int i=n-1;i>=1;i--)
		A[++C]=(b?q[i]:p[i]),B[C]=(b?p[i]:q[i]),b^=1;
	cout<<C<<'\n';
	for(int i=1;i<=C;i++)
		cout<<A[i]<<' '<<B[i]<<'\n';
}