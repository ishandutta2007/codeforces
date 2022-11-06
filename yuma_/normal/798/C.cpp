#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int l,long long int r){
    if(l>r)return gcd(r,l);
    else{
        if(r%l){
            return gcd(l,r%l);
        }else{
            return l;
        }
    }
}

int main(){
    int N;cin>>N;
    vector<long long int>as(N);
    for(int i=0;i<N;++i){
        cin>>as[i];
    }
    long long int aa=as[0];
    for(int i=0;i<N-1;++i){
        aa=gcd(aa,as[i+1]);
    }
    if(aa!=1){
        cout<<"YES"<<endl;
        cout<<0<<endl;
    }
    else{
        vector<int>odds(N);
        for(int i=0;i<N;++i){
            odds[i]=as[i]%2;
        }
        int ans=0;
        int onenum=0;
        for(int i=0;i<N;++i){
            if(odds[i])onenum++;
            else{
                if(onenum%2){
                    ans+=onenum/2+2;
                }else{
                    ans+=onenum/2;
                }
                onenum=0;
            }
        }
        if(onenum%2){
            ans+=onenum/2+2;
        }else{
            ans+=onenum/2;
        }
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
    return 0;
}