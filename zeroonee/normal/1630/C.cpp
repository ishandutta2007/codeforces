#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2e5+2;
int a[N],l[N],r[N],s[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,ans=0,cnt=0,lst=0;
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n;i++) r[a[i]]=i;
	for (i=n;i;i--) l[a[i]]=i;
	for (i=1;i<=n;i++) if (l[i]<r[i]) s[l[i]]=r[i];
	for (i=1;i<=n;i++) s[i]=max({s[i],s[i-1],i});
	for (i=1;i<=n;)
	{
		j=s[i];
		if (j==i)
		{
			ans+=i-lst-1-cnt;
			cnt=0;lst=i++;
		}
		else
		{
			++cnt;i=j;
		}
	}
	cout<<ans<<endl;
}