#include<iostream>
using namespace std;
char s[600010];
int a[600010];
int main(){
    int n;cin>>n>>s+1;
    for(int i=n+1;i<2*n;i++)s[i]=s[i-n];
    for(int i=1;i<2*n;i++){
        a[i]=a[i-1]+(s[i]=='('?1:-1);
    }
    if(a[n]!=0){
        cout<<0<<endl;
        cout<<"1 1"<<endl;
        return 0;
    }
    int cnt=0,minn=0;
    for(int i=1;i<=n;i++){
        minn=min(minn,a[i]);
    }
    int now=0;
    for(int i=1;i<=n;i++){
        if(a[i]==minn)cnt++,now=i;
    }
    int ans=cnt;
    int l=1,r=1;

    //cout<<now<<cnt<<endl;
    int nowl=now,tmp=0;
    for(int i=now;i<=now+n-1;i++){
        if(a[i]<minn+2){
            if(cnt+tmp>ans){
                ans=tmp+cnt;
                l=(nowl+1+n-1)%n+1,r=(i+n-1)%n+1;
            }
            nowl=i,tmp=0;
        }
        else if(a[i]==minn+2)tmp++;
    }

    tmp=0,nowl=now;
    for(int i=now;i<=now+n;i++){
        if(i==now+n||a[i]==minn){
            if(tmp>ans){
                ans=tmp;
                l=(nowl+1+n-1)%n+1,r=(i+n-1)%n+1;
            }
            nowl=i,tmp=0;
        }
        else if(a[i]==minn+1)tmp++;
    }
    
    cout<<ans<<endl;
    cout<<l<<" "<<r<<endl;

}