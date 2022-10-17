#include <bits/stdc++.h>
using namespace std;
int n;//nn
int a[100005];//a
int b[100005];//ber
int px=0,py=0;//~~
int main() {
cin>>n;//n
for(int i = 0;i<n;i++){//
    cin>>a[i];//
}
for(int i = 0;i<n;i++){//
    cin>>b[i];//
    if(a[i]==1&&b[i]==0){//
        px++;//++
    }
    if(a[i]==0&&b[i]==1){//
        py++;//++
    }
}
if(px==0){//
    cout<<-1;//
    return 0;
}
int o=1;//
while(o*px<=py){//
    o++;//
}
cout<<o;//
   return 0; 
}