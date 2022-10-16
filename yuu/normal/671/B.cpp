#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "B"
int n;
ll k;
int a;
//deque <pair <ll, ll> > q;
deque <ll> q;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
//    n=500000;
    read(k);
//    k=1e9;
    FOR(i, 1, n){
        read(a);
//        if(i<475000) a=i;
//        else a=1e9;
//        q.pb(mp(a, 1));
            q.pb(a);
    }
    sort(q.begin(), q.end());
    ll l=1, r=1e9, m, resl;
    while(l<=r){
        m=(l+r)/2;
        ll c=0;
        FFOR(i, 0, n) if(q[i]<m) c+=m-q[i]; else break;
        if(c>k){
            r=m-1;
        }
        else{
            resl=m;
            l=m+1;
        }
    }
    l=1, r=1e9;
    ll resr;
    while(l<=r){
        m=(l+r)/2;
        ll c=0;
        DFOR(i, n-1, 0) if(q[i]>m) c+=q[i]-m; else break;
        if(c>k){
            l=m+1;
        }
        else{
            resr=m;
            r=m-1;
        }
    }
    if(resl<resr) writeln(resr-resl);
    else{
        ll c=0;
        FFOR(i, 0, n) c+=q[i];
        if(c%n) write(1);
        else write(0);
    }
//    while(true){
//        while(q.size()>1){
//            if(q[1].first==q[0].first){
//                q[1].second+=q[0].second;
//                q.pop_front();
//            }
//            else break;
//        }
//        while(q.size()>1){
//            if(q[q.size()-2].first==q[q.size()-1].first){
//                q[q.size()-2].second+=q[q.size()-1].second;
//                q.pop_back();
//            }
//            else break;
//        }
//        if(q.size()==1){
//            write(0);
//            return 0;
//        }
//        if(q.size()==2){
//            ll highend=q.back().first-k/q.back().second;
//            ll lowbegin=q.front().first+k/q.front().second;
//            if(lowbegin<highend){
//                writeln(highend-lowbegin);
//                return 0;
//            }
//            if((q.front().first*q.front().second+q.back().first*q.back().second)%n) write(1);
//            else write(0);
//            return 0;
//        }
//        else{
//            ll up=(q[1].first-q[0].first)*q[0].second;
//            ll down=(q[q.size()-1].first-q[q.size()-2].first)*q[q.size()-1].second;
//            if(min(up, down)>=k){
//                ll low=k/q[0].second+q[0].first;
//                ll high=q[q.size()-1].first-k/q[q.size()-1].second;
//                write(high-low);
//                return 0;
//            }
//            if(up<down){
//                k-=up;
//                q[0].first=q[1].first;
//                ll high=q[q.size()-1].first-up/q[q.size()-1].second;
//                ll countlow=up%q[q.size()-1].second;
//                ll counthigh=q[q.size()-1].second-countlow;
//                q.pop_back();
//                if(countlow) q.pb(mp(high-1, countlow));
//                q.pb(mp(high, counthigh));
//            }
//            else{
//                k-=down;
//                q[q.size()-1].first=q[q.size()-2].first;
//                ll low=q[0].first+down/q[0].second;
//                ll counthigh=down%q[0].second;
//                ll countlow=q[0].second-counthigh;
//                q.pop_front();
//                q.push_front(mp(low, countlow));
//                if(counthigh) q.push_front(mp(low+1, counthigh));
//            }
//        }
//    }
}