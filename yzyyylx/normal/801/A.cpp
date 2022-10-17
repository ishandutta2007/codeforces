#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

char last,ch;
int ans;
bool have,P[110];
string str;

int main()
{
	int i,j;
	cin>>str;
	last=str[0];
	for(i=1;i<=str.size();i++)
	{
		if(last=='V'&&str[i]=='K')
		{
			ans++;
			P[i]=P[i-1]=1;
		}
		last=str[i];
	}
	last=str[0];
	for(i=1;i<str.size();i++)
	{
		if(str[i]==last&&!P[i]&&!P[i-1])
		{
			ans++;
			break;
		}
		last=str[i];
	}
	cout<<ans;
}