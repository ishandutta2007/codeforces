#include <iostream>
using namespace std;
int main(){__int64 n,a,b,c,d;cin>>n>>a>>b>>c>>d;cout<<max(n-max(a,d)-max(b,c)+min(a,d)+min(b,c),0LL)*1LL*n;}