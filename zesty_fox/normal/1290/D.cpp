#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=2010;

int n,k,siz,cnt;
bool fl[N];

bool query(int x){
    cout<<"? "<<x<<endl;
    static char buf[2];cin>>buf;
    return buf[0]=='Y';
}
void clear() {cout<<"R"<<endl;}

void unique(int x){
    clear();
    for(int i=x*siz;i<(x+1)*siz;i++) fl[i]=query(i+1);
}

void init(int x){
    clear();
    for(int i=x*siz;i<(x+1)*siz;i++)
        if(!fl[i]) query(i+1);
}
void append(int y){
    for(int j=y*siz;j<(y+1)*siz;j++)
        if(!fl[j]) fl[j]|=query(j+1);
}

int main(){
    cin>>n>>k;
    siz=k,cnt=n/k;
    for(int i=0;i<cnt;i++) unique(i);
    if(cnt>1){
        for(int i=0;i<cnt;i++){
            int nw=i;init(nw);
            for(int j=1;j<cnt/2;j++){
                int nx1=(i+j)%cnt,nx2=(i+cnt-j)%cnt;
                append(nx1),append(nx2),nw=nx2;
            }
            append((i+cnt/2)%cnt);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) ans+=(!fl[i]);
    cout<<"! "<<ans<<endl;
    return 0;
}