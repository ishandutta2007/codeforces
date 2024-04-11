#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n,m,a[N],b[N],cnt[N];
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	string s;int ans=0;
	cin>>s;
	for(int i=0;i<s.length()-2;i++)
	{
		if(s[i]=='x'&&s[i+1]=='x'&&s[i+2]=='x')ans++;
	}
	cout<<ans;
}