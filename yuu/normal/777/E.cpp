#include <stdio.h>
#include <locale>
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
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
#define taskname "E"
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct ring{
    int a, b, h;
} r[100001];
int n;
vector <int> v;
map <int, int> M;
int msize=0;
bool cmp(ring a, ring b){
    return (a.b>b.b)||(a.b==b.b&&a.a>b.a);
}
long long it[800001];
long long get(int i, int l, int r, int u, int v){
    if(l>v||r<u) return 0;
    if(l>=u&&r<=v)
        return it[i];
    int m=(l+r)/2;
    return max(get(2*i, l, m, u, v), get(2*i+1, m+1, r, u, v));
}
void update(int i, int l, int r, int u, long long x){
    if(r<u||l>u) return;
    if(l==r){
        it[i]=max(it[i], x);
    }
    else{
        int m=(l+r)/2;
        update(2*i, l, m, u, x);
        update(2*i+1, m+1, r, u, x);
        it[i]=max(it[2*i], it[2*i+1]);
    }
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    FOR(i, 1, n){
        read(r[i].a);
        read(r[i].b);
        read(r[i].h);
        v.push_back(r[i].a);
        v.push_back(r[i].b);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
        if(M.find(v[i])==M.end())
            M[v[i]]=++msize;
    FOR(i, 1, n){
        r[i].a=M[r[i].a];
        r[i].b=M[r[i].b];
    }
    sort(r+1, r+n+1, cmp);
    long long ans=0;
    FOR(i, 1, n){
        long long temp=r[i].h+get(1, 1, msize, 1, r[i].b-1);
        ans=max(ans, temp);
        update(1, 1, msize, r[i].a, temp);
    }
    writeln(ans);
}