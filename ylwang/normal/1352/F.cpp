#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n0,n1,n2,i;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n0>>n1>>n2;
		if(n1)//n10
		{
			s="1";
			for(i=0;i<n1;i++)
				if(s[s.size()-1]=='0')
					s+="1";
				else
					s+="0";
			for(i=0;i<n0;i++)
				s="10"+s.substr(1,s.size()-1);//s110
			for(i=0;i<n2;i++)
				s="1"+s;
			cout<<s<<endl;
		}
		else
			if(n0)
			{
				while(n0--)
					cout<<0;
				cout<<"0\n";//0
			}
			else
			{
				while(n2--)
					cout<<1;
				cout<<"1\n";//1
			}
	}
	return 0;
}