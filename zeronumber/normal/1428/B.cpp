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
        cin >> n >> s;
        bool f=1,g=1;
        for (int i=0;i<n;i++) f&=s[i]!='<',g&=s[i]!='>';
        if (f|g){
            cout << n << endl;
        } else {
            s[n]=s[0];
            int ans=0;
            for (int i=0;i<n;i++) ans+=s[i]=='-'||s[i+1]=='-';
            cout << ans << endl;
        }
    }
    return 0;
}