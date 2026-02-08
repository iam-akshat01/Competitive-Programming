#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        ll x, y;
        cin >> n >> x >> y;

        vector<ll> a(n), q(n);
        ll sumq = 0;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            q[i] = a[i] / x;
            sumq += q[i];
        }

        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll curr = a[i] + (sumq - q[i]) * y;
            ans = max(ans, curr);
        }

        cout << ans << '\n';
    }
    return 0;
}
