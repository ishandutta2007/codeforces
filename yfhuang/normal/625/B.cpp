//
//  main.cpp
//  B
//
//  Created by  on 16/2/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char str[100005];
char ch[35];

struct qujian{
    int l,r;
    bool operator < (const qujian& rhs) const{
        return l<rhs.l;
    }
}a[100005];

int main(int argc, const char * argv[]) {
    scanf("%s",str+1);
    int l1=strlen(str+1);
    scanf("%s",ch+1);
    int l2=strlen(ch+1);
    int cnt=0;
    for(int i=1;i<=l1;i++){
        if(str[i]==ch[1]){
            bool flag=true;
            for(int j=0;j<l2;j++){
                if(str[i+j]!=ch[1+j])
                    flag=false;
            }
            if(flag){
                a[cnt].l=i;
                a[cnt++].r=i+l2-1;
            }
        }
    }
    sort(a,a+cnt);
    int ans=0;
    int p=-1;
    for(int i=0;i<cnt;i++){
        if(p<a[i].l){
            p=a[i].r;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}