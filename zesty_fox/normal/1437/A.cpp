#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int T,l,r;
int main(){
    cin>>T;
    while(T--){
        scanf("%d%d",&l,&r);
        puts(r>=l*2?"NO":"YES");
    }
    return 0;
}