#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int lim=1e4;
ll f[8];

int ask(vector<ll>q){
    cout<<q.size();
    for (auto o:q) printf(" %lld",o); puts("");
    fflush(stdout);
    int x; cin>>x; return x;
}

ll que(ll l,int c){
    if (c==0) return l-1;
    if (l>=lim) return l+f[c]-1;
    int sz=min(l,(ll)lim);
    ll pos=l;
    for (int i=1;i<=sz+1;++i){
        pos=que(pos,c-1);
        pos+=2;
    }
    return pos-2;
}

void gao(ll l,ll r,int c){
    int sz=min(l,(ll)lim);
    vector<ll>q;
    ll pos=l;
    for (int i=1;i<=sz;++i){
        if (pos>r) break;
        pos=que(pos,c-1);
        q.push_back(pos+1);
        pos+=2;
    }
    int res=ask(q); if (res<0) exit(0);
    gao(res==0? l: q[res-1]+1 , res==q.size()? r: q[res]-1, c-1);
}

int main(){
    f[1]=lim; for (int i=2;i<=5;++i) f[i]=f[i-1]*(lim+1)+lim;
    gao(1,10004205361450474ll,5);
}