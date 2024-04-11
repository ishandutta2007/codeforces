#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int n,m;
long long a,b;
long long x,y;

int main(){
    cin>>n>>a;
    int k;
    x=0;
    for(int i=1;i<=n;i++){
        cin>>k;
        x=x*a+k;
    }
    y=0;
    cin>>m>>b;
    for(int i=1;i<=m;i++){
        cin>>k;
        y=y*b+k;
    }
    if(x<y) printf("<\n");
    else if(x==y) printf("=\n");
    else if(x>y) printf(">\n");
}