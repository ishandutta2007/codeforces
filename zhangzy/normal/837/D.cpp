#include<bits/stdc++.h>
using namespace std;
int f[233][6666],n,k,a,b,ans;
long long x;

void R(int &x,int y){
    x=max(x,y);
}

int main(){
    memset(f,-1,sizeof(f));
    f[0][0]=0;
    scanf("%d%d",&n,&k);
    for (int nnd=1;nnd<=n;nnd++){
        scanf("%lld",&x);
        a=0;b=0;
        while (x%5==0){
            x/=5;
            a++;
        }
        while (x%2==0){
            x/=2;
            b++;
        }
        
        for (int i=k-1;i>=0;i--){
            for (int j=6600;j>=0;j--){
                if (f[i][j]>=0){
                    R(f[i+1][j+a],f[i][j]+b);
                }
            }
        }
    }
    
    ans=0;
    for (int i=0;i<=6600;i++){
        R(ans,min(i,f[k][i]));
    }
    printf("%d",ans);
}