#include<iostream>
#include<cstdio>
using namespace std;

int n,m,ans;
bool can=1;
string str;

int main()
{
	int i,j;
	cin>>n>>str;
	ans=n;
	for(i=0;i<str.size();i++)
	{
		if(i>0&&str[i]!=str[i-1]&&can) ans--,can=0;
		else can=1;
	}
	cout<<ans;
}