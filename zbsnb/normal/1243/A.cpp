#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
#define ll long long 

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[1010];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        int cnt=0;
        for(int i=n;i>=1;i--){
            if(cnt+1>a[i])break;
            else cnt++;
        }
        cout<<cnt<<endl;
    }
}