#include<iostream>
using namespace std;

int main(){
    int n,a[100000+2];
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int ans=0;
    bool c=false;
    bool d=false;
    for(int i=0;i<n;i++){
        if(a[i]==i)ans++;
        else if(a[a[i]]==i)c=true;
        if(a[i]!=i)d=true;
    }
    if(c)printf("%d\n",ans+2);
    else if(d)printf("%d\n",ans+1);
    else printf("%d\n",ans);
}