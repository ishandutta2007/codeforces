#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,int> pi;
const int maxn=1e6+11;
const int M=1000000007;
int n,m,a[maxn],b[maxn],d[maxn],sa[maxn],sb[maxn],p[20][maxn];
char s[maxn];
ll ans;
int qry(int l,int r){
    if (l>r) return -1;
    int x=d[r-l+1];
    return max(p[x][l],p[x][r-(1<<x)+1]);
}
int qryL(int x,int v){
    if (qry(1,x-1)<=v) return 0;
    else {
        int l=1,r=x;
        while (r-l>1){
            int mid=(l+r)>>1;
            if (qry(mid,x-1)<=v) r=mid; else l=mid;
        }
        assert(a[l]>v);
        return sb[l-1]+sa[l]-v;
    }
}
int qryR(int x,int v){
    if (qry(x+1,m)<v) return n;
    else {
        int l=x,r=m;
        while (r-l>1){
            int mid=(l+r)>>1;
            if (qry(x+1,mid)<v) l=mid; else r=mid;
        }
        assert(a[r]>=v);
        return sa[l]+sb[l]+(v-1);
    }
}
int main(){
    cin >> n >> s;
    for (int i=0;i<n;i++){
        if (s[i]=='0') b[m]++;
        else if (s[i]=='1'){
            if (i==0||s[i-1]=='0') ++m;
            a[m]++;
        }
    }
    sb[0]=b[0];
    for (int i=2;i<maxn;i++) d[i]=d[i/2]+1;
    for (int i=1;i<=m;i++) sa[i]=sa[i-1]+a[i],sb[i]=sb[i-1]+b[i],p[0][i]=a[i];
    for (int i=1;i<=m;i++) ans+=(ll)a[i]*(a[i]-1)*(a[i]-2)/6;
    for (int i=1;i<19;i++)
        for (int j=1;j+(1<<i)-1<=n;j++)
            p[i][j]=max(p[i-1][j],p[i-1][j+(1<<(i-1))]);
    for (int i=1;i<=m;i++){
        int L,R,LL,RR;
        LL=sa[i-1]+sb[i-1];
        RR=sa[i]+sb[i-1];
        ans+=1ll*a[i]*(LL-qryL(i,a[i])+1)*(qryR(i,a[i])-RR+1);
        for (int j=1;j<a[i];j++) ans+=1ll*j*((LL-qryL(i,j)+1)+(qryR(i,j)-RR+1));
    }
    cout << ans << endl;
    return 0;
}