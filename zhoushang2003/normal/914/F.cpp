#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
char c;
int n,m,t,x,y,l;
string s;
bitset<N>a[26],C,A;
int main()
{
	cin>>s>>m,n=s.size();
	for(int i=0;i<n;i++)
		a[s[i]-'a'][i]=1,C[i]=1;
	while(m--&&cin>>t>>x)
		if(t==1&&cin>>c)
			for(int i=0;i<26;i++)
				a[i][x-1]=(c-'a'==i);
		else
		{
			cin>>y>>s,l=s.size(),A=(C>>(n-y+x+l-2))<<(x-1);
			for(int i=0;i<l;i++)
				A&=a[s[i]-'a'],A<<=1;
			cout<<A.count()<<'\n';
		}
	return 0;
}