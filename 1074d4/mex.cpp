#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

    
        sort(a.begin(), a.end());

    
        vector<long long> unique;
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] != a[i - 1]) {
                unique.push_back(a[i]);
            }
        }

        
        int longest = 1;
        int current = 1;

        for (int i = 1; i < unique.size(); i++) {
            if (unique[i] == unique[i - 1] + 1) {
                current++;
            } else {
                current = 1;
            }

            longest = max(longest, current);
        }

        
        cout << longest << endl;
    }

    return 0;
}
