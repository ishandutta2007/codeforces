#include<iostream>
#include<algorithm>
using namespace std;
int  a[100010];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        int flg=0;
        for(int i=2;i<=n;i++){
            if(a[i]-a[i-1]==1)flg=1;
        }
        cout<<flg+1<<endl;
    }
}