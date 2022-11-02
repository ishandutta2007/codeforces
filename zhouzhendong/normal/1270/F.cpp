#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
//const int mod=;
//int Pow(int x,int y){
//	int ans=1;
//	for (;y;y>>=1,x=(LL)x*x%mod)
//		if (y&1)
//			ans=(LL)ans*x%mod;
//	return ans;
//}
//void Add(int &x,int y){
//	if ((x+=y)>=mod)
//		x-=mod;
//}
//void Del(int &x,int y){
//	if ((x-=y)<0)
//		x+=mod;
//}
//int Add(int x){
//	return x>=mod?x-mod:x;
//}
//int Del(int x){
//	return x<0?x+mod:x;
//}
//void ckmax(int &x,int y){
//	if (x<y)
//		x=y;
//}
//void ckmin(int &x,int y){
//	if (x>y)
//		x=y;
//}
const int N=200005;
int n,sq;
char s[N];
int a[N];
struct hash_map{
    static const int Ti=233,mod=1<<20;
    int cnt,k[mod+1],v[mod+1],nxt[mod+1],fst[mod+1];
    int Hash(int x){
        int v=x&(mod-1);
        return v==0?mod:v;
    }
    void clear(){
        cnt=0;
        memset(fst,0,sizeof fst);
    }
    void update(int x,int a){
        int y=Hash(x);
        for (int p=fst[y];p;p=nxt[p])
            if (k[p]==x){
                v[p]=a;
                return;
            }
        k[++cnt]=x,nxt[cnt]=fst[y],fst[y]=cnt,v[cnt]=a;
        return;
    }
    int find(int x){
        int y=Hash(x);
        for (int p=fst[y];p;p=nxt[p])
            if (k[p]==x)
                return v[p];
        return 0;
    }
    int &operator [] (int x){
        int y=Hash(x);
        for (int p=fst[y];p;p=nxt[p])
            if (k[p]==x)
                return v[p];
        k[++cnt]=x,nxt[cnt]=fst[y],fst[y]=cnt;
        return v[cnt]=0;
    }
}mp;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,1,n)
		a[i]=s[i]-'0';
	sq=sqrt(n);
	LL ans=0;
	For(d,1,sq){
		mp.clear();
		LL sum=0;
		For(i,1,n){
			mp[sum]++;
			sum+=a[i]?d-1:-1;
			ans+=mp[sum];
		}
	}
	vi p;
	p.pb(0);
	For(i,1,n){
		if (a[i])
			p.pb(i);
		Fod(j,(int)p.size()-1,1){
			if (((int)p.size()-j)*sq>n)
				break;
			int p0=p[j],p1=p[j-1];
			int v0=i-p0+1,v1=i-p1;
			int c=p.size()-j;
			int L=(v0+c-1)/c;
			int R=v1/c;
			L=max(L,sq+1);
			if (L<=R)
				ans+=R-L+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}