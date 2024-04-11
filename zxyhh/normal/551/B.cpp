#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<string>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<bitset>
#include<vector>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define PC Putchar
#define GC Getchar
#define ll long long
#define ldb long double
#define pii pair<int,int>
#define pdd pair<double,double>
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define maxn 100005
using namespace std;
namespace FAST_IO {
    #define IN_LEN 500000
    #define OUT_LEN 500000
    inline char Getchar() {
        static char buf[IN_LEN], *l=buf,*r=buf;
        if (l==r) r=(l=buf)+fread(buf,1,IN_LEN,stdin);
        return (l==r)?EOF:*l++;
    }
    char obuf[OUT_LEN], *ooh = obuf;
    inline void Putchar(char c) {
        if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout),ooh = obuf;
	    *ooh++ = c;
    }
    inline ll rd(){
	    ll x=0;int ch=GC(); bool f=1;
	    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=GC();
	    if (ch=='-'){f=0;ch=GC();}
	    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=GC();}
	    return f?x:-x;
    }
    inline int strrd(char *t){
        int ch=GC();char *l=t;int len=0;
        while((!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')))&&(ch!=EOF))ch=GC();
        while(((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')))
        *l++=ch,len++,ch=GC();
        return len;
    }
    void write(unsigned ll x){ if (x>=10) write(x/10),PC((char)(x%10+'0')); else PC((char)(x+'0')); }
    inline void wrt(unsigned ll x,int p){if (x<0) PC('-'),x=-x; write(x); if (p) PC((char)p);}
    inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
}
using namespace FAST_IO;
char a[maxn],b[maxn],c[maxn];
int la,lb,lc;
int a1[27],b1[27],c1[27];
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	la=strrd(a+1); lb=strrd(b+1),lc=strrd(c+1);
	rep(i,1,la) a1[a[i]-'a'+1]++;rep(i,1,lb) b1[b[i]-'a'+1]++;rep(i,1,lc) c1[c[i]-'a'+1]++;
	int Max=0,m1=0,m2=0;
	rep(i,0,la/lb){
		bool flag=0;int s=666666666;
		rep(j,1,26) if (b1[j]*i>a1[j]) { flag=1;break;}
		if (!flag){
			rep(j,1,26) if (c1[j]>0) s=min(s,(a1[j]-b1[j]*i)/c1[j]);
			if (s==666666666) break;
			if (s+i>Max) Max=i+s,m1=i,m2=s;
		}
	}
	rep(i,1,m1) rep(j,1,lb) PC(b[j]),a1[b[j]-'a'+1]--;
	rep(i,1,m2) rep(j,1,lc) PC(c[j]),a1[c[j]-'a'+1]--;
	rep(i,1,26) rep(j,1,a1[i]) PC((char)i+'a'-1);
	PC('\n');flush();
	return 0;
}