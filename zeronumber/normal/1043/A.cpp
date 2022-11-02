#include<bits/stdc++.h>
#define maxn 1020

using namespace std;
int a[maxn],n,s;
int check(int x){
    int res=0;
    for (int i=1;i<=n;i++) res+=x-a[i]-a[i];
    return res>0;
}
int main(){
    cin >> n; for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) s=max(s,a[i]);
    while (!check(s)) s++;
    cout << s << endl;
}