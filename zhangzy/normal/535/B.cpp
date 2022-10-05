%:pragma GCC optimize(3)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char s[100];
long long ans=0,w=0;

int main()
{
	scanf("%s",s);
	for (int i=0;i<strlen(s);i++)
		ans+=s[i]=='4'?pow(2,strlen(s)-i-1):pow(2,strlen(s)-i);
	cout<<ans;
}