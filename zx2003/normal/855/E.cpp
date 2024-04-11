#include<cstdio>
#include<cstring>
#include<cctype>
typedef long long ll;
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
const int N=5000;
int q,b,cnt[5000],w,a[70];
ll l,r,f[12][70][(1<<11)+5];
ll dfs(int x,int s,bool zero,bool limit){
	if(cnt[s]>x)return 0;
	if(!x)return 1;
	if(~f[b][x][s] && !zero && !limit)return f[b][x][s];
	ll ans=0;int i=1,up=limit?a[x]:b;
	if(limit && x>1)ans=dfs(x-1,s^(1<<a[x]),0,1);
	for(i=zero;i<up;++i)ans+=dfs(x-1,s^(1<<i),0,0);
	if(!zero && !limit)f[b][x][s]=ans;
	return ans;
}
inline ll calc(ll x){
	register ll t=x,ans;register int i;
	for(w=0;t;t/=b)a[++w]=t%b;ans=dfs(w,0,1,1);
	for(i=w-1;i;--i)
		ans+=dfs(i,0,1,0);
	return ans;
}
int main(){
	//freopen("1.txt","r",stdin);
	memset(f,-1,sizeof f);
	register int i=1;
	for(;i<N;++i)cnt[i]=cnt[i>>1]+(i&1);
	read(q);
	while(q--){
		read(b),read(l),read(r);
		print(calc(r+1)-calc(l)),print('\n');
	}
	flush();
	return 0;
}