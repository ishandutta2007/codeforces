#include <bits/stdc++.h>
using namespace std;
int main() {
int t; cin >>t;
while (t--){
long long n;
cin>>n;
if(n%2050){puts("-1");continue;}
int cnt=0;
while(n){
long long cur=2050;
for(;cur<=1e18&&cur*10<=n;cur*=10);
cnt+=n/cur;n%=cur;
}
printf("%d\n",cnt);
}
return 0;
}