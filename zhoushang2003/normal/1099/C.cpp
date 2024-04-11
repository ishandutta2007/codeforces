#include<bits/stdc++.h>
using namespace std;
int k,a,b,c;
string s;
int main()
{
	cin>>s>>k;
	s+=' ';
	for(int i=0;i<s.size()-1;i++)
		if(s[i]=='?')
			b++;
		else if(s[i]=='*')
			c++;
		else if(s[i+1]!='?'&&s[i+1]!='*')
			a++;
	if(a>k||(c==0&&a+b<k))
		cout<<"Impossible";
	else if(c==0)
	{
		for(int i=0;i<s.size()-1;i++)
			if(s[i]=='?')
				continue;
			else if(s[i+1]=='?')
			{
				if(k-a>0)
					cout<<s[i],k--;
			}
			else
				cout<<s[i];
	}
	else
	{
		for(int i=0;i<s.size()-1;i++)
			if(s[i]=='?')
				continue;
			else if(s[i]=='*')
				while(k>a)
					cout<<s[i-1],k--;
			else if(s[i+1]!='?'&&s[i+1]!='*')
				cout<<s[i];
	}
	return 0;
}