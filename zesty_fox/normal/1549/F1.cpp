#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=60010;
int n,x[N],y[N],typ[N];
ll cnt[16],ans;
int main(){
    n=rdi();
    for(int i=1;i<=n;i++) 
        x[i]=rdi(),y[i]=rdi(),typ[i]=x[i]%4+y[i]%4/2,cnt[typ[i]]++;
    //ans=n*(n-1)*(n-2);
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j||typ[i]==typ[j]) continue;
            for(int k=0;k<4;k++){
                if(k!=typ[i]||k!=typ[j]){
                    if(k==typ[i]) ans-=(cnt[k]-1);
                    else if(k==typ[j]) ans-=(cnt[k];
            }
        }
    }
    */
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                int tmp=(i==j)+(j==k)+(k==i);
                if(tmp==1){
                    if(i==j) ans+=cnt[i]*(cnt[j]-1)*cnt[k];
                    if(i==k) ans+=cnt[i]*(cnt[k]-1)*cnt[j];
                    if(j==k) ans+=cnt[i]*cnt[j]*(cnt[k]-1);
                }
                else if(tmp==3) ans+=cnt[i]*(cnt[j]-1)*(cnt[k]-2);
            }
        }
    }
    ans/=6;
    cout<<ans<<endl;
    return 0;
}