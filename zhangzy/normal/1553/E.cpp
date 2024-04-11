#include<bits/stdc++.h>
using namespace std;

int T, n, m, aim[303000], ans[303000], p[303000], vis[303000];

set<int>S;

void chk(int sft){
    for (int i=1;i<=n;++i){
        int t=(aim[i]+sft)%n;
        if (t==0) t=n;
        p[i]=t;
    }
    int res=0;
    for (int i=1;i<=n;++i) vis[i]=0;
    for (int i=1;i<=n;++i){
        if (!vis[i]){
            int t=i, l=0;
            while (!vis[t]){
                vis[t]=1; ++l; t=p[t];
            }
            res+=l-1;
        }
    }
    if (res<=m) S.insert(sft);
}

int main(){
    srand(233333);
    for (cin>>T;T--;){
        cin>>n>>m;
        for (int i=1;i<=n;++i) scanf("%d",&aim[i]);
        S.clear();
        if (n<=50){
            for (int i=0;i<n;++i) chk(i);
        }else{
            for (int sb=50;sb--;){
                int id=rand()%n+1;
                int i=(id-aim[id]+n)%n;
                chk(i);
            }
        }
        cout<<S.size();
        for (auto o:S) printf(" %d",o);
        puts("");
        // for (int i=0;i<=n;++i) ans[i]=0;
        // for (auto o:S){
        //     if (o==0){
        //         for (int i=0;i<n;++i) ans[i]=1;
        //     }else{
        //         for (int i=1;i<n;++i){
        //             if (n%__gcd(i,o)==0) ans[i]=1;
        //         }
        //     }
        // }
        // int cnt=0;
        // for (int i=0;i<n;++i) if (ans[i]) ++cnt;
        // printf("%d ",cnt);
        // for (int i=0;i<n;++i) if (ans[i]) printf("%d ",i);
        // puts("");
    }
}