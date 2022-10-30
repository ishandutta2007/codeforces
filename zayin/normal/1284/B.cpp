#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
typedef long long LL;

const int inf=1e9;

int n;
vector<int> a[maxn];

int mn[maxn],mx[maxn];

int cnt=0;
vector<int> A,B;

LL sum;

int main()  {
    scanf("%d",&n);
    for (int i=0;i<n;++i)   {
        int sz;
        scanf("%d",&sz);
        a[i].resize(sz);

        bool flag=0;
        mn[i]=inf,mx[i]=-inf;
        for (int j=0;j<sz;++j)  {
            scanf("%d",&a[i][j]);
            if (mn[i]<a[i][j])
                flag=1;
            mn[i]=min(mn[i],a[i][j]);
            mx[i]=max(mx[i],a[i][j]);
        }

        if (flag)
            ++cnt;
        else    {
            A.push_back(mn[i]);
            B.push_back(mx[i]);
        }
    }

    sum+=(LL)cnt*n+(LL)n*cnt-(LL)cnt*cnt;

    // cout<<"sum:"<<sum<<endl;
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    // cout<<"sz:"<<A.size()<<endl;
    for (int x:B)   {
        int y=lower_bound(A.begin(),A.end(),x)-A.begin();
        // cout<<x<<":"<<y<<endl;
        sum+=y;
    }
    printf("%lld\n",sum);

    return 0;
}