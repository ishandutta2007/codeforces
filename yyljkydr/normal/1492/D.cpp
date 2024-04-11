#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

vector<int>x,y;

int a,b,k;

int main()
{
	scanf("%d%d%d",&a,&b,&k);
	if(k==0)
	{
		puts("Yes");
		for(int i=1;i<=b;i++)
			x.push_back(1),y.push_back(1);
		for(int i=1;i<=a;i++)
			x.push_back(0),y.push_back(0);
		for(auto w:x)
			printf("%d",w);
		puts("");
		for(auto w:y)
			printf("%d",w);
		puts("");
		return 0;
	}
	if(b==1||a==0)
	{
		puts("No");
		return 0;
	}
	x.push_back(1),y.push_back(1);
	b--;
	if(a+b-1<k)
	{
		puts("No");
		return 0;
	}
	if(k<=a)
	{
		for(int i=1;i<=b-1;i++)
			x.push_back(1),y.push_back(1);
		for(int i=1;i<=a-k;i++)
			x.push_back(0),y.push_back(0);
		x.push_back(1);
		for(int i=1;i<=k;i++)
			x.push_back(0),y.push_back(0);
		y.push_back(1);
	}
	else
	{
		while(a+b-1>k)
			x.push_back(1),y.push_back(1),b--;
		x.push_back(1);
		y.push_back(0);
		for(int i=1;i<=b-1;i++)
			x.push_back(1),y.push_back(1);
		for(int i=1;i<=a-1;i++)
			x.push_back(0),y.push_back(0);
		x.push_back(0),y.push_back(1);
	}
	puts("Yes");
	for(auto w:x)
		printf("%d",w);
	puts("");
	for(auto w:y)
		printf("%d",w);
	puts("");
}