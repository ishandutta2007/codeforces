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
#define taskname "E"
int q, p, l, o;
struct node{
    int c;
    int g[2];
} T[3200000];
int n;
void add(int u){
    vector <int> v;
    while(u>0){
        v.pb(u%2);
        u/=2;
    }
    while(v.size()<28) v.pb(0);
    int inode=0;
    while(!v.empty()){
        if(!T[inode].g[v.back()]) T[inode].g[v.back()]=++n;
        inode=T[inode].g[v.back()];
        T[inode].c++;
        v.pop_back();
    }
}
void take(int u){
    vector <int> v;
    while(u>0){
        v.pb(u%2);
        u/=2;
    }
    while(v.size()<28) v.pb(0);
    int inode=0;
    while(!v.empty()){
        inode=T[inode].g[v.back()];
        T[inode].c--;
        v.pop_back();
    }
}
int get(int u, int l){
    vector <int> v;
    while(u>0){
        v.pb(u%2);
        u/=2;
    }
    while(v.size()<28) v.pb(0);
    vector <int> s;
    while(l>0){
        s.pb(l%2);
        l/=2;
    }
    while(s.size()<28) s.pb(0);
    int res=0;
    int inode=0;
    while(!v.empty()){
        if(s.back()){
            res+=T[T[inode].g[v.back()]].c;
            inode=T[inode].g[1-v.back()];
        }
        else inode=T[inode].g[v.back()];
        s.pop_back();
        v.pop_back();
        if(inode==0) break;
    }
    return res;
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(q);
    while(q--){
        read(o);
        read(p);
        if(o==1) add(p);
        else if(o==2) take(p);
        else{
            read(l);
            writeln(get(p, l));
        }
    }
}