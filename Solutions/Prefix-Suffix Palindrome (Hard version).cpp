#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int bas1 = 19260817, bas2 = 13331, mod = 998244353;
int n;
string s;

int get(string str) {
	int fh1 = 0, fh2 = 0, rh1 = 0, rh2 = 0, len = str.length();
	int p1 = 1, p2 = 1, mxn=0;
	for (int i = 0; i < len; i++) {
		char ch = str[i];
		fh1 = (fh1 * bas1 + ch) % mod;
		fh2 = (fh2 * bas2 + ch) % mod;
		rh1 = (rh1 + ch * p1) % mod;
		rh2 = (rh2 + ch * p2) % mod;
		p1 = p1 * bas1 % mod;
		p2 = p2 * bas2 % mod;
		if(fh1==rh1 && fh2==rh2)	mxn=i;
//		cout<<fh1<<' '<<fh2<<'\n';
	}
	return mxn;
}

void sol() {
	cin >> s;
	n = s.length();
	int le = 0, ri = n - 1;
	while (s[le] == s[ri])	le++,ri--;
	if (le >= ri) {
		cout << s << "\n";
		return;
	}
	
	string t = s.substr(le, ri - le + 1);
	int len1 = get(t);
	string rev = t;
	reverse(rev.begin(),rev.end());
	int len2 = get(rev);
//	cout<<len1<<' '<<len2<<'\n';
	string ans=s.substr(0,le);
//	cout<<ans<<' ';
	if(len1>len2)	ans+=t.substr(0,len1+1);
	else			ans+=rev.substr(0,len2+1);
//	cout<<ans<<' ';
	ans+=s.substr(ri+1);
	
	cout<<ans<<'\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while (T--) {
		sol();
	}
	return 0;
}

/*
https://www.luogu.com.cn/problem/CF1326D2
https://codeforces.com/problemset/problem/1326/D2
*/

/*
WITH A SMILE

All the gold in her head
Covered up by the snow
As she goes to the bed
Of a name, she won't know
Candy nose, feeling fine
Stealing life with a line
Blows а kiss, wins а mile
With а smile
She's а dreamer, teaser, however, you need her
Eyes like a shooting star
She's an angel, sinner, tender love spinner
Light up your cold dark heart
She's а dreamer, teaser, however, you need her
Eyes like а shooting star
She's an angel, sinner, tender love spinner
Light up your cold dark heart
Na-na-na-na-na-na-na-na-na
Na-na-na-na-na-na-na-na-na
Na-na-na-na-na-na-na-na-na
Na-na-na-na-na-na-na-na-na
1 AM call her up, will the high be enough?
2 AM sugar rush, from her touch
She's а dreamer, teaser, however, you need her
Eyes like a shooting star
She's an angel, sinner, tender love spinner
Light up your cold dark heart
She's а dreamer, teaser, however, you need her
Eyes like a shooting star
She's an angel, sinner, tender love spinner
Light up your cold dark heart
She's a dream (Na-na-na-na-na-na-na-na-na)
Just a dream (Na-na-na-na-na-na-na-na-na)
She's a dream (Na-na-na-na-na-na-na-na-na)
Just a dream (Na-na-na-na-na-na-na-na-na)
She's a dreamer, teaser, however, you need her
Eyes like a shooting star
She's an angel, sinner, tender love spinner
Light up your cold dark heart
*/

