#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "C"
int n;
int a[100001];
ll s;
priority_queue <ll> q;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(s);
    FOR(i, 1, n) read(a[i]);
    ll l=1, r=n, m;
    pair <ll, ll> ans=mp(0, 0);
    while(l<=r){
        m=(l+r)/2;
        while(!q.empty()) q.pop();
        ll cost=0;
        ll temp=0;
        FOR(i, 1, n){
            temp=m*i+a[i];
            cost+=temp;
            q.push(temp);
            if(q.size()>m){
                cost-=q.top();
                q.pop();
            }
        }
        if(cost<=s){
            ans=mp(m, cost);
            l=m+1;
        }
        else r=m-1;
    }
    write(ans.first);
    putchar(' ');
    write(ans.second);
}