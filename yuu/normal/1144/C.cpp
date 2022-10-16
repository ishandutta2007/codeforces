#include <bits/stdc++.h>
using namespace std;
int n;
int a[200000];
vector <int> x, y;
int main(){
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    for(int i=0; i<n; i++){
        if((x.empty())||(x.back()!=a[i])) x.push_back(a[i]);
        else if((y.empty())|(y.back()!=a[i])) y.push_back(a[i]);
        else{
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    reverse(y.begin(), y.end());
    cout<<x.size()<<'\n';
    for(int a: x) cout<<a<<' ';
    cout<<'\n';
    cout<<y.size()<<'\n';
    for(int a: y) cout<<a<<' ';
    cout<<'\n';
}