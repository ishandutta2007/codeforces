#include <stdio.h>
#include <locale>
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while(!isdigit(c=getchar())&&c!='-');
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
template <typename T> inline writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline writeln(T x){
    write(x);
    putchar('\n');
}
#include <algorithm>
using namespace std;
int c[200001];
int d[200001];
int maxdiv2=-99999999;
int mindiv1=99999999;
int rating=0;
int n;
bool inf=1;
int main(){
//    freopen("C.INP", "r", stdin);
    read(n);
    for(int i=1; i<=n; i++){
        read(c[i]);
        read(d[i]);
        if(d[i]==2)
            inf=0;
    }
    if(inf){
        puts("Infinity");
        return 0;
    }
    if(d[1]==1)
        mindiv1=0;
    else maxdiv2=0;
    for(int i=1; i<n; i++){
        rating+=c[i];
        if(d[i+1]==1){
            if(c[i]<=0&&d[i]==2){
                puts("Impossible");
                return 0;
            }
            mindiv1=min(mindiv1, rating);
        }
        else{
            if(c[i]>=0&&d[i]==1){
                puts("Impossible");
                return 0;
            }
            maxdiv2=max(maxdiv2, rating);
        }
        if(mindiv1<=maxdiv2){
            puts("Impossible");
            return 0;
        }
    }
    rating+=c[n];
    rating+=1899-maxdiv2;
    write(rating);
}