#include<bits/stdc++.h>
using namespace std;
int x;
char ch[100]={};
int main()
{	
	cin>>x;
	cin>>ch>>ch;
	if(ch[0]=='m')
	{
		if(x==31) puts("7");
		if(x==30) puts("11");
		if(x<=29) puts("12");
	}
	if(ch[0]=='w')
	{
		if(x==5 || x==6) puts("53");
		else puts("52");
	}
	return 0;
}