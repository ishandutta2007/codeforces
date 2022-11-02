#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e5+3;
const int M=1000000007;
int _,n,a[maxn];
int main(){
    cin >> _;
    while (_--){
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++){
            if (i%2==1) a[i]=abs(a[i]);
            else a[i]=-abs(a[i]);
        }
        for (int i=1;i<=n;i++) cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}