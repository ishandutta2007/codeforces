#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define db double
#define ll long long
using namespace std;

int ct,cnt[200],c2;
string str;

int main()
{
	int i,j,t;
	cin>>str;
	for(i=0,t=str.size();i<t;i++)
	{
		cnt[str[i]]++;
		if(cnt[str[i]]==1) ct++;
		else if(cnt[str[i]]==2) c2++,ct--;
	}
	if(ct+c2>4)
	{
		puts("No");
		return 0;
	}
	if(ct>=4||c2&&ct>=2||c2>=2)
	{
		puts("Yes");
		return 0;
	}
	puts("No");
}