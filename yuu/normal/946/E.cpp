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
#define taskname "E"
string s;
string ans;
int cnt[256];
string construct(int u){
    string res;
    FOR(i, '0', '9') cnt[i]=0;
    FFOR(i, 0, u){
        res+=s[i];
        cnt[s[i]]=1-cnt[s[i]];
    }
    int x=0;
    FOR(i, '0', '9') x+=cnt[i];
    x=s.size()-u-x;
    if(x<0) return ans;
    if((!cnt[s[u]-1])&&(x>1)){
        x-=2;
        cnt[s[u]-1]+=2;
    }
    cnt['9']+=x;
    DFOR(i, s[u]-1, '0'){
        if(cnt[i]){
            cnt[i]--;
            res+=i;
            break;
        }
    }
    if(res.size()==u) return ans;
    x='9';
    FFOR(i, u+1, s.size()){
        while(!cnt[x]) x--;
        cnt[x]--;
        res+=x;
    }
    return res;
}
void solve(){
    cin>>s;
    if(s[0]=='1'){
        FFOR(i, 1, s.size()-1) if(s[i]>'0') goto line0;
        if(s.back()>'1') goto line0;
        FFOR(i, 2, s.size()) cout<<"9";
        cout<<"\n";
        return;
        line0:;
    }
    ans.resize(s.size());
    for(char &c: ans) c='0';
    DFOR(i, s.size()-1, 0){
        if(s[i]!='0'){
            ans=max(ans, construct(i));
            if(ans[0]!='0') break;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    int t;
    read(t);
    while(t--) solve();
}