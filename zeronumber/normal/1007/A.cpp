#include<bits/stdc++.h>
#define maxn 123456
#define F first
#define S second

using namespace std;
typedef long long ll;
map<int,int> f;
int n,a[maxn],r;

int main(){
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) f[a[i]]++;
    for (int i=0;i<n;i++) r=max(r,f[a[i]]);
    cout << n-r << endl;
}