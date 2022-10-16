#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
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
#define taskname "C"
int n;
vector <pair <ll, ll> > v;
priority_queue <ll, vector <ll>, greater <ll> > q;
ll ans[200001];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    v.resize(n);
    for(auto &p: v){
        read(p.first);
        read(p.second);
    }
    sort(v.begin(), v.end());
    ll old;
    FFOR(i, 0, v.size()){
        while((!q.empty())&&(q.top()<v[i].first)){
            ans[q.size()]+=q.top()-old+1;
            old=q.top()+1;
            q.pop();
        }
        ans[q.size()]+=v[i].first-old;
        old=v[i].first;
        int j=i;
        while((j+1<v.size())&&(v[j+1].first==v[j].first)) j++;
        FOR(k, i, j) q.push(v[k].second);
        i=j;
    }
    while(!q.empty()){
        ans[q.size()]+=q.top()-old+1;
        old=q.top()+1;
        q.pop();
    }
    FOR(i, 1, n){
        write(ans[i]);
        putchar(" \n"[i==n]);
    }
}