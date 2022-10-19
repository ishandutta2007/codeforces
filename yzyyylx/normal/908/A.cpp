#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#define N 
#define ll long long
using namespace std;

string str;
char ch;
int k,ans;

int main()
{
	register int i,j;
	cin>>str;
	for(i=0;i<str.size();i++)
	{
		ch=str[i];
		if(ch<=58)
		{
			k=ch-48;
			if(k%2) ans++;
		}
		else
		{
			if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') ans++;
		}
	}
	cout<<ans;
}