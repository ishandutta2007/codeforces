#include<bits/stdc++.h>
#define maxn 1050
using namespace std;

int n,m;

int pos[maxn];
int a[maxn][maxn],b[maxn];

vector<int> ans;

int main()  {
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n;++i)  {
        for (int j=1;j<=m;++j)
            scanf("%d",a[i]+j);
        pos[i]=i;
    }
    
    for (int i=1;i<=n;++i)
        ans.push_back(i);

    for (int i=1;i<m;++i)   {
        for (int j=1;j<=n;++j)
            b[j]=a[j][i]-a[j][m];
        sort(pos+1,pos+n+1,[&](int i,int j) {
            return b[i]>b[j];
        });

        // for (int k=1;k<=n;++k) cout<<b[pos[k]]<<" "; cout<<endl;

        int k,sum=0;
        for (k=1;k<=n;++k)   {
            sum+=b[pos[k]];
            if (sum<0) break;
        }

        // cout<<k<<" "<<sum-b[pos[k]]<<endl;

        if (ans.size()<=n-k+1) continue;
        // cout<<"upd:"<<n-k<<endl;
        ans.clear();
        for (int j=k;j<=n;++j)
            ans.push_back(pos[j]);
    }
    printf("%d\n",ans.size());
    for (int i:ans) 
        printf("%d ",i);
    return 0;
}