#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,d;cin>>n>>d;
        multiset<int> s;
        for(int i=1;i<=n;i++){
            cin>>a[i];s.insert(a[i]);
        }
        int x=*s.begin();
        int y=*(++s.begin());
        if(x>d||y>d) cout<<"NO"<<endl;
        else{
            if(*(--s.end())<=d) cout<<"YES"<<endl;
            else if(x+y<=d) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}