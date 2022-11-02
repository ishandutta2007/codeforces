#include<iostream>
using namespace std;
char s[10000];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n>>s;
        int l=-1,r=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(l==-1)l=i;
                r=i;
            }
        }
        if(l==-1)cout<<n<<endl;
        else cout<<2*(n-min(l,n-1-r))<<endl;
    }
}