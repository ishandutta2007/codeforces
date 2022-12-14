#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
bool Q;
struct Line{
    mutable ll k,m,p;//slope,intercept,right bound
    bool operator<(const Line& rhs)const{
        return Q?p<rhs.p:(k==rhs.k?m>rhs.m:k<rhs.k);//lower envelope
    }
};

struct LineContainer:set<Line>{
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf=LLONG_MAX;
    ll div(ll a,ll b){ //floored division
        return a/b-((a^b)<0&&a%b);
    }
    bool bad(iterator x,iterator y){
        if(y==end()){x->p = inf; return false;}
        if(x->k == y->k)  x->p = x->m > y->m ? inf : -inf;//lower envelope
        else x->p=div(y->m - x->m,x->k - y->k);
        return x->p>=y->p;
    }
    void add(ll k,ll m){
        auto z = insert({k,m,0}).first,y=z++,x=y;
        while(bad(y,z)) z=erase(z);
        if(x!=begin()&&bad(--x,y))  bad(x,y=erase(y));
        while((y=x)!=begin()&&(--x)->p >= y->p)
            bad(x,erase(y));
    }
    ll query(ll x){
        assert(!empty());
        Q=1;auto l=*lower_bound({0,0,x});Q=0;
        return l.k*x+l.m;
    }
};
pair<ll,pair<ll,ll> > point[1000000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>point[i].first>>point[i].second.first>>point[i].second.second;
    sort(point,point+n);
    LineContainer le;
    le.add(0,0);
    ll ans=0;
    for(int i=0;i<n;i++){
        ll x=point[i].first;
        ll y=point[i].second.first;
        ll a=point[i].second.second;
        ll dp=le.query(y)+x*y-a;
        le.add(-x,dp);
        ans=max(ans,dp);
    }
    cout<<ans<<endl;
}