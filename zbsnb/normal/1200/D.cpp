#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

int n,k;
int sumr[2010],sumc[2010];
int hr[2010][2010],hc[2010][2010];
int rp[2010][2010],cp[2010][2010];
int tot1[2010][2010],tot2[2010][2010];
#define lowb(x) ((x)&(-x))
void upd(int x,int h[]){
    for(;x<=n;x+=lowb(x))h[x]++;
}
int que(int x,int h[]){
    int ret=0;
    for(;x>=1;x-=lowb(x))ret+=h[x];
    return ret;
}

int main(){
    cin>>n>>k;
    int pp=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char tmp;cin>>tmp;
            if(tmp=='B'){
                sumr[i]++;
                sumc[j]++;
                upd(j,hr[i]);
                upd(i,hc[j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(sumc[i]==0)pp++;
        if(sumr[i]==0)pp++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-k+1;j++){
            rp[i][j]=sumr[i]!=0&&(sumr[i]-(que(j+k-1,hr[i])-que(j-1,hr[i])))==0;
            tot1[i][j+k-1]=tot1[i-1][j+k-1]+rp[i][j];
            if(i>k)tot1[i][j+k-1]-=rp[i-k][j];
        }
    }

    for(int j=1;j<=n;j++){
        for(int i=1;i<=n-k+1;i++){
            cp[i][j]=sumc[j]!=0&&(sumc[j]-(que(i+k-1,hc[j])-que(i-1,hc[j])))==0;
            tot2[i+k-1][j]=tot2[i+k-1][j-1]+cp[i][j];
            if(j>k)tot2[i+k-1][j]-=cp[i][j-k];
        }
    }

    int ans=0;
    for(int i=k;i<=n;i++){
        for(int j=k;j<=n;j++){
            //cout<<i<<" "<<j<<" "<<tot1[i][j]<<tot2[i][j]<<endl;
            ans=max(ans,tot1[i][j]+tot2[i][j]);
        }
    }

    cout<<ans+pp<<endl;

}