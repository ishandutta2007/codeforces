#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int aa[200010];
ll sum[200010];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++)cin>>aa[i];
        int x,a,y,b;cin>>x>>a>>y>>b;
        if(x<y){
            swap(a,b);
            swap(x,y);
        }
        ll k;cin>>k;
        sort(aa+1,aa+n+1);
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+aa[n+1-i];
        }
        int cnt=0,cnta=0,cntb=0;
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(i%a==0&&i%b==0)cnt++;
            else{
                if(i%a==0)cnta++;
                if(i%b==0)cntb++;
            }
            //cout<<i<<cnt<<cnta<<cntb<<endl;
            //cout<<sum[cnt+cnta+cntb]<<sum[cnt+cnta]<<endl;
            if(sum[cnt]*(x+y)+(sum[cnt+cnta]-sum[cnt])*x+(sum[cnt+cnta+cntb]-sum[cnt+cnta])*y>=100*k){
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }

}