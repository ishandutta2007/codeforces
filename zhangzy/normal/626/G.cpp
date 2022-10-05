#include<bits/stdc++.h>
using namespace std;

#define db double
#define pdi pair<db,int>
#define fi first
#define se second

set<pdi>mn;
set<pdi,greater<pdi> >mx;

int n, T, q, pi[202000], a[202000], b[202000];

db ans;

void fuck(int i,int ty){
    if (b[i]<a[i]){
        pdi p={(db)pi[i]*a[i]/(a[i]+b[i])/(a[i]+b[i]+1),i};
        if (ty==1) mx.insert(p);
        else mx.erase(p);
    }
    if (b[i]){
        pdi p={(db)pi[i]*a[i]/(a[i]+b[i]-1)/(a[i]+b[i]),i};
        if (b[i]>a[i]) p.fi=-1e100;
        if (ty==1) mn.insert(p);
        else mn.erase(p);
    }
    {
        db v=(db)b[i]/(a[i]+b[i])*pi[i];
        if (ty==1) ans+=v;
        else ans-=v;
    }
}

int main(){
    cin>>n>>T>>q;
    for (int i=1;i<=n;++i) cin>>pi[i];
    for (int i=1;i<=n;++i) cin>>a[i], fuck(i,1);
    ++n; a[n]=1e9; fuck(n,1);
    while (T--){
        int x=mx.begin()->se;
        fuck(x,-1); ++b[x]; fuck(x,1);
    }
    for (int t,x;q--;){
        cin>>t>>x;
        fuck(x,-1);
        if (t==1) ++a[x];
        else --a[x];
        fuck(x,1);
        while (mx.size()&&mn.size()&&(mx.begin()->fi)>(mn.begin()->fi)){
            int x=(mx.begin()->se), y=(mn.begin()->se);
            fuck(x,-1); fuck(y,-1);
            ++b[x]; --b[y];
            fuck(x,1); fuck(y,1);
        }
        printf("%.10lf\n",ans);
    }
}