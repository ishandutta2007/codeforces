#include <bits/stdc++.h>
using namespace std;
string a, b;
int main(){
    cin>>a;
    for(int i=0; i<5; i++){
        cin>>b;
        if(b[0]==a[0]||b[1]==a[1]){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
}