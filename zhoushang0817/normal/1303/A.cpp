#include<bits/stdc++.h>
using namespace std;
int t,c,x,y;
string s;
int main()
{
	cin>>t;
	while(t--&&cin>>s)
	{
		x=-1,y=c=0;
		for(int i=0;i<s.size();i++)
			if(s[i]=='1')
				x=i,c++;
		for(int i=s.size()-1;i>=0;i--)
			if(s[i]=='1')
				y=i;
		cout<<x-y+1-c<<'\n';
	}
	return 0;
}