#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int s[N],d[N],c,M;
string t;
int main()
{
	cin>>t;
	for(int i=0;i<t.size();i++)
		if(t[i]=='a')
			M=max(M,i+1);
		else
			s[++c]=t[i],d[c]=i+1;
	if(c&1)
	{
		cout<<":(";
		return 0;
	}
	for(int i=1;i<=c/2;i++)
		if(s[i]!=s[c/2+i])
		{
			cout<<":(";
			return 0;
		}
	if(c&&d[c/2+1]<M)
	{
		cout<<":(";
		return 0;
	}
	for(int i=0;i<max(M,d[c/2+1]-1);i++)
		cout<<t[i];
	return 0;
}