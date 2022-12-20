#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=100010;
int cnt[30],len;
vector<pair<char,int> > ch;
char s[N];
void solve(){
    memset(cnt,0,sizeof(cnt)),ch.clear();
    scanf("%s",s),len=strlen(s);
    for(int i=0;i<len;i++) cnt[s[i]-'a']++;
    for(int i=0;i<26;i++) if(cnt[i]) ch.pb(mp(i+'a',cnt[i]));
    if(ch.size()<=1){cout<<s<<endl;return;}
    bool have_single_ch=0;char c;
    for(auto tmp:ch)
        if(tmp.se==1) {c=tmp.fi,have_single_ch=1;break;}
    if(have_single_ch){
        cout<<c;
        for(auto tmp:ch){
            if(tmp.fi!=c) cout<<string(tmp.se,tmp.fi);
        }
        cout<<endl;
    }
    else if(len-ch[0].se+1>=ch[0].se-1){
        cout<<ch[0].fi<<ch[0].fi<<ch[1].fi;
        ch[0].se-=2,ch[1].se--;
        int pos=1;
        while(ch[0].se){
            while(pos<ch.size()&&!ch[pos].se) pos++;
            if(pos==ch.size()) break;
            cout<<ch[0].fi<<ch[pos].fi;
            ch[0].se--,ch[pos].se--;
        }
        if(ch[0].se) cout<<ch[0].fi;
        else if(pos<ch.size()){
            while(pos<ch.size()) cout<<string(ch[pos].se,ch[pos].fi),pos++;
        }
        cout<<endl;
    }
    else if(ch.size()==2){
        cout<<ch[0].fi<<string(ch[1].se,ch[1].fi)<<string(ch[0].se-1,ch[0].fi)<<endl;
    }
    else{
        cout<<ch[0].fi<<ch[1].fi;ch[0].se--,ch[1].se--;
        cout<<string(ch[0].se,ch[0].fi)<<ch[2].fi;ch[2].se--;
        for(auto tmp:ch){
            if(tmp.fi==ch[0].fi) continue;
            cout<<string(tmp.se,tmp.fi);
        }
        cout<<endl;
    }
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}