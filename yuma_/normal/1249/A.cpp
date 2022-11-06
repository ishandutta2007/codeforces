#include<bits/stdc++.h>
using namespace std;

int main(){
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int>v(N);
        for(int i=0;i<N;++i){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        bool ok=false;
        for(int i=0;i<N-1;++i){
            if(v[i]==v[i+1]-1)ok=true;
        }
        if(ok)cout<<2<<endl;
        else cout<<1<<endl;
    }
}