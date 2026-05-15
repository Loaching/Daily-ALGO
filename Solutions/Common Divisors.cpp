#include<bits/stdc++.h>
#define int long long
using namespace std;

const int b1 = 19260817, b2 = 13331, md = 998244353;
string s1, s2;
vector<int> h1, h2, p1, p2;

int gh1(int l, int r) {
    return ((h1[r] - h1[l - 1] * p1[r - l + 1]) % md + md) % md;
}

int gh2(int l, int r) {
    return ((h2[r] - h2[l - 1] * p2[r - l + 1]) % md + md) % md;
}

void ihsh(string &str) {
    int len = str.size();
    for (int i = 1; i <= len; i++) {
        char ch = str[i-1];
        h1[i] = (h1[i - 1] * b1 + ch) % md;
        h2[i] = (h2[i - 1] * b2 + ch) % md;
    }
}

bool chk(int k, string &str) {
    int len = str.size();
    if (len % k != 0) return false;
    int st1 = gh1(1, k), st2 = gh2(1, k);
    for (int i = k; i < len; i += k) {
        if (gh1(i+1, i+k) != st1 || gh2(i+1, i+k) != st2)
            return false;
    }
    return true;
}

int getl(string &s, string &T) {
    int len = s.size();
    h1.assign(len+5, 0);
    h2.assign(len+5, 0);
    ihsh(s);
    for(int k = 1; k <= len; k++) {
        if(chk(k, s)) {
            T = s.substr(0, k);
            return len / k;
        }
    }
    T = s;
    return 1;
}

int gcd(int a, int b) {
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int cntd(int x) {
    int res = 0;
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            res++;
            if(i != x / i) res++;
        }
    }
    return res;
}

void sol() {
    cin >> s1 >> s2;
    
    string T1, T2;
    int c1 = getl(s1, T1);
    int c2 = getl(s2, T2);
    
    if(T1 != T2) {
        cout << 0 << endl;
        return;
    }
    
    cout << cntd(gcd(c1, c2)) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    p1.resize(600010);
    p2.resize(600010);
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= 600000; i++) {
        p1[i] = p1[i - 1] * b1 % md;
        p2[i] = p2[i - 1] * b2 % md;
    }
    
    sol();
    return 0;
}
/*
https://www.luogu.com.cn/problem/CF182D
*/
