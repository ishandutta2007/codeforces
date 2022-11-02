#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=6e5+5;
int _,a[maxn],n;
ll k;

int main(){
    cin >> _;
    while (_--){
        cin >> n >> k;
        for (int i=1;i<=n;i++) cin >> a[i];
        if (k%2){
            int mx=a[1];
            for (int i=2;i<=n;i++) mx=max(mx,a[i]);
            for (int i=1;i<=n;i++) printf("%d ",mx-a[i]);puts("");
        } else {
            int mn=a[1];
            for (int i=2;i<=n;i++) mn=min(mn,a[i]);
            for (int i=1;i<=n;i++) printf("%d ",a[i]-mn);puts("");
        }
    }
    return 0;
}