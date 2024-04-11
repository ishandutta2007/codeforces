#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+5,mod=1e9+7;
struct Mat{
	static const int N=3;
	int v[N][N];
	Mat(){}
	Mat(int x){
		memset(v,0,sizeof v);
		if (x==1)
			for (int i=0;i<N;i++)
				v[i][i]=1;
	}
	void set(int p){
		v[0][0]=0,v[0][1]=1,v[0][2]=0;
		v[1][0]=1,v[1][1]=1,v[1][2]=0;
		v[2][0]=0,v[2][1]=p,v[2][2]=1;
	}
	void print(){
		for (int i=0;i<3;i++,puts(""))
			for (int j=0;j<3;j++)
				printf("%3d ",v[i][j]);
		puts("");
	}
	Mat operator * (Mat x){
		Mat ans(0);
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				for (int k=0;k<N;k++)
					ans.v[i][j]=(1LL*v[i][k]*x.v[k][j]+ans.v[i][j])%mod;
		return ans;
	}
	Mat operator ^ (LL y){
		Mat x=*this,ans(1);
		while (y){
			if (y&1LL)
				ans=ans*x;
			x=x*x,y>>=1;
		}
		return ans;
	}
};
LL k;
int m;
struct STR{
	string s;
	int id,ans;
}s[N];
string s1="a",s2="b",s3="ba",s4="bab";
bool cmpL(STR a,STR b){
	if (int(a.s.size())==int(b.s.size()))
		return a.s<b.s;
	return a.s.size()<b.s.size();
}
bool cmpid(STR a,STR b){
	return a.id<b.id;
}
int Fail[N];
char S1[N],S2[N];
int KMP(string &s1,string &s2){
	int n=s1.size(),m=s2.size();
	for (int i=1;i<=n;i++)
		S1[i]=s1[i-1];
	for (int i=1;i<=m;i++)
		S2[i]=s2[i-1];
	Fail[0]=Fail[1]=0;
	for (int i=2;i<=m;i++){
		int k=Fail[i-1];
		while (k&&S2[i]!=S2[k+1])
			k=Fail[k];
		if (S2[i]==S2[k+1])
			k++;
		Fail[i]=k;
	}
	int ans=0,k=0;
	for (int i=1;i<=n;i++){
		while (k&&S1[i]!=S2[k+1])
			k=Fail[k];
		if (S1[i]==S2[k+1])
			k++;
		if (k==m){
			ans++;
			k=Fail[k];
		}
	}
	return ans;
}
int main(){
	cin >> k >> m;
	for (int i=1;i<=m;i++){
		cin >> s[i].s;
		s[i].id=i;
	}
	sort(s+1,s+m+1,cmpL);
	int cnt=1;
	for (int i=1;i<=m;i++){
		while (cnt<k&&int(s1.size())<int(s[i].s.size())){
			s1=s4+s3;
			swap(s1,s2),swap(s2,s3),swap(s3,s4);
			cnt++;
		}
		if (cnt==k){
			s[i].ans=KMP(s1,s[i].s);
			continue;
		}
		int a=KMP(s1,s[i].s),b=KMP(s2,s[i].s),c=KMP(s3,s[i].s),d=KMP(s4,s[i].s);
		int del1=c-a-b,del2=d-b-c;
		Mat st(0),tn1(0),tn2(0);
		st.v[0][0]=a,st.v[0][1]=b,st.v[0][2]=1;
		tn1.set(del1),tn2.set(del2);
		st=st*((tn1*tn2)^((k-cnt)/2));
		if ((k-cnt)&1)
			st=st*tn1;
		s[i].ans=st.v[0][0];
	}
	sort(s+1,s+m+1,cmpid);
	for (int i=1;i<=m;i++)
		printf("%d\n",s[i].ans);
	return 0;
}