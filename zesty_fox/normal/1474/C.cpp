#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

const int N=2010;
int T,n,st[N][2],sum,maxn;
multiset<int> s,s1;
int main(){
    T=rdi();
    while(T--){
        n=rdi();n*=2;s.clear();
        for(int i=1;i<=n;i++) s.insert(rdi());
        s1=s;auto kk=s1.end();kk--;
        int maxx=*kk;kk--;
        bool success=0;
        for(int id=1;id<=n-1;id++,kk--){
            bool flg=1;
            maxn=sum=maxx+(*kk);s=s1;
            for(int i=1;i<=n/2;i++){
                auto it=(--s.end());int val=*it;
                s.erase(s.find(val));
                auto tmp=s.find(sum-val);
                if(tmp==s.end()) {flg=0;break;}
                else{
                    st[i][0]=val,st[i][1]=sum-val;
                    s.erase(s.find(sum-val));
                    sum=max(val,sum-val);
                }
            }
            if(flg){
                puts("YES");printf("%d\n",maxn);
                for(int i=1;i<=n/2;i++) printf("%d %d\n",st[i][0],st[i][1]);
                success=1;break;
            }
        }
        if(!success) puts("NO");
    }
    return 0;
}