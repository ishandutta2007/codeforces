#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while (t--)
	{
		int n;cin>>n;
		vector<int> a(n);
		for (int &x:a) cin>>x;
		sort(all(a));
		cout<<a.back()-a[0]<<'\n';
	}
}