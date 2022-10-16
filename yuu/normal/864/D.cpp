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
#define taskname "D"
int n;
int a[200001];
int c[200001];
bool done[200001];
queue <int> q;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    FOR(i, 1, n){
        read(a[i]);
        c[a[i]]++;
    }
    int ans=0;
    FOR(i, 1, n){
        if(c[i]==0) q.push(i);
        else ans+=c[i]-1;
    }
    writeln(ans);
    FOR(i, 1, n){
        if(q.empty()) break;
        if(done[a[i]]){
            a[i]=q.front();
            q.pop();
            continue;
        }
        if(c[a[i]]==1) continue;
        if(a[i]<q.front()) done[a[i]]=1;
        else{
            c[a[i]]--;
            a[i]=q.front();
            q.pop();
        }
    }
    FOR(i, 1, n){
        if(i>1) putchar(' ');
        write(a[i]);
    }
}