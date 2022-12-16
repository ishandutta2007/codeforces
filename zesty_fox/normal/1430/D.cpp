#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=200010;
int T,n,len[N],vis[N];
char s[N];
int main(){
    cin>>T;
    while(T--){
        scanf("%d%s",&n,s+1);
        for(int i=1;i<=n;i++) len[i]=0,vis[i]=1;
        /*if(n==1){
            puts("1");
            continue;
        }*/
        int d=0,last=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(last!=s[i]){
                d++,len[d]=1;
            }
            else len[d]++;
            last=s[i];
        }
        int ans=0,l=1,ll=n-d,kkk=1;
        while(len[kkk]==1&&kkk<=d) kkk++;
        for(;l<=d;){
            if(len[l]==1){
                if(kkk<=d){
                    len[kkk]--;
                    while(len[kkk]==1&&kkk<=d) kkk++;
                    l++;
                }
                else{
                    l+=2;
                }
            }
            else{
                l++;
                kkk++;
                while(len[kkk]==1&&kkk<=d) kkk++;
            }
            ans++;
        }
        printf("%d\n",ans);
nxt:;
        /*
        if(d<r) printf("%d\n",d);
        else printf("%d\n",((d+r)&1)?(d+r-1)/2:(d+r)/2);
        */
    }
    return 0;
}