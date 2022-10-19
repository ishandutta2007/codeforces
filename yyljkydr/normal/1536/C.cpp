#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int T,n;

char s[N];

map<pair<int,int>,int>last;

int f[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		last.clear();
		int d=0,k=0;
		for(int i=1;i<=n;i++)
		{
			d+=s[i]=='D';
			k+=s[i]=='K';
			int td=d/__gcd(d,k),tk=k/__gcd(d,k);
			f[i]=f[last[make_pair(td,tk)]]+1;
			last[make_pair(td,tk)]=i;
			printf("%d%c",f[i]," \n"[i==n]);
		}
	}
}