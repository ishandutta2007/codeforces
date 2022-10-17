#include<bits/stdc++.h>
using namespace std;

const int N=1e3+7;

int q,n,t[N],f[N][N];

int main()
{
	scanf("%d",&q);
	while(q--)
	{
		int x;
		cin>>x;
		string s;
		cin>>s;
		int ans=0;
		for(int i=0;i+1<s.size();i++)
			if(s[i]==s[i+1])
				ans++;
		cout<<((ans+1)>>1)<<endl;
	}
}