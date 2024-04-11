#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;
using pdd=pair<double,double>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=100010;
const double eps=1e-9;

int n;
pdd p[N];

pdd midpoint(pdd a,pdd b){
    return {(a.fi+b.fi)/2,(a.se+b.se)/2};
}

double dist(pdd a,pdd b){
    return hypot(a.fi-b.fi,a.se-b.se);
}

bool collinear(pdd a,pdd b,pdd c){
    return fabs((b.se-a.se)*(c.fi-b.fi)-(c.se-b.se)*(b.fi-a.fi))<eps;
}

int main(){
    n=rdi();
    for(int i=1;i<=n;i++) p[i].fi=rdi(),p[i].se=rdi();
    if(n&1) return puts("NO"),0;
    pdd mid=midpoint(p[1],p[n/2+1]);
    for(int i=2;i<=n/2;i++){
        if(fabs(dist(mid,p[i])-dist(mid,p[i+n/2]))<eps&&\
            collinear(p[i],mid,p[i+n/2]));
        else return puts("NO"),0;
    }
    puts("YES");
    return 0;
}