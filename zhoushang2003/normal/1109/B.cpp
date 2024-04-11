#include<iostream>
using namespace std;
const int N=5e3;
bool v,b;
char c[N];
string s;
int main()
{
	cin>>s;
	if(s.size()&1)
		for(int i=0;i<s.size();i++)
			if(s[i]!=s[0]&&i!=s.size()/2)
				v=true;
	if(s.size()%2==0)
		for(int i=0;i<s.size();i++)
			if(s[i]!=s[0])
				v=true;
	if(!v)
	{
		cout<<"Impossible";
		return 0;
	}
	for(int i=0;i<s.size()-1;i++)
	{
		for(int j=i+1;j<s.size();j++)
			c[j-i-1]=s[j];
		for(int j=0;j<=i;j++)
			c[s.size()-1-i+j]=s[j];
		b=true;
		for(int j=0;j<s.size()/2;j++)
			if(c[j]!=c[s.size()-1-j])
				b=false;
		if(b)
		{
			b=true;
			for(int j=0;j<s.size();j++)
				if(c[j]!=s[j])
					b=false;
			if(!b)
				v=false;
		}
	}
	if(!v)
		cout<<1;
	else
		cout<<2;
	return 0;
}