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
using ll=long long;
using ld=long double;
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
int n, k;
pair <int, int> p[1000001];
vector <pair <int, int>> ans;
priority_queue <int, vector <int>, greater<int>> q;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(k);
    FOR(i, 1, n){
        read(p[i].first);
        read(p[i].second);
    }
    sort(p+1, p+n+1);
    bool inside=0;
    FOR(i, 1, n){
        int j=i;
        while((j<n)&&(p[j+1].first==p[i].first)) j++;
        while((!q.empty())&&(q.top()<p[i].first)){
            int top=q.top();
            if(k<=0) ans.back().second=top;
            while((!q.empty())&&(q.top()==top)){
                k++;
                q.pop();
            }
            if(k>0) inside=0;
        }
        FOR(l, i, j){///
            k--;
            q.push(p[l].second);
        }
        if(k<=0){
            if(inside) ans.back().second=p[i].first;
            else{
                inside=1;
                ans.pb(mp(p[i].first, p[i].first));
            }
        }
        i=j;
    }
    if(k<=0) while((!q.empty())){
        int top=q.top();
        ans.back().second=top;
        while((!q.empty())&&(q.top()==top)){
            k++;
            q.pop();
        }
        if(k>0) break;
    }
    writeln(ans.size());
    for(auto p: ans){
        write(p.first);
        putchar(' ');
        writeln(p.second);
    }
}