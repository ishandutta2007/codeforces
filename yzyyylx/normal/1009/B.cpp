#include<iostream>
#include<cstdio>
using namespace std;

int n,cnt;
string str,ans;

int main()
{
	int i,j;
	cin>>str;
	for(i=0;i<str.size();i++)
	{
		if(str[i]!='1') ans+=str[i];
		else cnt++;
	}
	for(i=0;i<ans.size();i++)
	{
		if(ans[i]=='2')
		{
			for(j=1;j<=cnt;j++) printf("1");
			cnt=0;
		}
		printf("%c",ans[i]);
	}
	for(i=1;i<=cnt;i++) printf("1");
}