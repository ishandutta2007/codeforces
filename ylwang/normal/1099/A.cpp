#include<bits/stdc++.h>
using namespace std;

int w,h; 
int a,b,c,d;
int ans;
template<typename Tp>
void read(Tp &x){
    x=0;char ch=1;int fh;
    while(ch!='-'&&(ch>'9'||ch<'0')) ch=getchar();
    if(ch=='-'){
        ch=getchar();fh=-1;
    }
    else fh=1;
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    x*=fh;
}

int main(){
    read(ans);read(h);read(a);read(b);read(c);read(d);
    for(register int i=h;i>=0;i--){
        ans+=i;
        if(i==b) ans-=a;
        if(i==d) ans-=c;
        if(ans<0) ans=0;
    }
    printf("%d\n",ans);
    return 0;
}