#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e6+5;
int _,a[maxn],n;

int main(){
    cin >> _;
    while (_--){
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        bool flag=0;
        for (int i=2;i<=n;i++) flag|=a[i]!=a[1];
        if (flag) puts("1"); else cout << n << endl;
    }
    return 0;
}