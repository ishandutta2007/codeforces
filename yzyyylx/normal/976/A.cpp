#include<iostream>
#include<cstdio>
#define N 210
using namespace std;

int n;
string str;

int main()
{
	int i,j;
	cin>>n>>str;
	if(str=="0")
	{
		puts("0");
		return 0;
	}
	cout<<1;
	for(i=0;i<str.size();i++)
	{
		if(str[i]=='0') printf("0");
	}
}