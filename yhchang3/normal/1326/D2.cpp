#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 10;

int z[MAXN];
void Zvalue(const string &s){
    z[0]=s.size();int l=0,r=0,x;
    for(int i=1;i<s.size();i++){
        if(r<i||z[i-l]>=r-i+1){
            r<i?x=i:x=r+1;
            while(x<s.size()&&s[x]==s[x-i])  x++;
            z[i]=x-i;if(i<x){l=i;r=x-1;};
        }else   z[i]=z[i-l];
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int p;
		for(p = 0;p < s.size() - 1 - p;p++)
			if(s[p] != s[s.size() - 1 - p])
				break;
		string smid = s.substr(p, s.size() - p * 2);
		string revsmid = smid;
		reverse(revsmid.begin(), revsmid.end());
		Zvalue(smid + '$' + revsmid);
		int ls = 0, rs = 0;
		for(int i = 1;i <= smid.size();i++)
			if(i == z[smid.size() * 2 + 1 - i])
				ls = i;
		Zvalue(revsmid + '$' + smid);
		for(int i = 1;i <= smid.size();i++)
			if(i == z[smid.size() * 2 + 1 - i])
				rs = i;
		if(ls > rs)
			cout << s.substr(0, p + ls) + s.substr(s.size() - p,p) << '\n';
		else
			cout << s.substr(0, p) + s.substr(s.size() - p - rs, p + rs) << '\n';

	}
}