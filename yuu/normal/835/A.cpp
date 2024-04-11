#include <bits/stdc++.h>
using namespace std;
int main(){
    int s, v1, v2, t1, t2;
    cin>>s>>v1>>v2>>t1>>t2;
    (v1*=s)+=t1*2;
    (v2*=s)+=t2*2;
    if(v1<v2) cout<<"First\n";
    else if(v1>v2) cout<<"Second\n";
    else cout<<"Friendship\n";
}