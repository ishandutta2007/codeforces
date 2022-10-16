#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
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
#define taskname "C"
string s, t;
int cnta[256];
int cntb[256];
char lowa, higha;
char lowb, highb;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    cin>>s>>t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    int n=s.size();
    s='0'+s;
    DFOR(i, (n+1)/2, 1)
        cnta[s[i]]++;
    t='0'+t;
    DFOR(i, n/2, 1)
        cntb[t[i]]++;
    FOR(i, 'a', 'z'){
        if(cnta[i])
            higha=i;
        if(cntb[i])
            highb=i;
    }
    DFOR(i, 'z', 'a'){
        if(cnta[i])
            lowa=i;
        if(cntb[i])
            lowb=i;
    }
    s=t="";
    FOR(i, 1, n){
        if(i%2){
            if(lowa>=highb){
                t+=higha;
                cnta[higha]--;
                while(higha>='a'&&cnta[higha]==0)
                    higha--;
            }
            else{
                s+=lowa;
                cnta[lowa]--;
                while(lowa<='z'&&cnta[lowa]==0)
                    lowa++;
            }
        }
        else{
            if(lowa>=highb){
                t+=lowb;
                cntb[lowb]--;
                while(lowb<='z'&&cntb[lowb]==0)
                    lowb++;
            }
            else{
                s+=highb;
                cntb[highb]--;
                while(highb>='a'&&cntb[highb]==0)
                    highb--;
            }
        }
    }
    reverse(t.begin(), t.end());
    cout<<s<<t;
}