#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
string concat_string(string s, string t) {
    return s + t;
}

int main () {
    string s,t;
    cin >> s; cin >> t;
    unordered_map<char,int> hashmap_s, hashmap_t;
    for (int i = 0; i < s.length(); i++) {
        hashmap_s[s[i]]++;
    }
    for (int i = 0; i < t.length(); i++) {
        hashmap_t[t[i]]++;
    }
    if (hashmap_s == hashmap_t) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    cout << concat_string(s,t) << endl;
    return 0;
}