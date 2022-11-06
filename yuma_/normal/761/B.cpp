#include <bits/stdc++.h>
using namespace std;


int main(){
    int N,L;cin>>N>>L;
    vector<int>as,bs;
    for(int i=0;i<N;++i){
        int a;cin>>a;
        as.emplace_back(a);
    }
    for(int i=0;i<N;++i){
        int b;cin>>b;
        bs.emplace_back(b);
    }
    vector<int>adif(N),bdif(N);
    for(int i=0;i<N-1;++i){
        adif[i]=as[i+1]-as[i];
        bdif[i]=bs[i+1]-bs[i];
    }
    adif[N-1]=L+as[0]-as[N-1];
    bdif[N-1]=L+bs[0]-bs[N-1];
    bool ok=false;
    for(int i=0;i<N;++i){
        rotate(adif.begin(),adif.begin()+1,adif.end());
        if(adif==bdif)ok=true;
    }
    if(ok)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}