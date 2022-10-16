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
#define taskname "C"
int cnt[2][1024];
int a;
int x, k, n;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(k);
    read(x);
    FOR(i, 1, n){
        read(a);
        cnt[0][a]++;
    }
    FOR(time, 1, k){
        int temp=0;
        int o=time%2;
        int l=1-o;
        FOR(i, 0, 1023)
            cnt[o][i]=0;
        FOR(i, 0, 1023){
            if(temp%2==0){
                cnt[o][i^x]+=(cnt[l][i]+1)/2;
                cnt[o][i]+=cnt[l][i]-(cnt[l][i]+1)/2;
            }
            else{
                cnt[o][i^x]+=(cnt[l][i])/2;
                cnt[o][i]+=cnt[l][i]-(cnt[l][i])/2;
            }
            temp+=cnt[l][i];
        }
    }
    int ansmin, ansmax;
    int l=k%2;
    FOR(i, 0, 1023)
        if(cnt[l][i]>0){
            ansmin=i;
            break;
        }
    DFOR(i, 1023, 0)
        if(cnt[l][i]>0){
            ansmax=i;
            break;
        }
    write(ansmax);
    putchar(' ');
    write(ansmin);
}