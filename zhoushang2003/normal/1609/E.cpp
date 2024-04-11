#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,q,f[N][6],x;
char c;
string s;
void U(int k)
{
	f[k][0]=f[2*k][0]+f[2*k+1][0],f[k][1]=f[2*k][1]+f[2*k+1][1],f[k][2]=f[2*k][2]+f[2*k+1][2],f[k][3]=min(f[2*k][0]+f[2*k+1][3],f[2*k][3]+f[2*k+1][1]),f[k][4]=min(f[2*k][1]+f[2*k+1][4],f[2*k][4]+f[2*k+1][2]),f[k][5]=min(f[2*k][0]+f[2*k+1][5],min(f[2*k][3]+f[2*k+1][4],f[2*k][5]+f[2*k+1][2]));
}
void B(int k,int l,int r)
{
	if(l==r)
	{
		f[k][s[l]-'a']++;
		return;
	}
	int d=(l+r)/2;
	B(2*k,l,d),B(2*k+1,d+1,r),U(k);
}
void C(int k,int l,int r)
{
	if(l==r)
	{
		f[k][c-'a']++,f[k][s[x]-'a']--,s[x]=c;
		return;
	}
	int d=(l+r)/2;
	if(x<=d)
		C(2*k,l,d);
	else
		C(2*k+1,d+1,r);
	U(k);
}
int main()
{
	cin>>n>>q>>s,s=' '+s,B(1,1,n);
	while(q--&&cin>>x>>c)
	{
		C(1,1,n);
		cout<<f[1][5]<<'\n';
	}
}