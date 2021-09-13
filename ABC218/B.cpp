#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int a[26];
    string s = "";
    for (int i = 0; i < 26; i++)
    {
        cin >> a[i];
        s += (a[i] - 1 + 'a');
    }
    cout << s << endl;

    return 0;
}