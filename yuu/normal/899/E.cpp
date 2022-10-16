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
#define taskname "E"
int n, m;
struct node{
    int id;
    int value;
    int count;
    int next;
    int prev;
} e[200001];
int a[200001];
set <pair <int, int>, greater <pair <int, int> > > s;
void pop(int i){
    if(e[i].prev>0) e[e[i].prev].next=e[i].next;
    if(e[i].prev<m) e[e[i].next].prev=e[i].prev;
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n){
        int j=i;
        while(j<n&&a[j+1]==a[i]) j++;
        m++;
        e[m].id=m;
        e[m].value=a[i];
        e[m].count=j-i+1;
        e[m].next=m+1;
        e[m].prev=m-1;
        s.insert(mp(e[m].count, -e[m].id));
        i=j;
    }
    int ans=0;
    pair <int, int> p;
    while(!s.empty()){
        ans++;
        p=*s.begin();
        s.erase(s.begin());
        p.second=-p.second;
        int pr=e[p.second].prev;
        pop(p.second);
        if(pr&&e[pr].next<=m&&e[pr].value==e[e[pr].next].value){
            s.erase(mp(e[pr].count, -e[pr].id));
            s.erase(mp(e[e[pr].next].count, -e[e[pr].next].id));
            e[pr].count+=e[e[pr].next].count;
            pop(e[pr].next);
            s.insert(mp(e[pr].count, -e[pr].id));
        }
    }
    write(ans);
}