#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int n,m,x,y,dx=1,dy=1,xx,yy,r=0;
		cin>>n>>m>>x>>y>>xx>>yy;
		if (x<=xx) r=xx-x; else r=(n-x)+(n-xx);
		if (y<=yy) r=min(r,yy-y); else r=min(r,(m-y)+(m-yy));
		cout<<r<<'\n';
	}
}