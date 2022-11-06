#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,K;cin>>N>>M>>K;
    M--;
    vector<int>as(N);
    for(int i=0;i<N;++i){
        int a;cin>>a;
        if(a==0)a=10000;
        as[i]=a;
    }
    int ans=100;
    for(int t=0;t<100;++t){
        for(int x=0;x<2;++x){
            int nt(M);
            nt+=x?t:-t;
            if(nt>=0&&nt<N){
                if(as[nt]<=K)ans=min(ans,t);
            }
        }
    }
    cout<<ans*10<<endl;

	return 0;
}