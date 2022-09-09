#include<cstdio>
#include<cctype>
#include<set>
using namespace std;
const int N=100010,M=12000000;
typedef long long ll;
struct memorypool{
	int a[M],xb;
	inline void Init(){
		for(register int i=0;i<M;++i)a[i]=i;
		xb=M-1;
	}
	inline int New(){
		return a[xb--];
	}
	inline void Del(int x){
		a[++xb]=x;
	}
}X;
struct node{
	int l,r;
	ll s;
}a[M];
int xb;
void add(int&i,int rl,int rr,int l,int v){
	if(!i)i=X.New();
	a[i].s+=v;
	if(rl==rr)return;
	int m=(rl+rr)>>1;
	if(l>m)add(a[i].r,m+1,rr,l,v);
		else add(a[i].l,rl,m,l,v);
	if(!a[i].s)X.Del(i),i=0;
}
ll query(int i,int rl,int rr,int l,int r){
	if(!i)return 0;
	if(rl==l && rr==r)return a[i].s;
	int m=(rl+rr)>>1;
	if(l>m)return query(a[i].r,m+1,rr,l,r);
		else if(r<=m)return query(a[i].l,rl,m,l,r);
				else return query(a[i].l,rl,m,l,m)+query(a[i].r,m+1,rr,m+1,r);
}
int n,i,aa[N],lst[N],nxt[N],m,o,u,v;
struct BIT{
	int rt[N];
	inline void addd(int x,int y){//lst[x] x
		for(int i=x+1;i<=n+2;i+=i&-i)add(rt[i],1,n,y,y);
	}
	inline void del(int x,int y){
		for(int i=x+1;i<=n+2;i+=i&-i)add(rt[i],1,n,y,-y); 
	}
	inline ll que(int x,int y,int z){//<=x y->z
		ll ans=0;
		for(int i=x+1;i;i-=i&-i)ans+=query(rt[i],1,n,y,z);	
		return ans;
	}
}tl,tn;
set<int> s[N];
set<int>::iterator it1,it2;
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
    /*  */
    for (x = 0; isdigit(c); c = read())
        x = (x + (x << 2) << 1) + (c ^ '0');
    if (iosig) x = -x;
}
const int OUT_LEN = 2000000;
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
int main(){
	//freopen("c.txt","r",stdin);
	//freopen("cc.txt","w",stdout);
	X.Init();
	read(n);
	read(m);
	for(i=1;i<=n;++i)s[i].insert(0),s[i].insert(n+1);
	for(i=1;i<=n;++i){
		read(aa[i]);
		lst[i]=*--s[aa[i]].lower_bound(i);
		s[aa[i]].insert(i);
	}
	for(i=1;i<=n;++i)nxt[i]=*s[aa[i]].upper_bound(i);
	for(i=1;i<=n;++i){
		tl.addd(lst[i],i);
		tn.addd(nxt[i],i);
	}
	while(m--){
		read(o),read(u),read(v);
		if(o&2)print(tn.que(n+1,u,v)-tn.que(v,u,v)-tl.que(u-1,u,v)),print('\n');
			else{
				it1=s[aa[u]].upper_bound(u);
				it2=--s[aa[u]].lower_bound(u);
				if(*it1<=n)tl.del(lst[*it1],*it1),lst[*it1]=*it2,tl.addd(lst[*it1],*it1);
				if(*it2>=1)tn.del(nxt[*it2],*it2),nxt[*it2]=*it1,tn.addd(nxt[*it2],*it2);
				s[aa[u]].erase(u);
				it1=s[v].upper_bound(u);
				it2=--s[v].lower_bound(u);
				if(*it1<=n)tl.del(lst[*it1],*it1),lst[*it1]=u,tl.addd(lst[*it1],*it1);
				if(*it2>=1)tn.del(nxt[*it2],*it2),nxt[*it2]=u,tn.addd(nxt[*it2],*it2);			
				s[v].insert(u);
				tl.del(lst[u],u);
				tn.del(nxt[u],u);
				lst[u]=*it2;
				nxt[u]=*it1;
				tl.addd(lst[u],u);
				tn.addd(nxt[u],u);	
				aa[u]=v;
			}
	}
	flush();
	return 0;
}