#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int n,a[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

set<pii>ans;

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n-2;i++)
    {
        int j=i+2,s=a[j-1];
        while(j<=n&&s<=a[i]*2)
        {
            if(s==(a[i]^a[j]))
                ans.insert(mp(i,j));
            s+=a[j++];
        }
    }
    for(int i=3;i<=n;i++)
    {
        int j=i-2,s=a[j+1];
        while(j>=1&&s<=a[i]*2)
        {
            if(s==(a[i]^a[j]))
                ans.insert(mp(j,i));
            s+=a[j--];
        }
    }
    printf("%lld\n",(int)ans.size());
}