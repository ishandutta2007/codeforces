#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define ll long long
#define int long long
 
int a[1000010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int pos=0;
    for(int i=1;i<=n;i++){
        cin>>a[i],pos=a[i]==-1?i:pos;
        if(a[i]==-1)a[i]=2e9;
    }
 
    int cnt=0;
    int tmp=n;
    while(tmp!=1){
        tmp/=2;
        cnt++;
    }
 
    int cnt2=0;
    while((1<<(cnt2+1))<=pos)cnt2++;
    
    int now=n/2;
    int ans=a[n];
    if(pos==n){
        cout<<0<<endl;
        return 0;
    }
 
    a[n]=2e9;
    for(int i=cnt-2;i>=cnt2;i--){
        int minn=2e9,mpos=0;
        for(int i=n;i>=now;i--){
            if(minn>a[i]){
                minn=a[i];
                mpos=i;
            }
        }
        now-=1<<i;
        // cout<<i<<" "<<minn<<endl;
        ans+=minn;
        a[mpos]=2e9;
    }
 
    cout<<ans<<endl;
}