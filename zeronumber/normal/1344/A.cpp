#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e6+34;
int a[maxn],n;
int getmod(int x,int y){
    if (x>=0) return x%y;
    return (y-(-x)%y)%y;
}
void solve(){
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) a[i]=getmod(a[i]+i,n);
    sort(a,a+n);
    for (int i=0;i<n-1;i++) if (a[i]==a[i+1]) {puts("NO");return;}
    puts("YES");
}
int main(){
    int _; cin >> _;
    while (_--) solve();
}