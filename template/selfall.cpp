#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <functional>
#include <tuple>
#include <limits>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <sstream>
#include <utility>
#include <bitset>
#include <array>
#include <cstdint>
#include <cassert>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define REP(i,l,r) for(int i=l;i<(r);++i)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define el "\n"
using ll = long long;using vi = vector<int>;using vll = vector<ll>;using vb = vector<bool>;using vs = vector<string>;const ll INF = 1LL<<60;
template<class T> using pq=priority_queue<T>;template<class T> using pq_gt=priority_queue<T,vector<T>,greater<T>>;
template<class T> inline bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;};
template<class T> inline bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;};
const int dr4[4]={-1,0,1,0};const int dc4[4]={0,1,0,-1};
const int dr8[8]={-1,-1,-1,0,1,1,1,0};const int dc8[8]={-1,0,1,1,1,0,-1,-1};
//上右下左//左上上右上右右下下左下左


template<int MOD>
struct modint{
    ll x;
    modint(ll v=0){x=v%MOD;if(x<0)x+=MOD;}
    modint operator+(const modint&a)const{return modint(x+a.x);}
    modint operator-(const modint&a)const{return modint(x-a.x);}
    modint operator*(const modint&a)const{return modint(x*a.x);}
    modint& operator*=(const modint&a){x=x*a.x%MOD;return *this;}
    modint& operator+=(const modint&a){if((x+=a.x)>=MOD)x-=MOD;return *this;}
    modint& operator-=(const modint&a){x-=a.x;if(x<0)x+=MOD;return *this;}
    modint pow(ll n)const{modint res=1;modint a = *this;while(n){if(n&1)res=res*a;a=a*a;n>>=1;}return res;}
    modint inv()const{return pow(MOD-2);}
    modint operator/(const modint &a)const{return *this*a.inv();}
    modint& operator/=(const modint &a){return *this*=a.inv();}
    bool operator==(const modint&a)const{return x==a.x;}
    bool operator!=(const modint&a)const{return x!=a.x;}
    ll val()const{return x;}
};
using mint=modint<998244353>;
struct dsu{
    vector<int> p;vector<int> sz;int group_count;
    dsu(int n){p.resize(n,-1);sz.resize(n,1);group_count=n;}
    int leader(int x){if(p[x]==-1)return x;else return p[x]=leader(p[x]);}
    void merge(int x,int y){x = leader(x);y = leader(y);if(x==y)return;if(sz[x]>sz[y])swap(x,y);sz[y]+=sz[x];p[x]=y;group_count--;}
    bool same(int x,int y){return leader(x)==leader(y);}
    int groups(){return group_count;}
    int size(int x){return sz[leader(x)];}
};
struct comb{
    vector<mint>factor;vector<mint>invfactor;
    comb(int n=1){factor.resize(n+1);invfactor.resize(n+1);factor[0]=1;
        for(int i=1;i<n+1;i++){factor[i]=(mint)i*factor[i-1];}invfactor[n]=factor[n].inv();
        for(int i=n;i>0;i--){invfactor[i-1]=(mint)i*invfactor[i];}}
    mint C(int n,int r){if(n<0||r<0||r>n)return mint(0);return (mint)(factor[n]*invfactor[r]*invfactor[n-r]);}
    mint P(int n,int r){if(n<0||r<0||r>n)return mint(0);return (mint)(factor[n]*invfactor[n-r]);}
    mint H(int n,int r){if(n==0&&r==0)return 1;if(n<0||r<0)return 0;return C(n+r-1,r);}
};
vector<string> rotate90(vector<string> S){
    int H=S.size();int W=S[0].size();vector<string> A(W,string(H,'.'));
    for(int i=0;i<H;i++)for(int j=0;j<W;j++){A[j][H-1-i]=S[i][j];}return A; 
}
vector<string> rotate270(vector<string> S){
    int H=S.size();int W=S[0].size();vector<string> A(W,string(H,'.'));
    for(int i=0;i<H;i++)for(int j=0;j<W;j++){A[W-1-j][i]=S[i][j];}return A; 
}
struct sieve{
    vector<ll> f;vector<ll> primes;
    sieve(ll n=2){f.resize(n+1,0);f[0]=f[1]=-1;
        for(ll i=2;i<=n;i++){if(f[i])continue;primes.push_back(i);f[i]=i;
            for(ll j=i*i;j<=n;j+=i){if(f[j])continue;f[j]=i;}}}
    bool is_prime(ll x){return f[x]==x;}
    vector<ll> prime_factors(int x){vector<ll> vec;
        while(x!=1){vec.push_back(f[x]);x/=f[x];}return vec;}
    vector<pair<ll,ll>> prime_factorize(ll x){vector<pair<ll,ll>> vec;
        for(ll i=0;i<primes.size();i++){if(x%primes[i])continue;ll exp=0;
            while(!(x%primes[i])){x/=primes[i];exp++;}vec.push_back({primes[i],exp});}return vec;}
    vector<ll> divisors(ll x){vector<ll> res;
        for(ll i=1;i*i<=x;i++){if(x%i==0){res.push_back(i);if(i*i!=x)res.push_back(x/i);}}
        sort(res.begin(),res.end());return res;}
};
template<class T,auto op,auto e>
struct segtree{
    int n;vector<T> seg;int N;
    segtree(int N):N(N){
        n=1;while(n<N)n*=2;seg.resize(2*n,e());}
    T all_prod(){return seg[1];}
    T get(int x){return seg[x+n];}
    void set(int x,T y){
        x+=n;seg[x]=y;
        while(x>1){x/=2;seg[x]=op(seg[2*x],seg[2*x+1]);}}
    T prod(int l,int r){
        l+=n;r+=n;if(l>=r)return e();
        T resleft=e();T resright=e();
        while(r>l){
            if(l%2)resleft=op(resleft,seg[l++]);if(r%2)resright=op(seg[--r],resright);
            l/=2;r/=2;}
        return op(resleft,resright);
    }
    template<class F>
    int max_right(int l,F f){
        if(l>=n)return n;l+=n;T right=e();
        do{
            while(l%2==0)l/=2;
            if(!f(op(right,seg[l]))){
                while(l<n){
                    l*=2;
                    if(f(op(right,seg[l]))){right=op(right,seg[l]);l++;}
                }
                return l-n;
            }
            right=op(right,seg[l]);l++;
        }while((l&-l)!=l);
        return N;
    }
    template<class S>
    int min_left(int r,S f){
        if(r<0)return -1;r+=n;T left=e();
        do{
            while(r%2==0)r/=2;
            if(!f(op(seg[r-1],left))){
                while(r<n){
                    r=r*2+1;
                    if(f(op(seg[r],left))){left=op(seg[r],left);r--;}
                }
                return r+1-n;
            }
            left=op(seg[r-1],left);r--;
        }while((r&-r)!=r);
        return -1;
    }        
};
template<class T>
struct fenwick_tree{
    int n;
    vector<T> vec;
    fenwick_tree(int size):n(size){vec.resize(size+1,T(0));}
    void add(int p,T x){for(int i=p+1;i<=n;i+=i&-i){vec[i]+=x;}}
    T sum(int l,int r){T resright=(T)0;T resleft=(T)0;
        for(int i=r;i>0;i-=i&-i){resright+=vec[i];}
        for(int i=l;i>0;i-=i&-i){resleft+=vec[i];}
        return resright-resleft;
    }
};



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    

    return 0;
}
