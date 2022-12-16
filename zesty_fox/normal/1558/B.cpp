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
     
    const int N=8000010;
    int n,MOD;
    ll sum[N],f[N];
     
    int main(){
        n=rdi(),MOD=rdi();
        f[n]=1;
        for(int i=n;i>=1;i--){
            (f[i]+=sum[i+1])%=MOD;
            for(int j=2;j<=n/i;j++){
                (f[i]+=sum[i*j]-sum[i*j+j])%=MOD;
            }
            sum[i]=(sum[i+1]+f[i])%MOD;
        }
        cout<<f[1]<<endl;
        return 0;
    }