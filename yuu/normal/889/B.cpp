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
#define taskname "B"
#define next _next
#define prev _prev
int n;
string s[100001];
int last[256];
bool needed[256];
char next[256];
char prev[256];
bool done[256];
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    cin>>n;
    FOR(i, 1, n){
        cin>>s[i];
        for(char c: s[i]){
            if(last[c]==i){
                puts("NO");
                return 0;
            }
            needed[c]=1;
            last[c]=i;
        }
    }
    FOR(i, 1, n){
        FFOR(j, 1, s[i].size()){
            if(prev[s[i][j]]){
                if(prev[s[i][j]]!=s[i][j-1]){
                    puts("NO");
                    return 0;
                }
            }
            else prev[s[i][j]]=s[i][j-1];
            if(next[s[i][j-1]]){
                if(next[s[i][j-1]]!=s[i][j]){
                    puts("NO");
                    return 0;
                }
            }
            else next[s[i][j-1]]=s[i][j];
        }
    }
    vector <string> ans;
    FOR(c, 'a', 'z') if(needed[c]&&!done[c]){
        char a=c;
        while(prev[a]){
            a=prev[a];
            if(a==c){
                puts("NO");
                return 0;
            }
        }
        char b=a;
        ans.pb("");
        ans.back()+=a;
        done[a]=1;
        while(next[b]){
            b=next[b];
            if(done[b]){
                puts("NO");
                return 0;
            }
            done[b]=1;
            ans.back()+=b;
        }
    }
    sort(ans.begin(), ans.end(), [](string s, string t){
        return (s+t)<(t+s);
    });
    for(string s: ans) cout<<s;
}