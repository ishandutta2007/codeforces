#include<bits/stdc++.h>
using namespace std;

int n,l,r,m,an,ans[1000001][3],sz,x,siz,A,B,t[100001],tn,oN,o[21];
set<int> v[100001];
set<pair<int,int> > s;
set<int>::iterator nw,it;
set<pair<int,int> >::iterator itt;

namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	inline char gch(){
		char c=gc();for(;isspace(c);c=gc());
		return c;
	}
	inline void gs(char*c){
		char x=gc();for(;isspace(x);x=gc());
		for(;!isspace(x);x=gc())*c++=x;*c=0;
	}
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	// print a signed integer
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
using io :: gch;
using io :: gs;

void pri()
{
	print(an); putc('\n');
	for (int i=1; i<=an; i++) 
		print(ans[i][0]),putc(' '),print(ans[i][1]),putc(' '),print(ans[i][2]),putc('\n');
}

void ins(int x,int y,int z) {ans[++an][0]=x,ans[an][1]=y,ans[an][2]=z;}

int main()
{
	gi(n),gi(m); s.clear(); siz=0;
	for (int i=1; i<=n; i++)
	{
		gi(sz); v[i].clear(); siz+=sz; v[i].insert(-1);
		for (int j=0; j<sz; j++) gi(x),v[i].insert(x);
		s.insert(make_pair(sz+1,i));
	}
	l=siz/n; if (siz%n!=0) r=l+1; else r=l;
	l++; r++;
	while (1)
	{
		itt=s.end(); itt--;
		if ((*(s.begin())).first>=l||(*itt).first<=r) break;
		A=(*(s.begin())).second; B=(*itt).second;
		s.erase(make_pair(v[A].size(),A)); s.erase(make_pair(v[B].size(),B));
		nw=v[A].begin(); tn=0;
		while (v[A].size()+tn<l&&v[B].size()>r)
		{
			it=v[B].upper_bound(*nw);
			while (nw!=v[A].end()&&(*nw)<(*it)) nw++;
			if (nw==v[A].end()||(*it)!=(*nw))
			{
				ins(B,A,*it);
				t[++tn]=(*it);
				v[B].erase(it);
				nw--;
			}
		}
		for (int i=1; i<=tn; i++) v[A].insert(t[i]);
		s.insert(make_pair(v[A].size(),A));
		s.insert(make_pair(v[B].size(),B));
	}
	while ((*(s.begin())).first<l)
	{
		itt=s.end(); itt--;
		A=(*(s.begin())).second; B=(*itt).second;
		s.erase(make_pair(v[A].size(),A)); s.erase(make_pair(v[B].size(),B));
		nw=v[A].begin(); tn=0;
		while (v[A].size()+tn<l&&v[B].size()>l)
		{
			it=v[B].upper_bound(*nw);
			while (nw!=v[A].end()&&(*nw)<(*it)) nw++;
			if (nw==v[A].end()||(*it)!=(*nw))
			{
				ins(B,A,*it);
				t[++tn]=(*it);
				v[B].erase(it);
				nw--;
			}
		}
		for (int i=1; i<=tn; i++) v[A].insert(t[i]);
		s.insert(make_pair(v[A].size(),A));
		s.insert(make_pair(v[B].size(),B));
	}
	while (1)
	{
		itt=s.end(); itt--;
		if ((*itt).first<=r) break;
		A=(*(s.begin())).second; B=(*itt).second;
		s.erase(make_pair(v[A].size(),A)); s.erase(make_pair(v[B].size(),B));
		nw=v[A].begin(); tn=0;
		while (v[A].size()+tn<r&&v[B].size()>r)
		{
			it=v[B].upper_bound(*nw);
			while (nw!=v[A].end()&&(*nw)<(*it)) nw++;
			if (nw==v[A].end()||(*it)!=(*nw))
			{
				ins(B,A,*it);
				t[++tn]=(*it);
				v[B].erase(it);
				nw--;
			}
		}
		for (int i=1; i<=tn; i++) v[A].insert(t[i]);
		s.insert(make_pair(v[A].size(),A));
		s.insert(make_pair(v[B].size(),B));
	}
	pri();
	return 0;
}