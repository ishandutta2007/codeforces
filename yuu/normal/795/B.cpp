#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
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
pair <ll, int> a[100001];
pair <ll, int> b[100001];
int n, m, d;
ll ans=0;
bool cmp(pair <ll, int> a, pair <ll, int> b){
    return (a.first>b.first)||(a.first==b.first&&a.second<b.second);
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(m);
    read(d);
    FOR(i, 1, n){
        read(a[i].first);
        read(a[i].second);
    }
    FOR(i, 1, m){
        read(b[i].first);
        read(b[i].second);
    }
    sort(a+1, a+n+1, cmp);
    sort(b+1, b+m+1, cmp);
    FOR(i, 2, n){
        a[i].first+=a[i-1].first;
        a[i].second+=a[i-1].second;
        if(a[i].second>d){
            n=i-1;
            break;
        }
    }
    FOR(i, 2, m){
        b[i].first+=b[i-1].first;
        b[i].second+=b[i-1].second;
        if(b[i].second>d){
            m=i-1;
            break;
        }
    }
    FOR(i, 1, n){
        int l=1, r=m, mid, res=0;
        while(l<=r){
            mid=(l+r)/2;
            if(a[i].second+b[mid].second<=d){
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        if(res)
            ans=max(ans, a[i].first+b[res].first);
    }
    write(ans);
}