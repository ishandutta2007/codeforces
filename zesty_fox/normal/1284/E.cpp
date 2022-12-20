#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

template<typename T>
T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define rdi read<int>
#define rdll read<ll>

const int N=5010;
const ld eps=1e-10,pi=acosl(-1.0);
int n,k;
ll sum;
struct vec{ld x,y,deg;int id;};
vector<vec> v;
vec st;

int main(){
    n=rdi();
    for(int i=0;i<n;i++) v.pb(vec()),v[i].x=rdi(),v[i].y=rdi(),v[i].id=i;
    for(int cur=0;cur<n;cur++){
        for(auto it=v.begin();it!=v.end();it++){
            if((*it).id==cur) {st=(*it);v.erase(it);break;}
        }
        ll ans=(ll)(n-1)*(n-2)*(n-3)*(n-4)/24;
        for(int i=0;i<n-1;i++){
            v[i].deg=atan2l(v[i].y-st.y,v[i].x-st.x);
        }
        sort(v.begin(),v.end(),[&](const vec &a,const vec &b){return a.deg<b.deg;});
        for(int i=0;i<n-1;i++){
            auto tmp=v[i];tmp.deg+=2*pi;
            v.pb(tmp);
        }
        for(int l=0,r=0;l<n-1;l++){
            while(r<2*(n-1)&&v[r].deg-v[l].deg<pi) r++;
            if(r-l+1>=3) ans-=(ll)(r-l-1)*(r-l-2)*(r-l-3)/6;
        }
        v.resize(n-1);v.pb(st);
        sum+=ans;
    }
    printf("%lld\n",sum);
    return 0;
}