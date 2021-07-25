#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int x = min(a, b);
        long long int ans = 0;
        if (b > a)
            ans = (b - a) / 2 + 1;
        else if (a % 2 != b % 2)
            ans = (b - a) / 2;
        else
            ans = (b - a) / 2 + 1;

        if (a == b)
            ans = 0;
        cout << ans << endl;
    }
    return 0;
}