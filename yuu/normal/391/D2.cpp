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
#define taskname "391D2"
int n, m;
class vertical{
public:
    int x, y, l;
} v[50001];
int x[50001];
int y[50001];
int l[50001];
class data{
public:
    int a, x;
    data(int _a, int _x){
        a=_a;
        x=_x;
    }
};
class cmp{
public:
    bool operator ()(data A, data B){
        return A.x>B.x;
    }
};
priority_queue <data, vector <data>, cmp> to_add;
priority_queue <data, vector <data>, cmp> to_take;
multiset <int> s;
bool check(int sz){
    s.clear();
    while((!to_add.empty())) to_add.pop();
    while((!to_take.empty())) to_take.pop();
    FOR(i, 1, m){
        if(x[i]+sz<=x[i]+l[i]-sz){
            to_add.push(data(y[i], x[i]+sz));
            to_take.push(data(y[i], x[i]+l[i]-sz+1));
        }
    }
    int low, high;
    FOR(i, 1, n){
        low=v[i].y+sz;
        high=v[i].y+v[i].l-sz;
        if(low>high) continue;
        while((!to_add.empty())&&(to_add.top().x<=v[i].x)){
            s.insert(to_add.top().a);
            to_add.pop();
        }
        while((!to_take.empty())&&(to_take.top().x<=v[i].x)){
            s.erase(s.find(to_take.top().a));
            to_take.pop();
        }
        if(s.empty()) continue;
        if(*s.rbegin()<low) continue;
        if(*s.lower_bound(low)<=high) return 1;
    }
    return 0;
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(m);
    FOR(i, 1, n){
        read(v[i].x);
        read(v[i].y);
        read(v[i].l);
    }
    sort(v+1, v+n+1, [](vertical A, vertical B){
        return A.x<B.x;
    });
    FOR(i, 1, m){
        read(x[i]);
        read(y[i]);
        read(l[i]);
    }
    int low=1, high=100000000, ans=0, mid;
    while(low<=high){
        mid=(low+high)/2;
        if(check(mid)){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    writeln(ans);
}