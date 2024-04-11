#include<iostream>
#include<cstdio>
#define N 100100
using namespace std;

int n,top;
char sta[N],mn[N];
string str;

int main()
{
	int i,j;
	cin>>str;
	mn[str.size()]='z';
	for(i=str.size()-1;i>=0;i--)
	{
		mn[i]=min(str[i],mn[i+1]);
	}
	sta[++top]='z'+1;
	for(i=0;i<str.size();i++)
	{
		for(;sta[top]<=mn[i];top--) printf("%c",sta[top]);
		sta[++top]=str[i];
	}
	for(;top>1;top--) printf("%c",sta[top]);
}