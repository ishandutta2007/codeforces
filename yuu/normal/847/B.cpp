#include <bits/stdc++.h>
using namespace std;
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
#define NMAX 200005
#define pb push_back
typedef long long ll;
const ll inf=1e10;
ll n,a[NMAX],cnt=1;
vector<ll> res[NMAX];
void enter(){
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
   // cout<<1;
}
void solve(){
    res[1].pb(a[1]);
    for(int i=2;i<=n;i++){
        //cout<<i<<" ";
        ll l=0,r=cnt+1;
      //  cout<<l<<" "<<r<<'\n';
        while(l<r-1){
            ll m=(l+r)>>1;
           // cout<<m<<" "<<'\n';
         //  cout<<res[m][res[m].size()-1]<<'\n';
            if(res[m][res[m].size()-1]<=a[i]){
                r=m;
            }
            else{l=m;}
        }
      //  cout<<l<<" "<<r<<" "<<m<<" "<<'\n';
        if(l==cnt&&res[cnt][res[cnt].size()-1]>a[i]){
           // cout<<res[cnt][res[cnt].size()-1]<<" ";
            cnt++;
         //   cout<<cnt<<" ";
            res[cnt].pb(a[i]);
        }
        //cout<<l<<" "<<r<<" ";
        else res[r].pb(a[i]);
    }
}
void print(){
    for(int i=1;i<=cnt;i++){
        for(int j=0;j<res[i].size();j++){
            write(res[i][j]);putchar(' ');
        }
        putchar('\n');
    }
}
int main() {
   // freopen("1.inp","r",stdin);
    enter();
    solve();
    print();
}