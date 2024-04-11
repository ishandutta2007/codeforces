#include<cstdio>
#include<cstring>
#include<cctype>
inline char read() {
    static const int IN_LEN = 1000000;
    static char buf[IN_LEN], *s, *t;
    if (s == t) {
        t = (s = buf) + fread(buf, 1, IN_LEN, stdin);
        if (s == t) return -1;
    }
    return *s++;
}
template<class T>
inline void read(T &x) {
    static bool iosig;
    static char c;
    for (iosig = false, c = read(); !isdigit(c); c = read()) {
        if (c == '-') iosig = true;
        if (c == -1) return;
    }
    for (x = 0; isdigit(c); c = read())
        x = (x + (x << 2) << 1) + (c ^ '0');
    if (iosig) x = -x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *oh = obuf;
inline void print(char c) {
    if (oh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), oh = obuf;
    *oh++ = c;
}
template<class T>
inline void print(T x) {
    static int buf[30], cnt;
    if (x == 0) {
        print('0');
    } else {
        if (x < 0) print('-'), x = -x;
        for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
        while (cnt) print((char)buf[cnt--]);
    }
}
inline void flush() {
    fwrite(obuf, 1, oh - obuf, stdout);
}
typedef unsigned int ui;
struct LB{
	static const int L=30;
	unsigned int p[L];
	inline void clear(){memset(p,0,sizeof p);}
	inline void ins(ui x){
		for(register int i=L-1;x && i>=0;--i)x>>i&1?(p[i]?x^=p[i]:(p[i]=x,x=0)):0;
	}
	inline void operator+=(const LB&rhs){
		register int i;
		for(i=0;i<L;++i)
			if(rhs.p[i])
				ins(rhs.p[i]);
	}
	inline int query(){
		register int i=0,s=0;for(i=0;i<L;++i)s+=p[i]>>i;return s;
	}
}b;
const int N=200005; 
int a[N],l,r,o,n,q,i,j,k,bb[N];
ui v;
struct BIT{
	ui b[N];
	inline void init(){for(register int i=1;i<=n;++i)b[i]=a[i^(i&-i)]^a[i];}
	inline void add(int x,unsigned int v){
		for(register int i=x;i<=n;i+=i&-i)
			b[i]^=v;
	}
	inline unsigned int query(int x){
		register unsigned int ans=0;
		for(register int i=x;i;i^=i&-i)ans^=b[i];return ans;
	}
}tt;
struct segtree{
	struct node{
		LB v;
		int l,r,m;
	}t[N<<2];
	LB ans;
	int pos[N];
	void build(int i,int l,int r){
		t[i].l=l,t[i].r=r,t[i].m=(l+r)>>1;
		if(l==r){t[i].v.ins(a[l]^a[l-1]);pos[l]=i;return;}
		build(i<<1,l,t[i].m),build(i<<1|1,t[i].m+1,r),t[i].v=t[i<<1].v;
		t[i].v+=t[i<<1|1].v;
	}
	void query(int i,int l,int r){
		if(l==t[i].l && r==t[i].r){ans+=t[i].v;return;}
		if(l>t[i].m)query(i<<1|1,l,r);
			else if(r<=t[i].m)query(i<<1,l,r);
					else query(i<<1,l,t[i].m),query(i<<1|1,t[i].m+1,r);
	}
	int query(int l,int r){
		ans.clear();
		if(l<r)query(1,l+1,r);
		ans.ins(tt.query(l));
		return ans.query();
	}
	inline void mdy(int l,ui v){
		register int i=pos[l];t[i].v.clear();t[i].v.ins(v^bb[l]);
		for(;i>1;)i>>=1,t[i].v=t[i<<1].v,t[i].v+=t[i<<1|1].v;
	}
}t;
int main(){
	//freopen("1.txt","r",stdin);//freopen("2.txt","w",stdout);
	read(n),read(q);
	for(i=1;i<=n;++i)read(a[i]),bb[i]=a[i]^a[i-1];tt.init();t.build(1,1,n);
	while(q--){
		read(o),read(l),read(r);
		if(o&2)print(1<<t.query(l,r)),print('\n');
			else{
				read(v);
				t.mdy(l,v);bb[l]^=v;
				if(r<=n)t.mdy(r+1,v);
				tt.add(l,v);
				if(r<=n)tt.add(1+r,v),bb[r+1]^=v;
			}
		//for(i=1;i<=n;++i)printf("%d ",tt.query(i));puts("");
	}
	flush();
	return 0;
}