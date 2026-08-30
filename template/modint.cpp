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
//using mint=modint<998244353>;
