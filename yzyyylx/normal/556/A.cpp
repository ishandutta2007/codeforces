#include<bits/stdc++.h>
using namespace std;

char a[200010];
int len,m,n;

int main()
{
	int i,j;
	cin>>len;
	scanf("%s",a+1);
	for(i=1;i<=len;i++)
	{
		if(a[i]=='0') m++;
		else if(a[i]=='1') n++;
	}
	cout<<abs(m-n);
}