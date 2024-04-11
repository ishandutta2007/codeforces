#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000][1000];
int main(){
    cin>>n;
    int cnt=0;
    for(int i=0; i<n; i+=4) for(int j=0; j<n; j+=4){
        for(int x=0; x<4; x++) for(int y=0; y<4; y++) a[i+x][j+y]=cnt++;
    }
//    set <int> s;
//    for(int i=0; i<n; i++){
//        int x=0;
//        for(int j=0; j<n; j++){
//            x^=a[i][j];
//        }
//        s.insert(x);
//    }
//    for(int i=0; i<n; i++){
//        int x=0;
//        for(int j=0; j<n; j++){
//            x^=a[j][i];
//        }
//        s.insert(x);
//    }
//    for(int x: s) cerr<<x<<'\n';
//    cerr<<s.size()<<'\n';
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cout<<a[i][j]<<" \n"[j+1==n];
}