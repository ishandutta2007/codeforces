#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
using namespace std;
#define ll long long

char S[1000];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        char ans[1000]={};
        // r p s
        int r,p,s;cin>>r>>p>>s;
        cin>>S;
        for(int i=0;i<n;i++){
            if(S[i]=='S'&&r>0)ans[i]='R',r--;
            if(S[i]=='R'&&p>0)ans[i]='P',p--;
            if(S[i]=='P'&&s>0)ans[i]='S',s--;
        }
        if(n-r-s-p>=(n+1)/2){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                if(ans[i]) cout<<ans[i];
                else if(r>0)cout<<"R",r--;
                else if(p>0)cout<<"P",p--;
                else cout<<"S",s--;
            }
            cout<<endl;
        }
        else cout<<"No"<<endl;
    }
}