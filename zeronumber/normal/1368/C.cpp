#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=1e6+12;
const int M=1000000007;
int _,ans;
ll a,b,n;
int main(){
    cin >> n;
    cout << n*3+4 << endl;
    puts("0 0");
    for (int i=0;i<=n;i++){
        printf("%d %d\n",i,i+1);
        printf("%d %d\n",i+1,i);
        printf("%d %d\n",i+1,i+1);
    }
    return 0;
}