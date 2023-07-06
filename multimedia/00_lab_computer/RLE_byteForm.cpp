#include <bits/stdc++.h>
//  Run Length Encoding
using namespace std;
string encode(string s){
    char prev = '?';
    int cnt = 1;
    string ans;
    for (char &ch : s)
    {
        if (ch == prev and cnt < 128)
        {
            cnt++;
        }
        else
        {
            ans += prev;
            ans += cnt;
            cnt = 1;
        }
        prev = ch;
    }
    ans += prev;
    ans += cnt;
    return ans.substr(2, ans.size() - 2);
}

string decode(string s){
    string ans;
    for (int i = 0; i < s.size(); i += 2)
        ans += string(s[i + 1], s[i]);
    return ans;
}
int main(){
    int i, j, k, n, m, val, t = 0, test;
    freopen("codeToRLE.txt", "r", stdin);
    string s, tem;
    while (getline(cin, tem))
    {
        s += tem + '\n';
    }
    s = s.substr(0, s.size() - 1);

    freopen("encoded.txt", "w", stdout);
    string encoded = encode(s);
    cout << encoded;

    freopen("decoded.txt", "w", stdout);
    string decoded = decode(encoded);
    cout << decoded;
    // free();   //if pointer array
    return 0;
}