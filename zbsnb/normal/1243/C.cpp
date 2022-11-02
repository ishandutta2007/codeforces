#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
#define ll long long 
  
int main(){
    ll n;cin>>n;
    int flg=0;
    for(int i=2;1ll*i*i<=n;i++){
        if(n%i==0){
            while(n%i==0)n/=i;
            if(n==1){
                cout<<i<<endl;
            }
            else cout<<1<<endl;
            flg=1;
            break;
        }
    }
    if(!flg)cout<<n<<endl;
}