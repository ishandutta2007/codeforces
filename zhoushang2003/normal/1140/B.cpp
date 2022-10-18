#include<bits/stdc++.h>
using namespace std;
int t,n,A;
string s;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>s)
	{
		A=100;
		for(int i=0;i<n;i++)
			if(s[i]=='>')
				A=min(A,i);
			else
				A=min(A,n-i-1);
		cout<<A<<endl;
	}
	return 0;
}