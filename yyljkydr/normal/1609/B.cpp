#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,q;

string s,ch;

int main()
{
	scanf("%d%d",&n,&q);
	cin>>s;
	int ans=0;
	for(int i=0;i+2<s.size();i++)
		if(s.substr(i,3)=="abc")
			ans++;
	while(q--)
	{
		int x;
		scanf("%d",&x);
		cin>>ch;
		for(int i=max(x-3,0);i<x&&i+2<s.size();i++)
			if(s.substr(i,3)=="abc")
				ans--;
		s[x-1]=ch[0];
		for(int i=max(x-3,0);i<x&&i+2<s.size();i++)
			if(s.substr(i,3)=="abc")
				ans++;
		printf("%d\n",ans);
	}
}