#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
vector<int>p1, p2;
const int bas1 = 19260817, bas2 = 13331, mod = 998244353;
int n, m;
vector<pair<int, int>>ini;
string s, p;
void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		int len = s.length();
		int h1 = 0, h2 = 0;
		for (int q = 0; q < len; q++) {
			h1 = (h1 * bas1 % mod + s[q]) % mod;
			h2 = (h2 * bas2 % mod + s[q]) % mod;
		}
		for (int j = 0; j < len; j++) {
			for (int luohaijun = 'a'; luohaijun <= 'c'; luohaijun++) {
				if (luohaijun == s[j])	continue;
				int hh1, hh2;
				hh1 = (h1 + (luohaijun - s[j]) * p1[len - j - 1] % mod + mod) % mod;
				hh2 = (h2 + (luohaijun - s[j]) * p2[len - j - 1] % mod + mod) % mod;
				ini.push_back({hh1, hh2});
			}
		}
	}
	sort(ini.begin(), ini.end());
	ini.erase(unique(all(ini)),ini.end());
	for (int i = 1; i <= m; i++) {
		cin >> s;
		int len = s.length();
		int h1 = 0, h2 = 0;
		for (int q = 0; q < len; q++) {
			h1 = (h1 * bas1 % mod + s[q]) % mod;
			h2 = (h2 * bas2 % mod + s[q]) % mod;
		}
		auto tmp = make_pair(h1, h2);
//		int k = lower_bound(ini.begin(), ini.end(), tmp) - ini.begin();
//		if (ini[k].first == h1 && ini[k].second == h2)	cout << "YES\n";
//		else											cout << "NO\n";
		if(binary_search(ini.begin(),ini.end(),tmp))	cout<<"YES\n";
		else											cout<<"NO\n";
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	p1.resize(600010);
	p2.resize(600010);
	p1[0] = p2[0] = 1;
	for (int i = 1; i <= 600010; i++) {
		p1[i] = p1[i - 1] * bas1 % mod;
		p2[i] = p2[i - 1] * bas2 % mod;
	}

	sol();

	return 0;
}
/*
https://www.luogu.com.cn/problem/CF514C
https://codeforces.com/problemset/problem/514/C

Mend your pace, sway to the beat
加快步伐，紧随这律动摇摆
Hands up! Embrace who you wanna be
高举双手，拥理想自我入怀
We’re reaching heights unseen
我们一起抵达未见之境
Feel the fire deep within
感受着心底火焰
You’re the key to where my trust begins
你令我轻启心扉，交托信赖
Join-my-dream, it’s just the right time
加入我的梦境吧，大好时机已来
Leave it all behind
把一切都抛开
Get ready now
现在做好准备——
Rise
跃升
Up into my world
闯入我的世界
Renew your definition
更新你的定义
World so high, let me show
向你展示这里的超乎寻常
And hear my declaration
让你听见我的宣言
No more ties
“从此，再无拘束”
Off the ground and tap your feet
高高跳起，用双脚叩出节拍
Look, stars are near when you feel the beat
当你感受到律动，繁星已近在咫尺
We’re bound for a greater height
我们一起触碰更高的天空
Take a leap into the blazing,
要向炽燃中飞跃
Don’t lose yourself in mundanity
不在凡俗里沉沦
Join-my-dream, it is the right time
加入我的梦境吧，大好时机已来
Leave it all behind
把一切都抛开
Get ready now
现在做好准备
(Sing along)
（随我一起高唱）
Welcome to my world
欢迎来到我的世界
Renew your definition
更新你的定义
World so high, let me show
向你展示这里的超乎寻常
And hear my declaration
让你听见我的宣言
No more ties
“从此，再无拘束”
Welcome to my world
欢迎来到我的世界
Renew your definition
更新你的定义
World so high, let me show
向你展示这里的超乎寻常
And hear my declaration
让你听见我的宣言
Now hear my declaration
现在请静静地聆听
Welcome to my world
欢迎来到我的世界
Renew your definition
更新你的定义
World so high, we’ll show
我们要向世人证明这里的超乎寻常
and go beyond horizon
越过地平线
Side by side
肩并着肩
*/
