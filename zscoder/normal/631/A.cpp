#include <bits/stdc++.h>
using namespace std;
int main()
{
int n; cin>>n;
int a;
int ans1, ans2;
ans1=0;
ans2=0;
for(int i = 0; i < n; i++){
cin>>a; ans1|=a;
}
for(int i = 0; i < n; i++){
cin>>a; ans2|=a;
}
cout<<ans1+ans2;
return 0;}