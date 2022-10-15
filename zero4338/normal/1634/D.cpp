#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
int n;
int query(int i,int j,int k){printf("? %d %d %d\n",i,j,k);fflush(stdout);return read();}
void answer(int i,int j){printf("! %d %d\n",i,j);fflush(stdout);}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		vector<pair<int,int>>v;
		for(int i=1;i<=n;i++)
		{
			v.push_back({0,i});
			if(v.size()==4)
			{
				v[0].first=query(v[1].second,v[2].second,v[3].second);
				v[1].first=query(v[0].second,v[2].second,v[3].second);
				v[2].first=query(v[1].second,v[0].second,v[3].second);
				v[3].first=query(v[1].second,v[2].second,v[0].second);
				sort(v.begin(),v.end());
				v.pop_back();v.pop_back();
			}
		}
		if(v.size()==3)
		{
			for(int i=1;i<=n;i++)
				if(i!=v[0].second&&i!=v[1].second&&i!=v[2].second){v.push_back({0,i});break;}
			v[0].first=query(v[1].second,v[2].second,v[3].second);
			v[1].first=query(v[0].second,v[2].second,v[3].second);
			v[2].first=query(v[1].second,v[0].second,v[3].second);
			v[3].first=query(v[1].second,v[2].second,v[0].second);
			sort(v.begin(),v.end());
			v.pop_back();v.pop_back();
		}
		answer(v[0].second,v[1].second);
	}
	return 0;
}