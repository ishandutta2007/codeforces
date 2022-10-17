#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;

ll n,m,ans,an;
map<char,bool>t;
char a,z;

int main()
{
	ll i,j;
	cin>>n;
	for(z='a';z<='z';z++)
	{
		t[z]=false;
	}
	for(i=1;i<=n;i++)
	{
		cin>>a;
		if(a>='A'&&a<='Z')
		{
			ans=max(ans,an);
			an=0;
			for(z='a';z<='z';z++)
			{
				t[z]=false;
			}
		}
		else
		{
			if(t[a]==false)
			{
				an++;
				t[a]=true;
			}
		}
	}
	ans=max(ans,an);
	cout<<ans;
	return 0;
}