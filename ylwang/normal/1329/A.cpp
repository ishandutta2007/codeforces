# include <bits/stdc++.h>
# define rr register
# define int long long
const int N=100010,INF=0x3f3f3f3f;
int l[N];
int n,m;
int ans[N];
inline int read(void){
    int res,f=1;
    char c;
    while((c=getchar())<'0'||c>'9')
        if(c=='-')f=-1;
    res=c-48;
    while((c=getchar())>='0'&&c<='9')
        res=res*10+c-48;
    return res*f;
}
signed main(void){
    n=read(),m=read();
    int sum=0;
    for(rr int i=1;i<=m;++i){
        l[i]=read();
        sum+=l[i];
        if(i+l[i]-1>n){
            printf("-1");
            return 0;
        } 
    }
    if(sum<n){ 
        printf("-1");
        return 0;
    }
    int ret=sum-n,last=1; // last   1  last = 1
    ans[1]=1;
    for(rr int i=2;i<=m;++i){
        if(ret>=(l[i-1]-1)){ //   (l[i-1]+1)   i-1  1 
            ret-=(l[i-1]-1);//  ret
            ans[i]=last+1;
            ++last;//  last
        }else{
            last=last+l[i-1]-ret; //  ret  (l[i-1]+1)  ret   ret 
            ret=0;
            ans[i]=last;
        }
    }
    for(rr int i=1;i<=m;++i){
        printf("%I64d ",ans[i]);
    }
    return 0;
}