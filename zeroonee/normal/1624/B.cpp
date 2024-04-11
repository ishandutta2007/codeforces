#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if ((2*b-c)>=a&&(2*b-c)%a==0||a+c>=2*b&&(a+c)%(2*b)==0||2*b>=a+c&&(2*b-a)%c==0) cout<<"YES\n"; else cout<<"NO\n";
	}
}