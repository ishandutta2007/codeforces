#include<bits/stdc++.h>
using namespace std;
int cnt[1002];
int ans[1002];
int main(){
    int n,a,b;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }
    if(cnt[n]!=(n-1)){
        cout<<"NO"<<endl;
        return 0;
    }
    ans[n]=n;
    int j=1,k=1;
    for(int i=1;i<=n-1;k++){
        while(!cnt[k])   k++;
        ans[i++]=k;
        for(int z=1;z<cnt[k];z++){
            while(cnt[j])   j++;
            if(j>=k){
                cout<<"NO"<<endl;
                return 0;
            }
            ans[i++]=j++;
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n-1;i++){
        cout<<ans[i]<<' '<<ans[i+1]<<endl;
    }
}