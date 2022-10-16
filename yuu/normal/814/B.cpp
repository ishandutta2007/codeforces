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
#define taskname "B"
int n;
int a[1001];
int b[1001];
int ans[1001];
bool done[1001];
vector <int> pos;
vector <int> good;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) read(b[i]);
    int cnt=0;
    FOR(i, 1, n){
        if(a[i]!=b[i]) pos.pb(i);
        else{
            ans[i]=a[i];
            done[a[i]]=1;
        }
    }
    if(pos.size()==1){
        FOR(i, 1, n) if(!done[i]) good.pb(i);
        ans[pos[0]]=good[0];
    }
    else{
        FOR(i, 1, n) if(!done[i]) good.pb(i);
        if(a[pos[0]]==good[0]&&b[pos[1]]==good[1]){
            ans[pos[0]]=good[0];
            ans[pos[1]]=good[1];
        }
        else if(b[pos[0]]==good[0]&&a[pos[1]]==good[1]){
            ans[pos[0]]=good[0];
            ans[pos[1]]=good[1];
        }
        else if(a[pos[0]]==good[1]&&b[pos[1]]==good[0]){
            ans[pos[0]]=good[1];
            ans[pos[1]]=good[0];
        }
        else if(b[pos[0]]==good[1]&&a[pos[1]]==good[0]){
            ans[pos[0]]=good[1];
            ans[pos[1]]=good[0];
        }
    }
    FOR(i, 1, n){
        write(ans[i]);
        putchar(' ');
    }
}