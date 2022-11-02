#include<iostream>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int a,b,c,d,k;cin>>a>>b>>c>>d>>k;
        int flg=0;
        for(int i=0;i<=k;i++){
            int j=k-i;
            if(i*c>=a&&j*d>=b){
                cout<<i<<" "<<j<<endl;
                flg=1;
                break;
            }
        }
        if(!flg)cout<<-1<<endl;
    }
}