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
#define taskname "C"
#define next Tal
string s;
bool next[100000][26];
string u;
vector <char> v;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    cin>>s;
    if(s.size()==1){
        cout<<s;
        return 0;
    }
    for(char &c: s) c-='a';
    DFOR(i, s.size()-2, 0){
        FFOR(j, 0, 26) next[i][j]=next[i+1][j];
        next[i][s[i+1]]=1;
    }
    FFOR(i, 0, s.size()){
        v.pb(s[i]);
        while(!v.empty()){
            bool good=0;
            FFOR(j, 0, v.back()) if(next[i][j]){
                good=1;
                break;
            }
            if(!good){
                u+=char(v.back()+'a');
                v.pop_back();
            }
            else break;
        }
    }
    cout<<u;
}