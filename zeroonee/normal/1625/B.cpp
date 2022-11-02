#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1.5e5+2;
int lst[N],fir[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while (t--)
	{
		int n,i,r=-1;
		cin>>n;
		vector<int> a(n),b;
		for (int &x:a) cin>>x;
		b=a;sort(all(b));b.resize(unique(all(b))-b.begin());
		for (int &x:a) x=lower_bound(all(b),x)-b.begin();
		memset(lst,-1,n*sizeof lst[0]);
		for (i=0;i<n;i++)
		{
			if (~lst[a[i]])
			{
				r=max(r,lst[a[i]]+n-i);
			}
			lst[a[i]]=i;
		}
		cout<<r<<'\n';
	}
}