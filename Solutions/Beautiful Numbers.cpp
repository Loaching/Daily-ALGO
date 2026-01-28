#include<bits/stdc++.h>
#define int long long
using namespace std;
int a, b, n;
const int p = 1e9+7;
vector<int>fac(1500), inv(1500), invs(1500);
void init(int mxn) {
	fac[0] = 1;
	inv[0] = inv[1] = 1;
	invs[0] = 1;
	for (int i = 1; i <= mxn; i++)	fac[i] = i * fac[i - 1] % p;
	for (int i = 2; i <= mxn; i++)	inv[i] = (p - p / i) * inv[p % i] % p;
	for (int i = 1; i <= mxn; i++)	invs[i] = inv[i] * invs[i - 1] % p;
}

int con(int b, int a) {
	return fac[a] * invs[b] % p * invs[a - b] % p;
}

bool check(int k) {
	int c = a * k + b * (n - k);
	while (c) {
		if (c % 10 != a and c % 10 != b)	return false;
		c /= 10;
	}
	return true;
}

void sol() {
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = (ans + check(i) * con(i, n) ) % p;
	}
	cout << ans % p;
}
signed main() {
	ios::sync_with_stdio();
	cin.tie(0);
	cin >> a >> b >> n;
	init(n);
	sol();
	return 0;
}

/*1 3 3*/
