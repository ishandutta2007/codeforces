#include<iostream>
using namespace std;
bool t;
string s[6];
int main()
{
	for(int i=0;i<6;i++)
		cin>>s[i];
	for(int i=1;i<6;i++)
		if(s[i][0]==s[0][0]||s[i][1]==s[0][1])
			t=true;
	if(t)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}