#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define next zzyakioi2020
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
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
const int N=100005;
int n;
char S[N];
int next[N],pre[N];
int s[N],t[N];
vector <int> sl,sr;
vector <int> lr,rl,ll,rr;
void link(int l,int r){
	next[t[l]]=r;
	t[l]=t[r];
	s[t[l]]=l;
//	printf("link(%d,%d)\n",l,r);
}
int main(){
	cin>>S+1;
	n=strlen(S+1);
	For(i,1,n){
		if (S[i]=='L'){
			if (sr.empty()){
				s[i]=t[i]=i;
				sl.pb(i);
			}
			else {
				int j=sr.back();
				sr.pop_back();
				t[s[j]]=i;
				next[j]=i;
				s[i]=s[j];
//				printf("link(%d,%d)\n",s[i],i);
				sl.pb(i);
			}
		}
		else {
			if (sl.empty()){
				s[i]=t[i]=i;
				sr.pb(i);
			}
			else {
				int j=sl.back();
				sl.pop_back();
				t[s[j]]=i;
				next[j]=i;
				s[i]=s[j];
//				printf("link(%d,%d)\n",s[i],i);
				sr.pb(i);
			}
		}
	}
	For(i,1,n)
		if (s[t[i]]==i){
			if (S[i]=='L'&&S[t[i]]=='R')
				lr.pb(i);
			if (S[i]=='L'&&S[t[i]]=='L')
				ll.pb(i);
			if (S[i]=='R'&&S[t[i]]=='R')
				rr.pb(i);
			if (S[i]=='R'&&S[t[i]]=='L')
				rl.pb(i);
		}
	int ans=lr.size()+ll.size()+rr.size()+rl.size()-1;
	while (rr.size()&&ll.size()){
		int l=ll.back(),r=rr.back();
		ll.pop_back(),rr.pop_back();
		link(l,r);
		lr.pb(l);
	}
	while (lr.size()>1){
		int l=lr.back();lr.pop_back();
		int r=lr.back();lr.pop_back();
		link(l,r);
		lr.pb(l);
	}
	while (rl.size()>1){
		int l=rl.back();rl.pop_back();
		int r=rl.back();rl.pop_back();
		link(l,r);
		rl.pb(l);
	}
	if (ll.size()){
		int x=ll.back();
		while (lr.size()){
			int y=lr.back();lr.pop_back();
			link(y,x);
			x=y;
		}
		while (rl.size()){
			int y=rl.back();rl.pop_back();
			link(x,y);
		}
	}
	else if (rr.size()){
		int x=rr.back();
		while (lr.size()){
			int y=lr.back();lr.pop_back();
			link(x,y);
		}
		while (rl.size()){
			int y=rl.back();rl.pop_back();
			link(y,x);
			x=y;
		}
	}
	else if (lr.size()&&rl.size()){
		int x=lr.back(),y=rl.back();
		if (x>y)
			swap(x,y);
		next[t[y]]=next[x];
		next[x]=y;
	}
	vector <int> res;
	int T=0;
	For(i,1,n)
		if (!next[i])
			T=i;
		else
			pre[next[i]]=i;
	assert(T);
	while (T){
		res.pb(T);
		T=pre[T];
	}
	reverse(res.begin(),res.end());
	printf("%d\n",ans);
	for (auto i : res)
		printf("%d ",i);
	puts("");
	return 0;
}
//LLLLRRRRRRLLLLLLRRRRR