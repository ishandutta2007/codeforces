#include<iostream>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string a,b,c;cin>>a>>b>>c;
        int n=a.size();
        int flg=0;
        for(int i=0;i<n;i++){
            if(a[i]==c[i]||b[i]==c[i]){
                continue;
            }
            flg=1;
        }
        cout<<(flg?"NO":"YES")<<endl;
    }
}