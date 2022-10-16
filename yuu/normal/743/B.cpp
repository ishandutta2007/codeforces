#include <iostream>
using namespace std;
long long n, k, temp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    while(n>0){
        temp=(1LL<<n)-1LL;
        if(k<<1LL==temp+1LL){
            cout<<n;
            return 0;
        }
        else if(k>temp>>1LL){
            k-=(temp>>1LL)+1LL;
        }
        n--;
    }
}