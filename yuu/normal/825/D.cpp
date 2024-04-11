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
#define taskname "D"
string s, t;
int cnts[256];
int cntt[256];
int cnt[256];
int update[256];
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    cin>>s>>t;
    FFOR(i, 0, s.size()) cnts[s[i]]++;
    FFOR(i, 0, t.size()) cntt[t[i]]++;
    int ans=s.size();
    FOR(i, 'a', 'z') if(cntt[i]) ans=min(ans, cnts[i]/cntt[i]);
    FOR(i, 'a', 'z') cnts[i]-=cntt[i]*ans;
    while(cnts['?']>0){
        FOR(i, 'a', 'z'){
            if(cnts[i]>=cntt[i]) cnts[i]-=cntt[i], update[i]=0;
            else{
                update[i]=cntt[i]-cnts[i];
                cnts['?']-=update[i];
                cnts[i]=0;
            }
        }
        if(cnts['?']>=0) FOR(i, 'a', 'z') cnt[i]+=update[i];
    }
    char c='a';
    FFOR(i, 0, s.size()){
        if(s[i]=='?'){
            while(c<='z'&&cnt[c]==0) c++;
            if(c>'z') s[i]='a';
            else{
                s[i]=c;
                cnt[c]--;
            }
        }
    }
    cout<<s;
}