#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
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
#define taskname "A"
int n;
struct child{
    ll v, d, p;
    int next;
    int prev;
} c[4001];
bool done[4001];
vector <int> ans;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    FOR(i, 1, n){
        read(c[i].v);
        read(c[i].d);
        read(c[i].p);
        c[i].next=i+1;
        c[i].prev=i-1;
    }
    c[n].next=0;
    int a=1;
    while(a!=0){
        ans.pb(a);
        int b=c[a].next;
        while(b!=0&&c[a].v>0){
            c[b].p-=c[a].v;
            b=c[b].next;
            c[a].v--;
        }
        FOR(i, a+1, n){
            if((!done[i])&&c[i].p<0){
                done[i]=1;
                int j=c[i].next;
                while(j!=0){
                    c[j].p-=c[i].d;
                    j=c[j].next;
                }
                c[c[i].next].prev=c[i].prev;
                c[c[i].prev].next=c[i].next;
            }
        }
        a=c[a].next;
    }
    writeln(ans.size());
    for(int x: ans) write(x), putchar(' ');
}