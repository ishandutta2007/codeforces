#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int p=1,res=1,md=1e9+7;
    for (int i=0;i<n;++i) {
        res=(2ll*m*res%md-(res-p+md)+md)%md;
        p=p*1LL*m%md;
    }
    cout<<res<<endl;
}