#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int T,n,vis[300010],ti;
char s[300010];
int main(){
    cin>>T;
    while(T--){
        ++ti;
        scanf("%d%s",&n,s);
        int flg1=1,flg2=1,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='<') flg1=0;
            if(s[i]=='>') flg2=0;
        }
        if(flg1||flg2){
            printf("%d\n",n);
            continue;
        }
        else{
            for(int i=0;i<n;i++){
                if(s[i]=='-') vis[i]=vis[(i+1)%n]=ti;
            }
            for(int i=0;i<n;i++){
                if(vis[i]>=ti) ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}