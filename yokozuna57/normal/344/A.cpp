#include<iostream>
using namespace std;

int main(){
    int n,a,b=0,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(a!=b)ans++;
        b=a;
    }
    printf("%d\n",ans);
}