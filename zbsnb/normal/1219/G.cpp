#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

void pr(ll *a,int n,int m){
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<(a+(m+1)*i)[j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n,m;cin>>n>>m;
    ll a[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    ll ans=0;

    //cout<<"s2"<<endl;

    ll sum1[n+1]={};
    ll sum2[m+1]={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum1[i]+=a[i][j];
            sum2[j]+=a[i][j];
        }
    }

    //cout<<"s1"<<endl;

    ll b[n+1][m+1]={};
    ll c[n+1][m+1]={};
    ll d[m+1][n+1]={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j]=sum1[i]+sum2[j]-2*a[i][j];
            c[i][j]=sum1[i]+3*sum2[j]-3*a[i][j];
            d[j][i]=3*sum1[i]+sum2[j]-3*a[i][j];
        }
    }

    //pr((ll *)a,n,m);
    //pr((ll *)b,n,m);
    //pr((ll *)c,n,m);
    //pr((ll *)d,m,n);

    sort(sum1+1,sum1+n+1);
    sort(sum2+1,sum2+m+1);

    ll tmp1=0,tmp2=0;
    for(int i=n;i>=1&&i>=n-3;i--)tmp1+=sum1[i];
    for(int i=m;i>=1&&i>=m-3;i--)tmp2+=sum2[i];

    //cout<<tmp1<<" "<<tmp2<<endl;

    ans=max(ans,tmp1);
    ans=max(ans,tmp2);

    for(int i=1;i<=n;i++){
        sort(c[i]+1,c[i]+m+1);
        ll tmp=0;
        for(int j=m;j>=1&&j>=m-2;j--)tmp+=c[i][j];
        ans=max(ans,tmp/3);
        //cout<<i<<" "<<tmp/3<<endl;
    }
    for(int i=1;i<=m;i++){
        sort(d[i]+1,d[i]+n+1);
        ll tmp=0;
        for(int j=n;j>=1&&j>=n-2;j--)tmp+=d[i][j];
        ans=max(ans,tmp/3);
        //cout<<i<<" "<<tmp/3<<endl;
    }

    if(n<=m){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ll maxn1=-1,maxn2=-1;
                for(int k=1;k<=m;k++){
                    ll tmp=b[i][k]+b[j][k];
                    if(tmp>maxn1){
                        maxn2=maxn1;
                        maxn1=tmp;
                    }
                    else if(tmp>maxn2){
                        maxn2=tmp;
                    }
                }
                ans=max(ans,(maxn1+maxn2)/2);
            }
        }
    }
    else{
         for(int i=1;i<=m;i++){
            for(int j=i+1;j<=m;j++){
                ll maxn1=-1,maxn2=-1;
                for(int k=1;k<=n;k++){
                    ll tmp=b[k][i]+b[k][j];
                    if(tmp>maxn1){
                        maxn2=maxn1;
                        maxn1=tmp;
                    }
                    else if(tmp>maxn2){
                        maxn2=tmp;
                    }
                }
                ans=max(ans,(maxn1+maxn2)/2);
            }
        }
    }

    cout<<ans<<endl;

}