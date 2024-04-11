#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...); 1;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2e5+2;
int a[N],lst[N],s[N],ed[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,i,j,k,m;
		cin>>n;
		fill(lst,lst+n+1,0);
		for (i=1;i<=n;i++) cin>>a[i],lst[a[i]]=i;
		m=0;
		while (lst[m]) ++m;
		s[0]=lst[0];
		vector<int> ans;ans.reserve(n);
		for (i=1;i<=m;i++) s[i]=min(s[i-1],lst[i]);
		for (i=1;i<=n;i=j+1)
		{
			int cnt=0;
			for (j=i;j<=n;j++)
			{
				if (a[j]<m&&!ed[a[j]]) ++cnt,ed[a[j]]=1;
				if (cnt==m) break;
			}
			assert(j<=n);
			ans.push_back(m);
			for (k=i;k<=j;k++) if (a[k]<m) ed[a[k]]=0;
			while (m&&s[m-1]<=j) --m;
		}
		cout<<ans.size()<<'\n';
		for (i=0;i<ans.size();i++) cout<<ans[i]<<" \n"[i+1==ans.size()];\
	}
}