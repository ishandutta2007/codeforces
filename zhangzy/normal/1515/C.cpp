#include <bits/stdc++.h>
using namespace std;

int T, n, a[101000], sum, m, x, b[101000], c[101000];

#define pii pair<int,int>
#define fi first
#define se second

priority_queue<pii,vector<pii>,greater<pii> >q, nq;

int main(){
    for (cin>>T;T--;){
        cin>>n>>m>>x;
        sum=0;
        for (int i=1;i<=n;++i) scanf("%d",&a[i]), sum+=a[i];
        q=nq;
        for (int i=1;i<=m;++i) c[i]=0, q.push({0,i});
        for (int i=1;i<=n;++i){
            pii p = q.top(); q.pop();
            b[i]=p.se;
            c[b[i]]+=a[i];
            q.push({c[b[i]],b[i]});
        }
        puts("YES");
        for (int i=1;i<=n;++i) printf("%d ",b[i]); puts("");
    }
}