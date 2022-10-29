#include <bits/stdc++.h>
using namespace std;

const int K = 11;
const int N = 50006;
int k;

int s[N][K];

struct Person
{
    int mx[K];
    int mn[K];
    int sz;
    Person(){}
    Person(int *s)
    {
        for (int i=1;k>=i;i++)
        {
            mx[i] = s[i];
            mn[i] = s[i];
        }
        sz=1;
    }
};

bool operator<(const Person &p1,const Person &p2)
{
    for (int i=1;k>=i;i++)
    {
        if (p1.mx[i] >= p2.mx[i]) return false;
    }
    return true;
}

Person doo(const Person &p1,const Person &p2)
{
    Person ret = Person(s[0]);
    ret.sz = p1.sz + p2.sz;
    for (int i=1;k>=i;i++)
    {
        ret.mx[i] = max(p1.mx[i],p2.mx[i]);
        ret.mn[i] = min(p1.mn[i],p2.mn[i]);
    }
    return ret;
}

bool should_eat(const Person &p1,const Person &p2)
{
    for (int i=1;k>=i;i++)
    {
        if (p1.mx[i] > p2.mn[i]) return true;
    }
    return false;
}

int main ()
{
    int n;
    scanf("%d %d",&n,&k);
    set<Person> st;
    st.insert(Person(s[0]));
    for (int i=1;n>=i;i++)
    {
        for (int j=1;k>=j;j++)
        {
            scanf("%d",&s[i][j]);
        }
        Person now = Person(s[i]);
        //auto iter = lower_bound(st.begin(),st.end(),now);
        auto iter = st.lower_bound(now);
        if (iter == st.end())
        {
            st.insert(now);
        }
        else
        {
            vector<Person> erased;
            Person nnew = now;
            while (iter != st.end())
            {
                Person iterr = *iter;
                if (should_eat(nnew,iterr) )
                {
                    nnew = doo(iterr,nnew);
                    erased.push_back(iterr);
                }
                else
                {
                    break;
                }
                iter++;
            }
            for (auto i:erased) st.erase(i);
            st.insert(nnew);
        }
        Person _ = (*(--st.end()));
        printf("%d\n",_.sz);
    }
}