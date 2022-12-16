#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int T,n;
bool isprime(int x){
    if(x<=1) return false;
    int kk=sqrt(x)+0.5;
    for(int i=2;i<=kk;i++){
        if(x%i==0) return false;
    }
    return true;
}

int main(){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(int k=n;;k++){
            if(isprime(k)&&(!isprime(k-n+1))){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if(i!=j) printf("%d ",1);
                        else printf("%d ",k-n+1);
                    }
                    puts("");
                }
                break;
            }
        }
    }
    return 0;
}