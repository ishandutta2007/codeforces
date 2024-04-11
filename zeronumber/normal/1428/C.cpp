#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e6+11;
const int M=1000000007;
int _,n;
char s[maxn];
int main(){
    cin >> _;
    while (_--){
        cin >> s; n=strlen(s);
        int sum=0,ans=0;
        for (int i=n-1;i>=0;i--){
            if (s[i]=='A') ++sum; else --sum;
            ans=max(ans,sum);
        }
        if ((n-ans)&1) ++ans;
        cout << ans << endl;
    }
    return 0;
}