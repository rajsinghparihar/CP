#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char s[n];
        string unsorted;
        scanf("%s", s);
        unsorted = s;
        sort(s, s + n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (unsorted[i] == s[i])
                cnt++;
        }
        cout << n - cnt << endl;
    }
    return 0;
}