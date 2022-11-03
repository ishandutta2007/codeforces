//
//  main.cpp
//  B
//
//  Created by  on 15/12/19.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
const int maxn=1005;

int a[maxn];

bool a1[maxn];

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int t=n;
    int b=0;
    int c=-1;
    memset(a1,false,sizeof(a1));
    while(t){
        c++;
        for(int i=1;i<=n;i++){
            if(!a1[i]&&b>=a[i]){
                a1[i]=true;
                b++;
                t--;
            }
        }
        if(!t) break;
        c++;
        for(int i=n;i>=1;i--){
            if(!a1[i]&&b>=a[i]){
                a1[i]=true;
                b++;
                t--;
            }
        }
    }
    printf("%d\n",c);
    return 0;
}