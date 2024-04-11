#include<iostream>
using namespace std;
int a[10000];
int main(){
    int n;cin>>n;
    char s[2000];cin>>s+1;
    for(int i=1;i<=n;i++){
        if(s[i]=='(')a[i]=a[i-1]+1;
        else a[i]=a[i-1]-1;
    }
    if(a[n]!=0){
        cout<<0<<endl;
        cout<<"1 1"<<endl;
        return 0;
    }
    int ans=0,l,r;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=1;k<=n;k++){
                a[k]=a[k-1]+(s[k==i||k==j?i+j-k:k]=='('?1:-1);
                //if(i==1&&j==2)cout<<k<<" "<<a[i]<<endl,cout<<s[k==i||k==j?i+j-k:k]<<endl;
            }
            int minn=0;
            int tmp=0;
            for(int i=1;i<=n;i++)minn=min(minn,a[i]);
            for(int i=1;i<=n;i++)if(a[i]==minn)tmp++;
            if(tmp>ans){
                ans=tmp;
                l=i,r=j;
            }
        }
    }
    cout<<ans<<endl;
    cout<<l<<" "<<r<<endl;
}