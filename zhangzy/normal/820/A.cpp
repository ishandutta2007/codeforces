#include<cstdio>
#include<iostream>
#include<cmath>
#define xxx 100100
#define inf 520233
using namespace std;
int c,v,v1,a,l;

int main() 
{
	cin>>c>>v>>v1>>a>>l;
	v1-=l;
	int ans=0;
	while (c>0)
	{
		ans++;
		c-=v;
		if (ans==1) v-=l;
		v=min(v1,v+a);
	}
	cout<<ans;
}