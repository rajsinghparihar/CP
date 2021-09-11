#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;
    cin >> s;
    int n = s.length();
    vector<pair<int, int>> v;
    bool fl1 = false;
    bool fl2 = false;

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'A' && s[i + 1] == 'B')
        {
            v.push_back(make_pair(i, i + 1));
            cout << i << "a";
            i += 2;
        }
        if (s[i] == 'B' && s[i + 1] == 'A')
        {
            v.push_back(make_pair(i, i + 1));
            cout << i << "b";
            i += 2;
        }
        cout << endl;
    }

    return 0;
}