//
//  main.cpp
//  E
//
//  Created by  on 15/12/13.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int n;

const int maxn=2000+16;
const int maxk=2e6+5;

int a[maxn],b[maxn],mk[maxn];
int x[maxk],y[maxk];

int t=0,ans=0;

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        mk[b[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int val=b[i];
        int h;
        for(int j=1;j<=n;j++)
            if(a[j]==val)
            {
                h=j;
                break;
            }
        int p=h;
        for(int j=h-1;j>=i;j--){
            if(mk[a[j]]>=p){
                ans+=p-j;
                t++;
                x[t]=j;
                y[t]=p;
                swap(a[p],a[j]);
                p=j;
            }
        }
        
    }
    cout<<ans<<endl;
    cout<<t<<endl;
    for(int i=1;i<=t;i++){
        printf("%d %d\n",x[i],y[i]);
    }
    return 0;
}