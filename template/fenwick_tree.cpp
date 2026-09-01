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
