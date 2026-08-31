//#include<vector>
//using namespace std;
//using mint=modint<998244353>;
struct comb{
    vector<mint>factor;vector<mint>invfactor;
    comb(int n=1){factor.resize(n+1);invfactor.resize(n+1);factor[0]=1;
        for(int i=1;i<n+1;i++){factor[i]=(mint)i*factor[i-1];}invfactor[n]=factor[n].inv();
        for(int i=n;i>0;i--){invfactor[i-1]=(mint)i*invfactor[i];}}
    mint C(int n,int r){if(n<0||r<0||r>n)return mint(0);return (mint)(factor[n]*invfactor[r]*invfactor[n-r]);}
    mint P(int n,int r){if(n<0||r<0||r>n)return mint(0);return (mint)(factor[n]*invfactor[n-r]);}
    mint H(int n,int r){if(n==0&&r==0)return 1;if(n<0||r<0)return 0;return C(n+r-1,r);}
};
