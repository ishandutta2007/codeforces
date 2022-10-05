#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,y[1010],k1,k2,las,cnt;

void doit(int a,int b){
    k1=y[b]-y[a];
    k2=b-a;
    cnt=0;
    for (int i=1;i<=n;i++){
        if ((ll)(y[i]-y[a])*k2==(ll)(i-a)*k1){
            continue;
        }else{
            if (cnt){
                if ((ll)(y[i]-y[las])*k2!=(ll)(i-las)*k1){
                    return;
                }
            }
            cnt++;las=i;
        }
    }
    if (!cnt) return;
    printf("Yes\n");
    exit(0);
}

int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>y[i];
    }
    doit(1,2);
    doit(2,3);
    doit(1,3);
    printf("No\n");
}