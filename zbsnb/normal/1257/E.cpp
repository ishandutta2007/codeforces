#include<iostream>
#include<map>
using namespace std;
#define ll long long
int pre1[200010];
int pre2[200010];
int pre3[200010];
int main(){
    int n1,n2,n3;cin>>n1>>n2>>n3;
    for(int i=1;i<=n1;i++){
        int tmp;cin>>tmp;
        pre1[tmp]=1;
    }
    for(int i=1;i<=n2;i++){
        int tmp;cin>>tmp;
        pre2[tmp]=1;
    }
    for(int i=1;i<=n3;i++){
        int tmp;cin>>tmp;
        pre3[tmp]=1;
    }
    int maxn=n1+n2+n3;
    for(int i=1;i<=maxn;i++){
        pre1[i]+=pre1[i-1];
        pre2[i]+=pre2[i-1];
        pre3[i]+=pre3[i-1];
    }

    for(int i=0;i<=maxn;i++){
        pre3[i]=pre2[i]+(n3-pre3[i]);
        //cout<<i<<" "<<pre1[i]<<" "<<pre2[i]<<" "<<pre3[i]<<endl;
    }

    for(int i=maxn-1;i>=0;i--){
        pre3[i]=max(pre3[i+1],pre3[i]);
    }
    int ans=0;
    for(int i=0;i<=maxn;i++){
        //cout<<i<<" "<<pre1[i]<<" "<<pre2[i]<<" "<<pre3[i]<<endl;
        ans=max(pre1[i]-pre2[i]+pre3[i],ans);
    }
    cout<<n1+n2+n3-ans<<endl;
}