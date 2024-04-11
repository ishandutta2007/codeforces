#include<bits/stdc++.h>
#define maxn 423456
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
char s[maxn];
ll n,p,q,r;

int main(){
    cin >> n >> p >> q;
    scanf("%s",s);
    for (int i=1;i<n;i++) if (s[i]=='0'&&s[i-1]=='1') r++;
    if (s[0]=='0'&&s[n-1]=='0'){
        cout << r*min(p,q)+q << endl;
    }
    if (s[0]=='1'&&s[n-1]=='1'){
        if (r==0) cout << 0 << endl;
        else cout << (r-1)*min(p,q)+q << endl;
    }
    if (s[0]=='1'&&s[n-1]=='0'){
        cout << (r-1)*min(p,q)+q << endl;
    }
    if (s[0]=='0'&&s[n-1]=='1'){
        cout << r*min(p,q)+q << endl;
    }
}