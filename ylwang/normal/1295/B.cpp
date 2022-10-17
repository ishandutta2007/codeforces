#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int T,n,x,s,ans;
int sum[100010],mod;
char ch;
int main() {
    scanf("%d",&T);
    for(int ttt=1; ttt<=T; ttt++) {
        ans=0;
        scanf("%d%d",&n,&x);
        for(int i=1; i<=n; i++) {
            cin>>ch;
            sum[i]=sum[i-1];
            if(ch=='0') sum[i]++;
            if(ch=='1') sum[i]--;
        }
        mod=sum[n];
        if(mod==0) {
            for(int i=0; i<=n; i++)
                if(sum[i]==x) {
                    ans++;
                    break;
                }
            if(ans)
                puts("-1");
            else
                puts("0");
            continue;
        }
        else {
            for(int i=1;i<=n;i++)
                if(abs(x-sum[i])%abs(mod)==0&&(x-sum[i])/mod>=0)
                  ans++;
            if(x==sum[0])
              ans++;
            printf("%d\n",ans);
        }
    }
    return 0;
}