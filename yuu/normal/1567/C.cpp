#include <bits/stdc++.h>
using namespace std;
int d[10];
int rem[10];
int make[10][2];
long long ans=0;
void backtrack(int u, long long cnt=1){
    if(u==10){
        ans+=cnt;
    }
    else{
        int target=d[u]-rem[u];
        if(target!=-1){
            backtrack(u+1, cnt*make[target][0]);
            if(u<8){
                rem[u+2]=1;
                backtrack(u+1, cnt*make[target][1]);
                rem[u+2]=0;
            }
        }
        else{
            if(u<8){
                rem[u+2]=1;
                backtrack(u+1, cnt*make[9][0]);
                rem[u+2]=0;
            }
        }
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=0; i<10; i++){
        d[i]=n%10;
        n/=10;
    }
    ans=0;
    backtrack(0);
    cout<<ans-2<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    for(int i=0; i<10; i++) for(int j=0; j<10; j++) make[(i+j)%10][(i+j)/10]++;
    cin>>t;
    while(t--) solve();
}