#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
bool t;
int n,p[N],h[N];
long long s[N],A;
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		h[i]=h[p[i]]+1;
	for(int i=1;i<=n;i++)
		if((h[i]%2==1&&s[i]==-1)||(h[i]%2==0&&s[i]!=-1))
			t=true;
	for(int i=n;i>=2;i--)
		if(s[i]==-1)
			s[i]=s[p[i]];
		else if(h[i]%2==1)
			if(s[p[i]]==-1)
				s[p[i]]=s[i];
			else
				s[p[i]]=min(s[p[i]],s[i]);
		else if(s[i]<s[p[i]])
			t=true;
	for(int i=1;i<=n;i++)
		A+=s[i]-s[p[i]];
	if(t)
		cout<<-1;
	else
		cout<<A;
	return 0;
}