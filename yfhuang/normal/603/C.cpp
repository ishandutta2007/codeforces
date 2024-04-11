//
//  main.cpp
//  div1C
//
//  Created by  on 15/12/24.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,k,a;

int Xor;

int Grundyodd(int x){
    if(x==1) return 1;
    else if(x==2) return 0;
    else if(x==3) return 1;
    else if(x==4) return 2;
    else if(x&1) return 0;
    else if(Grundyodd(x/2)==1) return 2;
    else return 1;
}

int Grundyeven(int x){
    if(x==1) return 1;
    else if(x==2) return 2;
    else if(x==3) return 0;
    else if(x==4) return 1;
    else if(x&1) return 0;
    else return 1;
}

int main(int argc, const char * argv[]) {
    scanf("%d%d",&n,&k);
    Xor=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        if(k&1) Xor^=Grundyodd(a);
        else Xor^=Grundyeven(a);
    }
    if(Xor) printf("Kevin\n");
    else printf("Nicky\n");
    return 0;
}