#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define loop(i,a,b)           for(ll i=a;i<=b;++i)
#define boost				  ios_base::sync_with_stdio(0);
#define eb                    emplace_back
#define mp                    make_pair
#define clr(x)                x.clear()
#define MOD                   1e9+7
#define itoc(c)               ((char)(((int)'0')+c))
#define ctoi(c)               ((int)(((int)c)-'0'))
#define all(p)                p.begin(),p.end()
#define iscn(num)             scanf("%d",&num);
#define scn(num)              scanf("%lld",&num);
#define scn2(num,num2)        scanf("%lld%lld",&num,&num2);
#define dbg(x)                cerr <<"( "<<#x << " = " << x << " )"<<endl
using namespace std;
template<class T >T set_bit(T N,T pos){return N=N | (1<<pos);}
template<class T >T reset_bit(T N,T pos){return N= N & ~(1<<pos);}
template<class T > bool check_bit(T N,T pos){return (bool)(N & (1<<pos));}
template<class T>void bin_print(T N){bitset<25>bit(N);cerr<<bit.to_string()<<"\n";}
template <class T > void max_self(T &a, T b){
	a=max(a,b);
}
template <class T > void min_self(T &a, T b){
	a=min(a,b);
}
template <class T > void add_self(T &a, T b){
	a+=b;
}
////////////////////////

const ll INF = 2e18 + 99;
typedef pair<ll,ll> Pair;
typedef vector<int> vec;;

void ara_read(vec &v,ll n){
	ll temp;
	for(ll i=0; i< n; i++){
		scanf("%lld",&temp);
		v.emplace_back(temp);
	}
}
void ara_print(vec &v){
	for(ll x : v)
		printf("%lld ",x);
	puts("");
}
////////////////////////

int main()
{
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		int n;
		scanf("%d",&n);
		bool grid[n][n];
		for(int i=0; i< n ; i++){
			for(int j=0; j< n; j++){
				int temp=0;
				scanf("%d",&temp);
				grid[i][j] = (bool) temp;
			}
		}
		
		ll nax= (1<<n);
		vector < ll > dp(nax);
		dp[0] = 1;
		
		for(ll mask=0; mask< nax-1; mask++){
			ll cnt = (ll) __builtin_popcount(mask);
			for(ll x=0; x<n; x++){
				if(grid[cnt][x] and !check_bit(mask,x)){
					ll temp = mask ^ (1<<x) ;
					add_self(dp[temp],dp[mask]);
					
				}
			}
		}
		printf("%lld\n",dp[nax-1]);
	}
	
    return 0;
}
