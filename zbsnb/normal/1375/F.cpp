#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    pair<int,int> a[3];
    cin>>a[0].first>>a[1].first>>a[2].first;
    a[0].second=1;a[1].second=2;a[2].second=3;
    cout<<"First"<<endl;
    sort(a,a+3);
    int q=2*a[2].first-a[1].first-a[0].first;
    cout<<q<<endl;
    int tmp;cin>>tmp;
    if(tmp==a[0].second){
        cout<<(a[2].first-a[1].first)<<endl;
        cin>>tmp;
    }
    else if(tmp==a[1].second){
        cout<<(a[2].first-a[0].first)<<endl;
        cin>>tmp;
    }
    else{
        a[2].first=1ll*3*a[2].first-a[1].first-a[0].first;
        q=2*a[2].first-a[1].first-a[0].first;
        cout<<q<<endl;
        cin>>tmp;
        if(tmp==a[0].second){
            cout<<(a[2].first-a[1].first)<<endl;
            cin>>tmp;
        }
        else if(tmp==a[1].second){
            cout<<(a[2].first-a[0].first)<<endl;
            cin>>tmp;
        }
    }
}