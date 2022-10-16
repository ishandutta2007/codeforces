#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(ll i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(ll i=(j); i<(k); i++)
#define DFOR(i, j, k) for(ll i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
using ll=long long;
using ld=long double;
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
#define taskname "D"
ll n, k, l, r;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(l);
    read(r);
    read(k);
    r-=l;
    r%=n;
    r+=n+1;
    r%=n;
    if(n<=1000000){
        ll c, inmax;
        DFOR(x, n, 0){
            c=k%(n+x);
            if(c<r) continue;
            if(c>r+r) continue;
            if(c>r+x) continue;
            if(c==r*2) inmax=c-r;
            else inmax=c-r+1;
            if(x-inmax>n-r) continue;
            writeln(x);
            return 0;
        }
        writeln(-1);
    }
    else{
        if(r==0) r=n;
        ll ans=-1;
        ll low, high;
        FOR(d, 1, 100000){
            ///k=d*(n+x)+c
            ///k>=(n+x)*d
            ///k<(d+1)*(n+x)
            ///d<=k/x<d+1
            high=(k/d)+2;
            while(high*d>k) high--;
            low=(k/(d+1))-2;
            while(low*(d+1)<=k) low++;
            low=max(low, n);
            high=min(high, n+n);
            if(low>high) continue;
            ll left=low, right=high, mid, first=0, c, inmax, last=0;
            while(left<=right){
                mid=(left+right)/2;
                c=k%mid;
                if((c>(r*2))||(c>r+mid-n)){
                    left=mid+1;
                }
                else{
                    first=mid;
                    right=mid-1;
                }
            }
            left=first, right=high;
            while(left<=right){
                mid=(left+right)/2;
                c=k%mid;
                if(((mid-n-c)>n-r*2+1)){
                    right=mid-1;
                }
                else{
                    last=mid;
                    left=mid+1;
                }
            }
            if(last==0||first==0) continue;
            FOR(cnt, -5, 5){
                ll x=last-cnt;
//                if(x<first) break;
                x-=n;
                if(x<0) break;
                c=k%(n+x);
                if(c<r) continue;
                if(c>r+r) continue;
                if(c>r+x) continue;
                if(c==r*2) inmax=c-r;
                else inmax=c-r+1;
                if(x-inmax>n-r) continue;
                ans=max(ans, x);
            }
        }
        ///d=0
        if((k<=r*2)&&(k>=r)){
            ans=max(ans, k-r+(k!=r*2)+(n-r));
        }
        writeln(ans);
    }
}