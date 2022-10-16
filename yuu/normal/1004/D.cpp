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
#define taskname "D"
int t;
int cnt[1000001];
int temp[1000001];
int maxa=0;
void check(int h, int x, int y){
    int w=(t/h);
    if(w*h!=t) return;
    if((x<0)||(y<0)) return;
    if((x>h)||(y>w)) return;
    FOR(i, 1, maxa) temp[i]=0;
    if(x-1+y-1>maxa) return;
    if(x-1+w-y>maxa) return;
    if(h-x+y-1>maxa) return;
    if(h-x+w-y>maxa) return;
    FOR(i, 1, x) FOR(j, 1, y) temp[x-i+y-j]++;
    FOR(i, 1, x) FOR(j, y+1, w) temp[x-i+j-y]++;
    FOR(i, x+1, h) FOR(j, 1, y) temp[i-x+y-j]++;
    FOR(i, x+1, h) FOR(j, y+1, w) temp[i-x+j-y]++;
    FOR(i, 1, maxa) if(temp[i]!=cnt[i]) return;
    write(h);
    putchar(' ');
    writeln(w);
    write(x);
    putchar(' ');
    writeln(y);
    exit(0);
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(t);
    {
        int a;
        FFOR(i, 0, t){
            read(a);
            cnt[a]++;
            maxa=max(maxa, a);
        }
    }
    if(cnt[0]!=1){
        puts("-1");
        return 0;
    }
    if(t==1){
        puts("1 1");
        puts("1 1");
        return 0;
    }
    FOR(i, 1, t){
        if(cnt[i]>(i*4)){
            puts("-1");
            return 0;
        }
        if(cnt[i]<((i-1)*4)){
            puts("-1");
            return 0;
        }
        if(cnt[i]==i*4) continue;
        else{
            int re=cnt[i]-(i-1)*4;
            if(re<=1){
                check(i*2-1, i, i);
            }
            else if(re==2){
                check(i*2-1, i, maxa-(i-1)+1);
                int w;
                FOR(h, i*2, t) if(t%h==0){
                    w=t/h;
                    if(w<i*2) break;
                    check(h, i, i);
                }
            }
            else{///re==3
                int w;
                FOR(h, i*2+1, t) if(t%h==0){
                    w=t/h;
                    if(w<i*2) break;
                    check(h, maxa-(w-i)+1, i);
                }
            }
            break;
        }
    }
    puts("-1");
    return 0;
}