#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
int n,a[M],ct[M];
vector<int> v[M];
int t[M*2],s[M];
int main(){
	n=read();
	F(i,1,n) a[i]=read(),ct[a[i]]++;
	int mx=0,val=0;
	bool fl=0;
	F(i,1,n){
		if (ct[i]>mx){
			fl=0;
			val=i;
			mx=ct[i];
		}
		else if (ct[i]==mx){
			fl=1;
		}
	}
	if (fl){
		cout<<n<<"\n";
		return 0;
	}
	int B=sqrt(n);
	int ans=0;
	F(i,1,n){
		if (i^val && ct[i]>=B){
			ms(t,-1); t[0+n]=0;
			F(j,1,n){
				s[j]=s[j-1]+(a[j]==val ? 1 : (a[j]==i ? -1 : 0));
				if (t[s[j]+n]!=-1){
					ans=max(ans,j-t[s[j]+n]);
				}
				else t[s[j]+n]=j;
			}
		}
	}
	F(o,1,B-1){
		ms(t,0); ms(ct,0);
		t[0]=n;
		int j=0,mx=0;
//		cerr<<o<<"   wowow\n";
		F(i,1,n){
			while (j<n && ct[a[j+1]]<o){
				j++;
				t[ct[a[j]]]--;
				ct[a[j]]++;
				t[ct[a[j]]]++;
			}
			if (t[o]>=2) ans=max(ans,j-i+1);
			t[ct[a[i]]]--;
			ct[a[i]]--;
			t[ct[a[i]]]++;
		}
	}
	cout<<ans<<"\n"; 
	return 0;
}
/*
*/