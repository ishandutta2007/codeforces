#include<bits/stdc++.h>
using namespace std;
int n,x,c,t,A;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='(')
			x++;
	if(n&1||x!=n/2)
	{
		cout<<-1;
		return 0;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
			c++;
		else
			c--;
		if(c<0)
		{
			t=i+1;
			while(t<s.size()&&c<0)
				if(s[t++]=='(')
					c++;
				else
					c--;
			A+=t-i,i=t-1;
		}
	}
	cout<<A;
	return 0;
}