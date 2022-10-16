#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int b[1000];
int c[1000];
vector <int> d;
vector <pair <int, int> > ans;
int main(){
    cin>>n;
    for(int i=1; i<n; i++){
        cin>>a[i]>>b[i];
        if(a[i]>b[i]) swap(a[i], b[i]);
        if((b[i]!=n)||(a[i]==b[i])){
            cout<<"NO\n";
            return 0;
        }
    }
    for(int i=1; i<n; i++) c[a[i]]++;
    for(int i=1; i<n; i++){
        if(c[i]==0) d.push_back(i);
        else if(d.size()+1<c[i]){
            cout<<"NO\n";
            return 0;
        }
        else{
            int attach=n;
            while(c[i]>1){
                ans.push_back({attach, d.back()});
                attach=d.back();
                d.pop_back();
                c[i]--;
            }
            ans.push_back({attach, i});
        }
    }
    cout<<"YES\n";
    for(pair <int, int> p: ans) cout<<p.first<<' '<<p.second<<'\n';
}