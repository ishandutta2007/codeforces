#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "D"
int n;
int x, y, u, v, l, r;
map <pair <pair <int, int>, pair <int, int> >, int> M; 
int query(int x, int y, int u, int v){
	if(M.find(mp(mp(x, y), mp(u, v)))!=M.end()) return M[mp(mp(x, y), mp(u, v))];
	printf("? %d %d %d %d\n", x, y, u, v);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return M[mp(mp(x, y), mp(u, v))]=res;
}
vector <pair<pair<int, int>, pair<int, int> > > ans;
void findrect(int x, int y, int u, int v, int side){
	if(side==1||side==3){
		if(side==1){//sure x
			l=x; r=u;
			while(l<=r){
				int m=(l+r)/2;
				int res;
				if(0&&m==u) res=1;
				else res=query(x, y, m, v);
				if(res>=1){
					u=m;
					r=m-1;
				}
				else
					l=m+1;
			}
		}
		if(side==3){//sure u
			l=x; r=u;
			while(l<=r){
				int m=(l+r)/2;
				int res;
				if(0&&m==x) res=1;
				else res=query(m, y, u, v);
				if(res>=1){
					x=m;
					l=m+1;
				}
				else
					r=m-1;
			}
		}
		l=y; r=v;
		while(l<=r){
			int m=(l+r)/2;
			int res;
			if(0&&m==v) res=1;
			else res=query(x, y, u, m);
			if(res>=1){
				v=m;
				r=m-1;
			}
			else
				l=m+1;
		}
		l=y; r=v;
		while(l<=r){
			int m=(l+r)/2;
			int res;
			if(0&&m==y) res=1;
			else res=query(x, m, u, v);
			if(res>=1){
				y=m;
				l=m+1;
			}
			else
				r=m-1;
		}
	}
	else{
		if(side==2){//sure y
			l=y; r=v;
			while(l<=r){
				int m=(l+r)/2;
				int res;
				if(0&&m==v) res=1;
				else res=query(x, y, u, m);
				if(res>=1){
					v=m;
					r=m-1;
				}
				else
					l=m+1;
			}
		}
		if(side==4){//sure v
			l=y; r=v;
			while(l<=r){
				int m=(l+r)/2;
				int res;
				if(0&&m==y) res=1;
				else res=query(x, m, u, v);
				if(res>=1){
					if(res==1) y=m;
					l=m+1;
				}
				else
					r=m-1;
			}
		}
		l=x; r=u;
		while(l<=r){
			int m=(l+r)/2;
			int res;
			if(0&&m==u) res=1;
			else res=query(x, y, m, v);
			if(res>=1){
				u=m;
				r=m-1;
			}
			else
				l=m+1;
		}
		l=x; r=u;
		while(l<=r){
			int m=(l+r)/2;
			int res;
			if(0&&m==x) res=1;
			else res=query(m, y, u, v);
			if(res>=1){
				x=m;
				l=m+1;
			}
			else
				r=m-1;
		}
	}
	ans.pb(mp(mp(x, y), mp(u, v)));
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
	scanf("%d", &n);
	x=y=1;
	u=v=n;
	l=1; r=n;
	while(l<=r){
		int m=(l+r)/2;
		int res;
		if(0&&m==v) res=1;
		else res=query(1, 1, n, m);
		if(res>=1){
			if(res==1) v=m;
			r=m-1;
		}
		else
			l=m+1;
	}
	l=1; r=n;
	while(l<=r){
		int m=(l+r)/2;
		int res;
		if(0&&m==y) res=1;
		else res=query(1, m, n, n);
		if(res>=1){
			if(res==1) y=m;
			l=m+1;
		}
		else
			r=m-1;
	}
	if(y>v){
		findrect(1, y, n, n, 2);
		findrect(1, 1, n, v, 4);
	}
	else{
		x=y=1;
		u=v=n;
		l=1, r=n;
		while(l<=r){
			int m=(l+r)/2;
			int res;
			if(0&&m==u) res=1;
			else res=query(1, 1, m, n);
			if(res>=1){
				if(res==1) u=m;
				r=m-1;
			}
			else
				l=m+1;
		}
		l=1; r=n;
		while(l<=r){
			int m=(l+r)/2;
			int res;
			if(0&&m==x) res=1;
			else res=query(m, 1, n, n);
			if(res>=1){
				if(res==1) x=m;
				l=m+1;
			}
			else
				r=m-1;
		}
		findrect(x, 1, n, n, 1);
		findrect(1, 1, u, n, 3);
	}
	printf("!");
	FOR(i, 0, 1)
		printf(" %d %d %d %d", ans[i].first.first, ans[i].first.second, ans[i].second.first, ans[i].second.second);
}