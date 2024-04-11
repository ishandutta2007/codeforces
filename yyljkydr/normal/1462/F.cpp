#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n;

int l[N],r[N];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        vector<int>L,R;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&l[i],&r[i]);
            L.push_back(l[i]);
            R.push_back(r[i]);
        }
        sort(L.begin(),L.end());
        sort(R.begin(),R.end());
        int ans=n+1;
        for(int i=1;i<=n;i++)
        {
            int sm=n-(upper_bound(L.begin(),L.end(),r[i])-L.begin());
            int bg=lower_bound(R.begin(),R.end(),l[i])-R.begin();
            ans=min(ans,sm+bg);
        }
        printf("%d\n",ans);
    }
}