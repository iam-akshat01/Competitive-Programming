#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int initial = 0;
        for(char c : s)
            if(c == '1') initial++;

        int add = 0;

        for(int i = 0; i < n; ){
            if(s[i] == '1'){
                i++;
                continue;
            }

            int j = i;
            while(j < n && s[j] == '0') j++;
            int len = j - i;

            bool left = (i > 0 && s[i-1] == '1');
            bool right = (j < n && s[j] == '1');

            if(left && right)
                add += len / 3;
            else if(left || right)
                add += (len + 1) / 3;
            else
                add += (len + 2) / 3;

            i = j;
        }

        cout << initial + add << "\n";
    }
    return 0;
}
