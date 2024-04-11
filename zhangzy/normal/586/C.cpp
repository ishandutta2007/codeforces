#include<bits/stdc++.h>
using namespace std;
int n,a[5200],b[5200],c[5200],ans=0,die[5200]={0};

void godie(int x){
    die[x]=1;
    for (int i=x+1;i<=n;i++){
        if (!die[i]){
            c[i]-=b[x];
            if (c[i]<0){
                godie(i);
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    int t;
    for (int i=1;i<=n;i++){
        if (!die[i]){
            ans++;
            t=a[i];
            for (int j=i+1;j<=n&&t>0;j++){
                if (!die[j]){
                    c[j]-=t;
                    t--;
                }
            }
            for (int j=i+1;j<=n;j++){
                if (c[j]<0&&!die[j]){
                    godie(j);
                }
            }
        }
    }
    printf("%d\n",ans);
    for (int i=1;i<=n;i++){
        if (!die[i]){
            printf("%d ",i);
        }
    }
}