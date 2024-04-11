#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=2000+10;
char ch[M];
vector<pair<int,int> > ans;
int p[M],s[M],tp;
int n,k;
int mth(){
	int now=0,ct=0; tp=0;
	F(i,1,n){
		if (ch[i]=='(') now++,s[++tp]=i;
		else {
			now--;
			p[s[tp]]=i;
			p[i]=s[tp]; tp--;
			if (now==0){
				ct++;
			}
		}
	}
	return ct;
}
int main(){
	int T=read();
	while (T--){
		n=read(),k=read();
		scanf("%s",ch+1);
		int las=0,now=0;
		ans.clear();
		F(i,1,n){
			if (ch[i]=='(') now++;
			else now--;
			if (now==0){
//				cout<<i<<"  fuck\n";
				if (ch[i]=='(') ans.pb(make_pair(las+1,i)),reverse(ch+las+1,ch+i+1);
				las=i;

			}
		}
		while (mth()<k){
			now=0;
			F(i,1,n-1){
				if (ch[i]=='(') now++;
				else now--;
				if (now>1){
					ans.pb(make_pair(i,p[i]));
					reverse(ch+i,ch+p[i]+1);
					if (i+1<p[i]-1) ans.pb(make_pair(i+1,p[i]-1)),reverse(ch+i+1,ch+p[i]);
					break;
				}
			}
		}
		while (mth()>k){
			ans.pb(make_pair(p[1],p[1]+1));
			reverse(ch+p[1],ch+p[1]+1+1);
		}
		cout<<SZ(ans)+1<<"\n";
		F(i,0,SZ(ans)){
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
		}		
//		cout<<(ch+1)<<"\n";
	}
    return 0;
}