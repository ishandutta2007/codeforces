#include<bits/stdc++.h>
using namespace std;
const int N=26;
long long f[N][N],c[N],A;
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		for(int j=0;j<26;j++)
			f[j][s[i]-'a']+=c[j];
		c[s[i]-'a']++;
	}
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			A=max(A,f[i][j]);
	for(int i=0;i<26;i++)
		A=max(A,c[i]);
	cout<<A;
	return 0;
}