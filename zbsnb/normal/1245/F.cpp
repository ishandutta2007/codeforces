#include<iostream>
#include<map>
using namespace std;
#define ll long long 

ll calcu(int a,int b){
    ll ret=0;
    int nowa=0;
    for(int i=30;i>=0;i--){
        if(!(a&(1<<i)))continue;

        int nowb=0;
        for(int j=30;j>=0;j--){
            if(!(b&(1<<j)))continue;
            if(nowa&nowb)continue;

            ll tmp=1;
            for(int k=30;k>=0;k--){
                if(k>(i-1)&&k>(j-1))continue;
                if(k<=(i-1)&&k>(j-1))tmp*=nowb&(1<<k)?1:2;
                if(k<=(j-1)&&k>(i-1))tmp*=nowa&(1<<k)?1:2;
                if(k<=(j-1)&&k<=(i-1))tmp*=3;
            }
            ret+=tmp;
            //cout<<i<<" "<<j<<" "<<tmp<<endl;

            nowb|=1<<j; 
        }
        nowa|=1<<i;
    }
    return ret;
}
int main(){
    int t;cin>>t;
    while(t--){
        int l,r;cin>>l>>r;l++,r++;
        cout<<calcu(r,r)+calcu(l-1,l-1)-2*calcu(l-1,r)<<endl;
    }
}