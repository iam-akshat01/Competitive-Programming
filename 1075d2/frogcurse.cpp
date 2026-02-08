#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vector<vector<ll>> frog(n);
        bool check = 0;
        ll tot = 0;
        for (int i = 0; i < n; i++)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            ll cost = (b - 1) * a;
            ll rollcost = cost + (a - c);
            tot += cost;
            if (cost >= x)
                check = 1;
            frog[i] = {rollcost, a, b, c};
        }
        if (check || tot >= x)
        {
            cout << 0 << endl;
            continue;
        }

        sort(frog.begin(), frog.end());
        ll rc = frog[n - 1][0];
        if (rc <= 0)
        {
            cout << -1 << endl;
            continue;
        }

        x-=tot;

        ll ans= ceil(1.0*(double(x)/rc));
        cout << ans << endl;
    }
}
