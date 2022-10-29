#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL C = 100000;

const int N = 10006;
int aa[N];

LL get_masl(LL a,LL b,LL c,LL d)
{
    return a*C*C*C + b*C*C + c*C + d;
}

void get_back(LL mask,LL &a,LL &b,LL &c,LL &d)
{
    d = mask%C;
    mask/=C;
    c = mask%C;
    mask/=C;
    b=mask%C;
    mask/=C;
    a=mask%C;
}

int main ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i=0;n>i;i++)
    {
        char c=s[i];
        //Gryffindor, Hufflepuff, Ravenclaw and Slytherin
        if (c == 'G') aa[i] = 0;
        else if (c == 'H') aa[i] = 1;
        else if (c == 'R') aa[i] = 2;
        else if (c == 'S') aa[i] = 3;
        else if (c == '?') aa[i] = -1;
    }
    set<LL> st;
    st.insert(0);
    for (int i=0;n>i;i++)
    {
        if (aa[i] != -1)
        {
            set<LL> stt;
            for (LL mask:st)
            {
                LL a,b,c,d;
                get_back(mask,a,b,c,d);
                if (aa[i] == 0)++a;
                else if (aa[i]==1)++b;
                else if (aa[i]==2)++c;
                else if (aa[i]==3)++d;
                stt.insert(get_masl(a,b,c,d));
            }
            st.swap(stt);
        }
        else
        {
            set<LL> stt;
            for (LL mask:st)
            {
                LL a,b,c,d;
                get_back(mask,a,b,c,d);
                LL mn = min({a,b,c,d});
                //cout << "A = " << a << " , b = " << b << " , c = " << c<< " , d=  " << d <<endl;
                if (a == mn) stt.insert(get_masl(a+1,b,c,d));
                if (b == mn) stt.insert(get_masl(a,b+1,c,d));
                if (c == mn) stt.insert(get_masl(a,b,c+1,d));
                if (d == mn) stt.insert(get_masl(a,b,c,d+1));
            }
            st.swap(stt);
        }
        //cout << "i = " << i <<endl;
        //for (LL i:st) cout << i << endl;
    }
    vector<int> ans;
    for (LL mask:st)
    {
        LL a,b,c,d;
        get_back(mask,a,b,c,d);
        LL mn = min({a,b,c,d});
        if (a == mn) ans.push_back(0);
        if (b == mn) ans.push_back(1);
        if (c == mn) ans.push_back(2);
        if (d == mn) ans.push_back(3);
    }
    sort(ans.begin(),ans.end());
    ans.resize(unique(ans.begin(),ans.end()) - ans.begin());
    string names[4] = {"Gryffindor", "Hufflepuff", "Ravenclaw" ,"Slytherin"};
    for (int i:ans) cout << names[i] <<endl;
}