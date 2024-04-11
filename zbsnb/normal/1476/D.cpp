#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[1000010];
int l[1000010];
int r[1000010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cin>>(s+1);
        for(int i=1;i<=n;i++){
            if(i==1) l[i]=1;
            else if(s[i]==s[i-1]) l[i]=1;
            else l[i]=l[i-1]+1;
        }
        for(int i=n;i>=1;i--){
            if(i==n) r[i]=1;
            else if(s[i]==s[i+1]) r[i]=1;
            else r[i]=r[i+1]+1;
        }
        
        // for(int i=1;i<=n;i++) cout<<l[i]<<" "<<r[i]<<endl;

        for(int i=1;i<=n+1;i++){
            cout<<
                (i!=1&&s[i-1]=='L'?l[i-1]:0)+
                (i!=n+1&&s[i]=='R'?r[i]:0)+
                1<<" \n"[i==n+1];
        }
    }
}