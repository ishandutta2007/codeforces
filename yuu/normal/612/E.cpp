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
#define taskname "E"
int n;
int p[1000001];
vector <vector <int> > cycle[1000001];
bool done[1000001];
int ans[1000001];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) read(p[i]);
    ///q[q[i]]=p[i]ss
    FOR(i, 1, n) if(!done[i]){
        vector <int> temp;
        temp.pb(i);
        done[i]=1;
        while(p[temp.back()]!=temp[0]){
            temp.pb(p[temp.back()]);
            done[temp.back()]=1;
        }
        reverse(temp.begin(), temp.end());
        cycle[temp.size()].pb(temp);
    }
    FOR(i, 2, n) if(cycle[i].size()){
        if(i%2){
            for(vector <int> &v: cycle[i]){
                int k=(i+1)/2;
                FFOR(j, 0, (i+1)/2){
                    p[v[j]]=v[k];
                    p[v[k]]=v[j+1];
                    k++;
                    k%=i;
                }
            }
        }
        else{
            if(cycle[i].size()%2){
                puts("-1");
                return 0;
            }
            FFOR(j, 1, cycle[i].size()){
                FFOR(k, 0, i){
                    p[cycle[i][j][k]]=cycle[i][j-1][k];
                    p[cycle[i][j-1][k]]=cycle[i][j][(k+1)%i];
                }
                j++;
            }
        }
    }
    FOR(i, 1, n) ans[p[i]]=i;
    FOR(i, 1, n){
        write(ans[i]);
        putchar(" \n"[i==n]);
    }
}