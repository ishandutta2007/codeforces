#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
using namespace std;

void Solve(){
    int a,b;
    scanf("%d%d",&a,&b);
    if(a<b)swap(a,b);
    if((a-b)&1){puts("-1");return;}
    if(a==0&&b==0){puts("0");return;}
    if(a==b){puts("1");return;}
    puts("2");
}

int main() {
    int T;
    scanf("%d",&T);
    for(;T--;)Solve();
    return 0;
}