#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
string s;
int n,x,a[N],t,b;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
			x++;
		else
			x--;
		a[i]=x;
	}
	for(int i=n-2;i>=0;i--)
		a[i]=min(a[i+1],a[i]);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
		{
			if(a[i]>=2&&x==2)
				t++;
			b++;
		}
		else{
			if(a[i]>=-2&&x==-2)
				t++;
			b--;
		}
		if(b<0)
			break;
	}
	cout<<t;
	return 0;
}