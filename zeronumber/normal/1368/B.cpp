#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=1e6+12;
const int M=1000000007;
int _,ans,a[10];
ll k,s;
string v="codeforces";
void check(int x){
    memset(a,0,sizeof(a));
    for (int i=0;i<x;i++) a[i%10]++;
    s=1; for (int i=0;i<10;i++) s*=a[i];
}
int main(){
    cin >> k;
    for (int i=1;i<=100000;i++) {
        check(i);
        if (s>=k){
            for (int j=0;j<10;j++)
                for (int t=0;t<a[j];t++) printf("%c",v[j]);
            puts("");
            return 0;
        }
    }
    return 0;
}