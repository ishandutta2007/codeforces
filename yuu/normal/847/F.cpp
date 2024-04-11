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
#define taskname "F"
int n, m, k;
int c[101];
int last[101];
int a, g;
bool cmp(pair <int, int> a, pair <int, int> b){
    if(a.first!=b.first) return a.first>b.first;
    return a.second<b.second;
}
vector <pair <int, int> > v;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    if(n==1){
        write(1);
        return 0;
    }
    read(k);
    read(m);
    read(a);
    FOR(i, 1, a){
        read(g);
        c[g]++;
        last[g]=i;
    }
    FOR(i, 1, n){
        v.clear();
        FFOR(j, 1, i) v.pb(mp(c[j], last[j]));
        FOR(j, i+1, n) v.pb(mp(c[j], last[j]));
        sort(v.begin(), v.end(), cmp);
        pair <int, int> p=mp(c[i], last[i]);
        if(c[i]){
            int d=m-a;
            int j=0;
            while(j<v.size()){
                if(cmp(v[j], p)){
                    j++;
                    continue;
                }
                if(d>p.first-v[j].first){
                    d-=p.first-v[j].first+1;
                    j++;
                }
                else break;
            }
            if(j<k){
                write(1);
                putchar(' ');
                continue;
            }
        }
        if(a<m){
            v.pb(mp(c[i]+m-a, m));
            sort(v.begin(), v.end(), cmp);
            int j=0;
            while(j<v.size()){
                if(v[j].second==m) break;
                j++;
            }
            if(j<k) write(2);
            else write(3);
            putchar(' ');
        }
        else{
            if(c[i]==0){
                write(3);
                putchar(' ');
                continue;
            }
            int x=0;
            FFOR(j, 0, v.size()) if(cmp(v[j], p)) x++;
            if(x<k) write(2);
            else write(3);
            putchar(' ');
        }
    }
}