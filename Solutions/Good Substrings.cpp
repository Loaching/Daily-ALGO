#include<bits/stdc++.h>
#define int long long
using namespace std;
int base1 = 19260817, base2 = 131, m, mod = 998244353, n, len;
vector<int>h1, h2;
string s, k;

void sol() {
	vector<pair<int, int>>mew;
	getline(cin, s);
	getline(cin, k);
	len = s.length();
	cin >> m;
	for (int i = 0; i < len; i++) {
		int h1 = 0, h2 = 0, bad = 0;
		for (int j = i; j < len; j++) {
			bad += (k[s[j] - 'a'] == '0');
			if (bad > m)	continue;
			h1 = (h1 * base1 % mod + s[j]) % mod;
			h2 = (h2 * base2 % mod + s[j]) % mod;
			mew.push_back({h1, h2});
		}
	}
	sort(mew.begin(), mew.end());
	mew.erase(unique(mew.begin(), mew.end()), mew.end());
	cout << mew.size();
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	sol();

	return 0;
}
/*
https://codeforces.com/problemset/problem/271/D

La la, la la la... La la, la la la..
Hush, don't speak
安静 别说话
When you spit your venom, keep it shut I hate it
你的口中吐出恶毒的话语 我不想再听
When you hiss and preach
当你滔滔不绝
About your new messiah 'cause your theories catch fire
你的理论被推翻 你又阐述新的观点
I can't find your silver lining
我看不出你有什么闪光点
I don't mean to judge
我并不想指责什么
But when you read your speech, it's tiring
但是请审视你的话语 如此让人厌烦
Enough is enough
我已忍无可忍
I'm covering my ears like a kid
我像孩子一样堵住耳朵
When your words mean nothing, I go la la la
当你的话语毫无意义时 我就高唱:啦啦啦
I'm turning up the volume when you speak
你一说话我就把音量开大
Cause if my heart can't stop it, I find a way to block it
若我无法让你停止说话 我会寻找另一种方法
I go
我会高唱
La la, la la la... La la, la la la...
I find a way to block it, I go
寻找另一种方法 我会高唱
La la, la la la... La la, la la la...
Yes our love is running out of time
我们的爱无法通过时间的考验
I won't count the hours, rather be a coward
我不会细数恋爱的时光 宁愿做个懦夫
When our words collide
每当我们争吵时
I'm gonna drown you out before I lose my mind
我会在抓狂之前用声音将你淹没
I can't find your silver lining
我看不出你有什么闪光点
I don't mean to judge
我并不想指责什么
But when you read your speech, it's tiring
但是请审视你的话语 如此让人厌烦
Enough is enough
我已忍无可忍
I'm covering my ears like a kid
我像孩子一样堵住耳朵
When your words mean nothing, I go la la la
当你的话语毫无意义时 我就高唱：啦啦啦
I'm turning up the volume when you speak
你一说话我就把音量开大
Cause if my heart can't stop it, I find a way to block it
若我无法让你停止说话 我会寻找另一种方法
I go
我会高唱
La la la la la... La la la la la...
I find a way to block it ,I go
寻找另一种方法 我会高唱
La la la la la... La la la la la...
I find a way to block you, oh
我会寻找另一种方法
La la la la la... La la la la la...
I find a way to block it,I go
寻找另一种方法 我会高唱
La la la la la... La la la la la...
I'm covering my ears like a kid
我像孩子一样堵住耳朵
When your words mean nothing, I go la la la
当你的话语毫无意义时 我就高唱:啦啦啦
I'm turning up the volume when you speak
你一说话我就把音量开大
Cause if my heart can't stop it, I find a way to block it
若我无法让你停止说话 我会寻找另一种方法
I go
我会高唱
I'm covering my ears like a kid
我像孩子一样堵住耳朵
When your words mean nothing, I go la la la
当你的话语毫无意义时 我就高唱 啦啦啦
I'm turning up the volume when you speak
你一说话我就把音量开大
Cause if my heart can't stop it, I find a way to block it
若我无法让你停止说话
我会寻找另一种方法
I go
我会高唱
La la la la la... La la la la la...
La la la la la... La la la la la...
*/
