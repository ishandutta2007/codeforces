#include<bits/stdc++.h>
using namespace std;
#define db double

int n, a[505000], fl[505000], pre[505000], nex[505000];
long long ans;

bool basa(int i,int j){
	return a[i]<a[j];
}

long long calc(int l,int r){
	long long res=0;
	for (int i=l;i<r;++i){
		pre[i+1]=i;
		nex[i]=i+1;
	}
	vector<int>tmp;
	for (int i=l+1;i<r;++i)
		tmp.push_back(i);
	sort(tmp.begin(),tmp.end(),basa);
	for (auto i:tmp){
		res+=min(a[pre[i]],a[nex[i]]);
		nex[pre[i]]=nex[i];
		pre[nex[i]]=pre[i];
	}
	return res;
}

int main(){
	cin>>n;
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	if (n<=2){
		puts("0"); return 0;
	}
	int p=max_element(a+1,a+n+1)-a; fl[p]=1;
	int llas=0, rlas=0;
	{
		int pre=0;
		for (int i=1;i<p;++i){
			if (a[i]>pre){
				ans+=pre;
				fl[i]=1; pre=a[i];
			}
		}
		llas=pre;
	}
	{
		int pre=0;
		for (int i=n;i>p;--i){
			if (a[i]>pre){
				ans+=pre;
				fl[i]=1; pre=a[i];
			}
		}
		rlas=pre;
	}
	ans+=min(llas,rlas);
	vector<int>pos;
	for (int i=1;i<=n;++i)
		if (fl[i]) pos.push_back(i);
	for (int i=1;i<pos.size();++i){
		ans+=calc(pos[i-1],pos[i]);
	}
	cout<<ans<<endl;
}