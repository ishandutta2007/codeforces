#include<iostream>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int x[200010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,a,b,k;cin>>n>>a>>b>>k;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<=n;i++){
        x[i]=(x[i]-1)%(a+b)+1;
        x[i]=(x[i]-1)/a+1;
        x[i]--;
    }
    sort(x+1,x+n+1);
    // for(int i=1;i<=n;i++)cout<<x[i]<<" ";cout<<endl;
    int i=1;
    while(i<=n){
        k-=x[i];
        if(k<0){
            break;
        }
        i++;
    }
    cout<<i-1<<endl;
}