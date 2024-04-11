#include<bits/stdc++.h>
using namespace std;
string s;
int x,y;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')
		{
			x++;
			if(x&1)
				cout<<3<<" "<<4<<endl;
			else
				cout<<1<<" "<<4<<endl;
		}
		else
		{
			y++;
			if(y&1)
				cout<<1<<" "<<1<<endl;
			else
				cout<<1<<" "<<3<<endl;
		}
	return 0;
}