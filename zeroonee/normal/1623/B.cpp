#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e3+2;
struct Q
{
	int l,r,v;
	bool operator<(const Q &o) const {return r-l<o.r-o.l;}
};
Q a[N];
int flg[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T,i,j;
	cin>>T;
	while (T--)
	{
		int n,i;
		cin>>n;
		for (i=1;i<=n;i++) cin>>a[i].l>>a[i].r,flg[i]=0;
		sort(a+1,a+n+1);
		for (i=1;i<=n;i++)
		{
			for (j=a[i].l;j<=a[i].r;j++) if (!flg[j]) break;
			cout<<a[i].l<<' '<<a[i].r<<' '<<j<<'\n';
			for (j=a[i].l;j<=a[i].r;j++) flg[j]=1;
		}
		cout<<'\n';
	}
}