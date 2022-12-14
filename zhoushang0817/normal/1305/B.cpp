#include<bits/stdc++.h>
using namespace std;
const int N=1e3+2;
int a[N],b[N],A,B,q[N],t;
string s;
int main()
{
	cin>>s;
	for(int i=1;i<=s.size();i++)
		a[i]=a[i-1]+(s[i-1]=='(');
	for(int i=s.size();i>=1;i--)
		b[i]=b[i+1]+(s[i-1]==')');
	for(int i=1;i<=s.size();i++)
		A=max(A,min(a[i],b[i]));
	B=A;
	if(A==0)
	{
		cout<<0;
		return 0;
	}
	cout<<1<<'\n'<<2*A<<'\n';
	for(int i=1;i<=s.size();i++)
		if(A&&s[i-1]=='(')
			cout<<i<<' ',A--;
	for(int i=s.size();i>=1;i--)
		if(B&&s[i-1]==')')
			q[++t]=i,B--;
	for(int i=t;i>=1;i--)
		cout<<q[i]<<' ';
	return 0;
}