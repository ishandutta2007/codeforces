#include<iostream>
#include<algorithm>
using namespace std;

int main(){
int ans[2];
int n,k;
long int a[51];
cin>>n>>k;
for(int i=0;i<n;i++)cin>>a[i];
for(int i=n;i<51;i++)a[i]=0;
sort(a,a+51);
if(a[51-k]!=a[50-k])printf("%d %d\n",a[51-k],a[51-k]-1);
else cout<<-1<<endl;
}