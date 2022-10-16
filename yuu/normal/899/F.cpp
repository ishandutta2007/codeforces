#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define builtin_popcount __builtin_popcountll
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
#define taskname "F"
int n, m;
string s;
int it[800001];
int value[800001];
void build(int i, int l, int r){
    if(l==r){
        value[i]=l;
        it[i]=1;
    }
    else{
        int m=(l+r)/2;
        build(2*i, l, m);
        build(2*i+1, m+1, r);
        it[i]=it[2*i]+it[2*i+1];
    }
}
void erase(int i, int l, int r, int u){
    if(l==r){
        it[i]=0;
    }
    else{
        int m=(l+r)/2;
        if(m>=u) erase(2*i, l, m, u);
        else erase(2*i+1, m+1, r, u);
        it[i]=it[2*i]+it[2*i+1];
    }
}
int find(int i, int l, int r, int k){
    if(l==r) return value[i];
    else{
        int m=(l+r)/2;
        if(it[2*i]>=k) return find(2*i, l, m, k);
        return find(2*i+1, m+1, r, k-it[2*i]);
    }
}
set <int> pos[256];
bool out[200001];
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>s;
    s='0'+s;
    FOR(i, 1, n) pos[s[i]].insert(i);
    build(1, 1, n);
    int l, r;
    char c;
    FOR(i, 1, m){
        cin>>l>>r>>c;
        l=find(1, 1, n, l);
        r=find(1, 1, n, r);
        while(!pos[c].empty()){
            if(*pos[c].rbegin()<l) break;
            set <int>::iterator it=pos[c].lower_bound(l);
            if(*it>r) break;
            out[*it]=1;
            erase(1, 1, n, *it);
            pos[c].erase(it);
        }
    }
    FOR(i, 1, n) if(!out[i]) cout<<s[i];
}