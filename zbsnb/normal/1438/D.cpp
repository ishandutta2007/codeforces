#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        int tmp;cin>>tmp;
        sum^=tmp;
    }
    if(n%2==0&&sum) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        if(n%2==0) n--;
        cout<<n-1<<endl;
        for(int i=3;i<=n;i+=2){
            cout<<i-2<<" "<<i-1<<" "<<i<<endl;
        }
        for(int i=3;i<=n;i+=2){
            cout<<i-2<<" "<<i-1<<" "<<n<<endl;
        }
    }
}