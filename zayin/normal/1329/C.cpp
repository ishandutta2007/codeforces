#include<bits/stdc++.h>
#define maxn 5000050
using namespace std;
typedef long long LL;

int n,m;

int Log2[maxn];

int dep[maxn];
int a[maxn],son[maxn],len[maxn],pos[maxn];

int ls[maxn],rs[maxn];

bool ok[maxn];

int del(int x) {
    // cout<<x<<":"<<ls[x]<<" "<<rs[x]<<endl;
    if (!ls[x]&&!rs[x])   {
        return 0;
    } else  {
        int k=son[x];
        int t=del(son[x]);
        pos[k]=pos[x];

        if (ls[x]>rs[x])
            ls[k]=t,rs[k]=rs[x];
        else
            ls[k]=ls[x],rs[k]=t;

        son[k]=max(ls[k],rs[k]);
        len[k]=len[son[k]]+1;
        dep[k]=Log2[pos[k]];
        
        ok[k]=dep[k]+len[k]-1>m;

        return k;
    }
}


vector<int> ans;
int main()  {
    for (int i=1;i<maxn;++i)
        Log2[i]=Log2[i>>1]+1;

    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);

        LL A=0;
        ans.clear();
        for (int i=0;i<(1<<n+1);++i) a[i]=0;
        for (int i=1;i<(1<<n);++i)
            scanf("%d",a+i),A+=a[i];

        for (int i=(1<<n)-1;i;--i)  {
            ls[a[i]]=a[i<<1];
            rs[a[i]]=a[i<<1|1];
            son[a[i]]=max(ls[a[i]],rs[a[i]]);

            dep[a[i]]=Log2[i];
            len[a[i]]=len[son[a[i]]]+1;
            pos[a[i]]=i;

            ok[a[i]]=1;

            // cout<<"ok:"<<i<<" "<<a[i]<<" "<<ok[a[i]]<<" "<<dep[a[i]]<<"+"<<len[a[i]]<<endl;
        }

        sort(a+1,a+(1<<n));
        reverse(a+1,a+(1<<n));

        int i=1;
        for (int t=(1<<n)-(1<<m);t;--t) {
            while (!ok[a[i]]) ++i;
            assert(i<(1<<n));

            // cout<<"del:"<<i<<" "<<a[i]<<endl;
            A-=a[i];
            ans.push_back(pos[a[i]]);
            del(a[i]);
            ++i;
        }
        printf("%lld\n",A);
        for (int i:ans) printf("%d ",i); puts("");

        for (int i=1;i<=n;++i) ls[a[i]]=rs[a[i]]=ok[a[i]]=dep[a[i]]=len[a[i]]=pos[a[i]]=0;
    }
    return 0;
}