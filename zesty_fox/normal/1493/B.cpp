#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
           if(ch=='-') f=-1;
           ch=getchar();
        }
    while(ch>='0'&&ch<='9'){
           x=(x<<1)+(x<<3)+(ch^48);
           ch=getchar();
        }
    return x*f;
}
 
#define rdi read<int>
#define rdl read<ll>
 
int T,n,m,x,y;
const int fx[]={0,1,5,-1,-1,2,-1,-1,8,-1};
pii rev(int x,int y){
    int a=x/10,b=x%10,c=y/10,d=y%10;
    if(fx[a]==-1||fx[b]==-1||fx[c]==-1||fx[d]==-1) return make_pair(-1,-1);
    return make_pair(fx[d]*10+fx[c],fx[a]+fx[b]*10);
}
 
int main(){
    T=rdi();
    while(T--){
        n=rdi(),m=rdi();
        scanf("%d:%d",&x,&y);
        for(;;y++,(x+=y/m)%=n,y%=m){
            if(rev(x,y).first==-1) continue;
            if(rev(x,y).first<n&&rev(x,y).second<m){
                printf("%02d:%02d\n",x,y);
                break;
            }
        }
    }
    return 0;
}