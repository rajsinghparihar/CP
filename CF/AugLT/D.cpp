#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.ff > b.ff)
    {
        return true;
    }
    else if (a.ff == b.ff)
    {
        if (a.ss > b.ss)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ll t, n, k, i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> v(n);
        vector<pair<ll, ll>> vp(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
            if (i != 0)
            {
                vp[i].ff = v[i];
                vp[i].ss = i;
            }
        }
        ll c = 0;
        ll top = v[0];
        sort(vp.begin(), vp.end(), cmp);
        ll x = 0, q = 0;
        for (i = 0; i < n; i++)
        {
            //cout<<vp[i].ff<<" "<<top<<" "<<x<<" "<<vp[i].ss<<"\n";
            if (vp[i].ff <= top && x < vp[i].ss)
            {
                //cout<<"hii\n";
                top = vp[i].ff;
                x = vp[i].ss;
                c++;
            }
            else if (vp[i].ff > top && x < vp[i].ss)
            {
                q = 1;
                break;
            }
        }
        //cout<<x<<" <== \n";
        if (q == 1)
        {
            c = -1;
        }
        cout << c << "\n";
    }
}