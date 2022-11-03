//
//  main.cpp
//  D
//
//  Created by  on 16/2/27.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int maxn=1005;

int a[maxn];

map<int,int> cnt;

int t[200];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    int ans=2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(a[i]==0&&a[j]==0) ans=max(ans,cnt[0]);
            else{
                t[0]=a[i];
                t[1]=a[j];
                int x=t[0]+t[1];
                int num=2;
                while(abs(x)<=1e9){
                    t[num++]=x;
                    x=t[num-2]+t[num-1];
                }
                t[num++]=x;
                cnt[t[0]]--;
                cnt[t[1]]--;
                for(int k=2;k<num;k++){
                    if(cnt.find(t[k])==cnt.end()||cnt[t[k]]==0){
                        ans=max(ans,k);
                        for(int l=0;l<k;l++){
                            cnt[t[l]]++;
                        }
                        break;
                    }
                    cnt[t[k]]--;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}