/*
PINKING

La, la-la-la-la-la-la
La-la-la-la-la-la, la-la
La, la-la-la-la-la-la
La-la-la-la
Oh, villains ain't but a thing (ain't but a thing)
Blink of an eye, I'll show them why I'm king
Things change when I'm with you
Baby, facing your smile, it's so disarming
Pop up in my head (my head), dreaming of the day (of the day)
When you come and take me away like a princess
Don't fret, just be brave (be brave)
It's you and me, there ain't no other way
Drop the beat, I feel
Like a roller coaster going up and down
Because (love is-, ooh)
I-I-I know I'm lost
My yearning heart was stolen by you (ooh)
Blu-blu-blu-blush, my spark
Like a blooming flower when I think of you
Because (love is-, ooh)
I-I-I know I'm lost
My yearning heart was stolen by you (ooh)
La, la-la-la-la-la-la
La-la-la-la-la-la, la-la
Yeah, pull up, pull up, do up my hair
Yearning, yearning, being more than friends
Boy, don't play peekaboo-boo
Piggy little Bangboo's gonna lead my way to you
Baby, since the last time we spoke
It's been so long (I miss you)
I'm loco but hope you don't know
Pop up in my head (my head), dreaming of the day (of the day)
When you come and take me away like a princess
Don't fret, just be brave (be brave)
It's you and me, there ain't no other way (slow it down)
Do I seem like I'm not supposed to be
Written in a sugary and dreamy love story?
You are the one makes me wanna sing a love song, ooh, ha
Drop the beat, I feel
Like a roller coaster going up and down
Because (love is-, ooh)
I-I-I know I'm lost
My yearning heart was stolen by you (ooh)
Blu-blu-blu-blush, my spark
Like a blooming flower when I think of you
Because (love is-, ooh)
I-I-I know I'm lost
My yearning heart was stolen by you (ooh)
Yeah, pull up, pull up, do up my hair
Yearning, yearning, being more than friends
Boy, don't play peekaboo-boo
Piggy little Bangboo's gonna lead my way to you (up-up-up)
Pull up, pull up, do up my hair
Yearning, yearning, being more than friends
Boy, don't play peekaboo-boo
Piggy little Bangboo's gonna lead my way to you
*/
/*
The Other Side of Paradise
Glass Animals
When I was young and stupid my love
Left to be a rock and roll star
He told me please don't worry
Wise little smile that spoke so safely
He booked a one-way ticket
Out west that's where they make it
Six kids stuck in a bedsit
To sunswept poolside riches
He met a girl who wore Versace
Pink feather coats and jumbo jewellery
Gonna be a hoop phenomenon
He's gonna be Hakeem Olajuwan
He's got a gold Camaro
He said over the payphone
I try to keep my cool but
My life turns in slow motion
Bye bye baby blue
I wish you could see the wicked truth
Caught up in a rush it's killing you
Screaming at the sun you blow into
Curled up in a grip when we were us
Fingers in a fist like you might run
I settle for a ghost I never knew
Super paradise I held on to
But I settle for a ghost
When I was from in n.o.l.a no one
Left to be a rock and roll star
He'd stay and treat his lady
Give everything to his new baby
I miss him don't you blame me
That boy went stone cold crazy
Caught up in camera lust he's
Chasing that pappy pipe dreams
I know you don't but I
I know you don't but I still try
My thunder shook him down
My thunder came and shook him down
That girl is gone but I
That girl is gone but I still try
I think it's over now
The bullet hit but maybe not
I feel so ******* numb
It hits my head and I feel numb
My body's looking wrong
My body's looking wrong
My body's looking wrong
Bye bye baby blue
I wish you could see the wicked truth
Caught up in a rush it's killing you
Screaming at the sun you blow into
Curled up in a grip when we were us
Fingers in a fist like you might run
I settle for a ghost I never knew
Super paradise I held on to
But I settle for a ghost
*/
/*
I feel the pain and anger, wicked monster, losin' control
I'm ready for a battle, wakened shadow, blood on my soul
Burn it, burning it all, heavens, let them fall~ Haha
They taste of bitter ashes, littered plastic, crumblin away
They glimpse the broken faces, devil racin', searching for faith
Crushing, crushing it all, shadows, watch them crawl~ Hahaha
Creepin' up my brain
Learnin' from my pain
Baby watchin' it burn, send death to isolation
Oh watchin' it burn, ain't got no hesitation
Watchin' it burn, we're fallin' higher
Oh oh oh oh oh oh oh oh oh~
I'll cast your dark intentions, convolution, never before
I'll fight with skeletons, adrenaline, conviction in war
Terror, terror is near, I will shatter you all!
Baby watchin' it burn, send death to isolation
Oh watchin' it burn, ain't got no hesitation
Watchin' it burn, we're fallin' higher
Oh oh oh oh oh oh oh~
Watchin' it burn! Oh watchin' it burn!
Watchin' it burn!
Watchin' it burn!
Like glass that shattered, reaching through the darkness
Voices trailing fires, echo of desires
A world of silence, sound of Death's parading
Phantoms in the shadow, softly waiting…
I'm tearin' it down! Embrace the detonation
Burnin' it loud! Cravin' our damn creation
Breakin' the chain! I'm reachin' for ya
Oh oh oh oh oh oh yeah!!
Shout till the end! This blaze is my salvation!
Sword in the wind! I strike without damnation!
Shatter the skies! No fate, no king, no god!
Fall to my name!
Fall to my name!
Fall to my name!
Fall to my name!
Fall to my name!
Fall to my name!
… my name!
Fall to my name!
*/
/*
IF WE EVER BROKE UP

If you keep wondering if somebody understands
Darling, I don't understand you
If you stay awake at night waiting for somebody right
Baby, oh, your karma is due
Like, I would never hate you
But only if you want to
So much time like who knew? (Like who knew?)
Music we got into
Songs we fell in love to
Boy this feels so wrong too (Ah, ah, ah)
If we ever broke up, I'd never be sad
Thinking about everything that we had
If we ever broke up
If we ever broke up, I'd call your dad
And tell him all the sh!ttiest of things you've said
If wе ever broke up
Boy, don't gеt emotional
'Cause it's not personal
It's just the way, just the way it goes
If we ever broke up, I'd never be sad
Thinking about everything that we had
If we ever broke up
You're living in Wonderland
If you think I'll understand
All the sh!t you put me through
If girls in white dresses and big winter wedding
Is something you want to be true (Yeah)
Then pack up your drama, this selfish dilemma
Is something this sh!t can't undo
Like, I would never hate you
But only if you want to
So much time like, who knew? Woah
If we ever broke up, I'd never be sad
Thinking about everything that we had
If we ever broke up (Ha, ah, ah)
If we ever broke up, I'd call your dad
And tell him all the sh!ttiest of things you've said
If we ever broke up
Boy, don't get emotional
'Cause it's not personal
It's just the way, just the way it goes
If we ever broke up, I'd never be sad
Thinking about everything that we had
If we ever broke up
*/
