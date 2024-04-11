#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int a[52];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,i;
		cin>>n;
		for (i=1;i<=n;i++)
		{
			int x;cin>>x;
			while (x>n) x>>=1;
			a[i]=x;
		}
		sort(a+1,a+n+1);
		for (i=n;i;i--) if (a[i]!=i)
		{
			if (a[i]<i) break;
			a[i]>>=1;
			sort(a+1,a+n+1);
			++i;
		}
		if (i==0) cout<<"YES\n"; else cout<<"NO\n";
	}
}