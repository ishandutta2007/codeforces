#include<bits/stdc++.h>
#define maxn 200050
using namespace std;

int n,a[maxn];

int m,pos[maxn];
vector<int> circle[maxn];

bool vis[maxn],ok[maxn];

int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i);
    for (int i=1;i<=n;++i)  {
        if (vis[i]) continue;
        ++m;
        for (int j=i;!vis[j];j=a[j])    {
            circle[m].push_back(j);
            vis[j]=1;
            // cout<<j<<" ";
        }
        // cout<<endl;
        if (circle[m].size()==1) circle[m--].clear();
    }

    vector<pair<int,int> > res;
        // for (int i=1;i<=n;++i) cout<<a[i]<<" "; cout<<endl;
    auto exe=[&](int i,int j)   {
        tie(a[i],a[j])=make_pair(-a[j],-a[i]);
        res.emplace_back(i,j);
        // for (int i=1;i<=n;++i) cout<<a[i]<<" "; cout<<endl;
    };

    // cout<<"???:"<<m<<endl;
    while (m>1) {
        int a=m,b=m-1;
        exe(circle[a][0],circle[b][0]);
        for (int i=1;i<circle[a].size();++i)
            exe(circle[a][i],circle[b][0]);
        for (int i=1;i<circle[b].size();++i)
            exe(circle[b][i],circle[a][0]);
        exe(circle[a][0],circle[b][0]);
        m-=2;
    }

    // cout<<"???:"<<m<<endl;
    for (int i=1;i<=n;++i) ok[i]=(a[i]==i);
    if (m)  {
        if (circle[m].size()==n)    {
            exe(circle[m][n-2],circle[m][n-1]);
            exe(circle[m][0],circle[m][n-1]);
            exe(circle[m][0],circle[m][n-2]);
            for (int i=1;i<n-2;++i)
                exe(circle[m][i],circle[m][n-1]);
            exe(circle[m][n-1],circle[m][n-2]);
        } else  {
            int k;
            for (int i=1;i<=n;++i)
                if (ok[i])
                    k=i;
            exe(k,circle[m][0]);
            for (int i=1;i<circle[m].size();++i)
                exe(k,circle[m][i]);
            exe(k,circle[m][0]);
        }
    }

    assert(res.size()<=n+1);
    for (int i=1;i<=n;++i) assert(a[i]==i);

    printf("%d\n",res.size());
    for (auto p:res)
        printf("%d %d\n",p.first,p.second);

    return 0;
}