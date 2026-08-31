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

