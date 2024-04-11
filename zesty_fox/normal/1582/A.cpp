#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
int a,b,c;
inline void work(){
    a=read()&1,b=read()&1,c=read()&1;
    puts(a+c%2==1?"1":"0");
}
int main(){
    int test=read();
    while(test--)work();
    return 0;
}