#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,k;
int ask(int x){
    printf("? %d\n",x); fflush(stdout);
    scanf("%d",&x);
    return x;
}
int calc(int x){
    x=x%n;
    if(x<=0) x+=n;
  //  cout<<x<<endl;
    return x;
}
int check(int x){
    int tmp=ask(x);
    return (tmp==k);
}
int main(){
    scanf("%d%d",&n,&k);
    int nw=1,val=0;
    for(int i=1;i<=n;i++){
        val=ask(nw);
        if(val!=k) break;
        nw+=(i+1); nw=calc(nw);
    }
    if(val>k){//
        for(int i=1;i<=n;i++){
            int tmp=calc(nw-i);
            if(check(tmp)){
                printf("! %d\n",tmp);
                return 0;
            }
        }
    } else {//
        for(int i=1;i<=n;i++){
            int tmp=calc(nw+i);
            if(check(tmp)){
                printf("! %d\n",tmp);
                return 0;
            }
        }
    }
    return 0;
}