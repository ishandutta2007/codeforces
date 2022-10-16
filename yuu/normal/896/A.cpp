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
#define taskname "A"
const string s="What are you doing at the end of the world? Are you busy? Will you save us?";
const string t1="What are you doing while sending ";
const string t2="? Are you busy? Will you send ";
const string t3="?";
const int sz=t1.size()+t2.size()+t3.size()+4;
ll length[100001];
int q, n;
ll k;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(q);
    length[0]=s.size();
    FOR(i, 1, 100000){
        length[i]=length[i-1]*2+sz;
        if(length[i]>2e18) length[i]=2e18;
    }
    while(q--){
        read(n);
        read(k);
        if(length[n]<k){
            putchar('.');
            goto line0;
        }
        while(n>0){
            if(k<=t1.size()){
                putchar(t1[k-1]);
                goto line0;
            }
            k-=t1.size();
            if(k==1){
                putchar('"');
                goto line0;
            }
            k--;
            if(k<=length[n-1]){
                n--;
                continue;
            }
            k-=length[n-1];
            if(k==1){
                putchar('"');
                goto line0;
            }
            k--;
            if(k<=t2.size()){
                putchar(t2[k-1]);
                goto line0;
            }
            k-=t2.size();
            if(k==1){
                putchar('"');
                goto line0;
            }
            k--;
            if(k<=length[n-1]){
                n--;
                continue;
            }
            k-=length[n-1];
            if(k==1){
                putchar('"');
                goto line0;
            }
            putchar('?');
            goto line0;
        }
        putchar(s[k-1]);
        line0:;
    }
}