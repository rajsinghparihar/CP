#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        if (k == 0)
        {
            if (n % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (k == 1)
        {
            if (m % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            if (n % k == 0 || k % n == 0)
            {
                int rest = n * m - k * 2;
                if (rest % 2 == 0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}