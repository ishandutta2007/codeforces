//
//  main.cpp
//  E
//
//  Created by  on 16/1/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int gcd(int a,int b){
    return (b==0)? a:gcd (b,a%b);
}

int n;
const int maxn=30;

int a[maxn];

char s[100005];

int main(int argc, const char * argv[]) {
    cin>>n;
    int odds=0;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        if(a[i]&1) odds++;
    }
    if(n==1){
        printf("%d\n",a[1]);
        for(int i=1;i<=a[1];i++)
            printf("a");
        printf("\n");
    }
    else{
        if(odds >= 2){
            printf("0\n");
            for(int i=1;i<=n;i++){
                for(int j=1;j<=a[i];j++){
                    printf("%c",'a'+i-1);
                }
            }
            printf("\n");
        }else{
            int loc=-1;
            for(int i=1;i<=n;i++)
                if(a[i]&1) loc=i;
            int g=a[1];
            for(int i=1;i<=n;i++)
                g=gcd(g,a[i]);
            printf("%d\n",g);
            if(g%2==0) g/=2;
            for(int k=1;k<=g;k++){
                for(int i=1; i<=n; i++)
                {
                    if(i==loc)continue;
                    for(int j=0; j<a[i]/(2*g); j++)
                        printf("%c",'a'+i-1);
                }
                for(int j=0; j<a[loc]/g; j++)
                    printf("%c",'a'+loc-1);
                for(int i=n; i>=1; i--)
                {
                    if(i==loc)continue;
                    for(int j=0; j<a[i]/(2*g); j++)
                        printf("%c",'a'+i-1);
                }
            }
            printf("\n");
        }
    }
    return 0;
}