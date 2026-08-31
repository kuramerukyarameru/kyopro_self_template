//#include<bits/stdc++.h>
//using namespace std;
//using ll = long long;


struct sieve{
    vector<ll> f;
    vector<ll> primes;
    sieve(ll n=2){
        f.resize(n+1,0);
        f[0]=f[1]=-1;
        for(ll i=2;i<=n;i++){
            if(f[i])continue;
            primes.push_back(i);
            f[i]=i;
            for(ll j=i*i;j<=n;j+=i){
                if(f[j])continue;
                f[j]=i;
            }
        }
    }
    bool is_prime(ll x){return f[x]==x;}
    vector<ll> prime_factors(int x){
        vector<ll> vec;
        while(x!=1){
            vec.push_back(f[x]);
            x/=f[x];
        }
        return vec;
    }
    vector<pair<ll,ll>> prime_factorize(ll x){
        vector<pair<ll,ll>> vec;
        for(ll i=0;i<primes.size();i++){
            if(x%primes[i])continue;
            ll exp=0;
            while(!(x%primes[i])){
                x/=primes[i];
                exp++;
            }
            vec.push_back({primes[i],exp});
        }
        return vec;
    }
    vector<ll> divisors(ll x){
        vector<ll> res;
        for(ll i=1;i*i<=x;i++){
            if(x%i==0){
                res.push_back(i);
                if(i*i!=x)res.push_back(x/i);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};

