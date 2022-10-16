#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
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
int n, m;
string name[21];
string ss;
vector <string> s[21];
bool display[201];
void solve(int i){
    m=s[i].size();
    sort(s[i].begin(), s[i].end(), [](string a, string b){
        return a.size()<b.size();
    });
    cout<<name[i];
    FFOR(j, 0, m) display[j]=1;
    FFOR(j, 0, m){
        reverse(s[i][j].begin(), s[i][j].end());
        FFOR(k, 0, j) if(s[i][j].find(s[i][k])==0) display[k]=0;
    }
    int res=0;
    FFOR(j, 0, m) if(display[j]) res++;
    cout<<' '<<res;
    FFOR(j, 0, m) if(display[j]){
        reverse(s[i][j].begin(), s[i][j].end());
        cout<<' '<<s[i][j];
    }
    cout<<'\n';
}
map <string, int> M;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    cin>>n;
    int res=0;
    FOR(i, 1, n){
        cin>>name[i];
        if(M.find(name[i])==M.end()){
            M[name[i]]=i;
            res++;
        }
        cin>>m;
        FOR(j, 1, m){
            cin>>ss;
            s[M[name[i]]].pb(ss);
        }
    }
    writeln(res);
    FOR(i, 1, n) if(M[name[i]]==i) solve(i);
}