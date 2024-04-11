#include<bits/stdc++.h>
#define mkp(x,y)    make_pair(x,y)
#define maxn 1005
using namespace std;
typedef pair<int,int> pii;

int n;

int x[maxn],y[maxn];
int a[maxn],b[maxn];

set<pii> s;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d%d",&x[i],&y[i]);
    for (int i=1;i<=n;++i)
        scanf("%d%d",&a[i],&b[i]);

    for (int j=1;j<=n;++j)
    {
        int X=x[1]+a[j],Y=y[1]+b[j];

        // cout<<j<<" "<<X<<" "<<Y<<endl;

        s.clear();
        for (int i=1;i<=n;++i)
            s.insert(mkp(X-x[i],Y-y[i]));
        bool flag=1;
        for (int i=1;i<=n;++i)
        {
            flag&=s.count(mkp(a[i],b[i]));
            if (!flag)  break;
            s.erase(mkp(a[i],b[i]));
        }
        if (!flag)  continue;
        printf("%d %d\n",X,Y);
        break;
    }
    return 0;
}