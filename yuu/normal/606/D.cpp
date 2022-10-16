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
#define taskname "D"
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
struct edge{
    int first, second, third;
} e[100001];
bool cmp(edge a, edge b){
    return (a.first<b.first)||(a.first==b.first&&a.second>b.second);
}
int curver=1;
vector <int> v;
vector <int> adj[100001];
vector <pair<int, int> > edgetoadd;
int overallsize=0;
int bound;
pair<int, int> ans[100001];
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(m);
    bound=m-n+1;
    FOR(i, 1, m){
        read(e[i].first);
        read(e[i].second);
        e[i].third=i;
    }
    sort(e+1, e+m+1, cmp);
    FOR(i, 1, m){
        if(e[i].second==0){
            if(edgetoadd.empty()){
                puts("-1");
                return 0;
            }
            ans[e[i].third].first=edgetoadd.back().first;
            ans[e[i].third].second=edgetoadd.back().second;
            edgetoadd.pop_back();
        }
        else{
            ans[e[i].third].first=1;
            ans[e[i].third].second=++curver;
            DFOR(i, curver-1, 2){
                if(overallsize>=bound) break;
                edgetoadd.push_back(make_pair(curver, i));
                overallsize++;
            }
        }
    }
    FOR(i, 1, m){
        write(ans[i].first);
        putchar(' ');
        writeln(ans[i].second);
    }
}