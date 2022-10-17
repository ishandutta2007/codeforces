#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define C(x,y) memset(x,y,sizeof(x))
map<string,int>mp;
struct P{
	string a;
	friend bool operator > (P x,P y){
		return x.a.size()==y.a.size()?x.a.compare(y.a)>0:x.a.size()>y.a.size();
	}
}p;
priority_queue<P,vector<P>,greater<P> >q;
char c[110],ans[110];
string s;
int n,m,cnt[30],now[30],f[110][30];
namespace solve1{
	I solve(int x){
		if(x==1){
			cout<<"? 1 1"<<endl;fflush(stdout);
			cin>>c+1;ans[1]=c[1];return;
		}
		cout<<"? 1 "<<x<<endl;fflush(stdout);
		F(i,1,x*(x+1)/2){
			cin>>c+1;m=strlen(c+1);sort(c+1,c+1+m);p.a.clear();p.a.append(c+1);q.emplace(p);
		}
		cout<<"? 1 "<<x-1<<endl;fflush(stdout);
		F(i,1,x*(x-1)/2){
			cin>>c+1;m=strlen(c+1);sort(c+1,c+1+m);s.clear();s.append(c+1);mp[s]++;
		}
		C(cnt,0);m=0;
		while(!q.empty()){
			s=q.top().a;q.pop();//cout<<"@"<<s<<endl;
			if(mp.count(s)){
				if(mp[s]==1)mp.erase(s);
				else mp[s]--;
				continue;
			}
			C(now,0);
			F(i,0,s.size()-1){
				now[s[i]-'a'+1]++;
			}
			F(i,1,26)if(now[i]>cnt[i]){ans[++m]=i+'a'-1;cnt[i]++;break;}
		}
		reverse(ans+1,ans+1+x);
	}
};
namespace solve2{
	I solve(){
		cout<<"? 1 "<<n<<endl;fflush(stdout);
		F(i,1,n*(n+1)>>1){
			cin>>c+1;m=strlen(c+1);
			F(j,1,m)f[m][c[j]-'a'+1]++;
		}
		re l,r;
		FOR(i,(n-1)>>1,0){
			l=i+1;r=n-i;
			C(cnt,0);
			F(j,l,r-1)cnt[ans[j]-'a'+1]++;
			F(j,1,26)if(f[i+1][j]-f[i][j]>cnt[j]){ans[r]=j+'a'-1;break;}
		}
		cout<<"! "<<ans+1<<endl;fflush(stdout);
	}	
};
int main(){
	cin>>n;
	if(n==1){
		cout<<"? 1 1"<<endl;fflush(stdout);
		cin>>c+1;cout<<"! "<<c[1]<<endl;fflush(stdout);
		return 0;
	}
	solve1::solve(n/2);
	solve2::solve();
	return 0;
}