#include <iostream>
using namespace std;
int main() {
int n, sum;
cin >> n >> sum;
int ans[n];
int l[n];
int r[n];
for (int i=0; i<n; i++) cin >> l[i] >> r[i];
for (int i=0; i<n; i++) {
ans[i]=l[i];
sum-=l[i];
}
if(sum>0)
for(int i=0; i<n; i++){
int a = min(sum, r[i] - l[i]);
ans[i] += a;
sum-=a;
}
if (sum==0){
cout<<"YES\n";
for(int i=0; i<n; i++) cout << ans[i] << " \n"[i+1==n];
} else cout << "NO";
}