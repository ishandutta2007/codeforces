#include <bits/stdc++.h>
using namespace std;

int gettype(char c){
    if(isdigit(c))return 0;
    else if('a'<=c&&c<='z')return 1;
    else return 2;
}
int main(){
    // int N,L;cin>>N>>L;
    // vector<int>as,bs;
    // for(int i=0;i<N;++i){
    //     int a;cin>>a;
    //     as.emplace_back(a);
    // }
    // for(int i=0;i<N;++i){
    //     int b;cin>>b;
    //     bs.emplace_back(b);
    // }
    // vector<int>adif(N),bdif(N);
    // for(int i=0;i<N-1;++i){
    //     adif[i]=as[i+1]-as[i];
    //     bdif[i]=bs[i+1]-bs[i];
    // }
    // adif[N-1]=L+as[0]-as[N-1];
    // bdif[N-1]=L+bs[0]-bs[N-1];
    // bool ok=false;
    // for(int i=0;i<N;++i){
    //     rotate(adif.begin(),adif.begin()+1,adif.end());
    //     if(adif==bdif)ok=true;
    // }
    // if(ok)cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;

    // return 0;
    int N,M;cin>>N>>M;
    vector<vector<int>>dp(N+1,vector<int>(8,100000));
    dp[0][0]=0;
    vector<string>sts;
    for(int i=0;i<N;++i){
        string st;cin>>st;
        sts.push_back(st);
    }
    for(int n=0;n<N;++n){
        for(int flag=0;flag<8;++flag){
            const int now=dp[n][flag];
            for(int use=0;use<M;++use){
                int cost=min(use,M-use);
                const int nextflag=flag|(1<<(gettype(sts[n][use])));
                dp[n+1][nextflag]=min(dp[n+1][nextflag],now+cost);
            }

        }
    }
    int ans=1e8;
    for(int i=0;i<8;++i){
        ans=min(ans,dp[N][7]);
    }
    cout<<ans<<endl;
    return 0;
}