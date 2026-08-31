template<class T,auto op,auto e>
struct segtree{
    int n;vector<T> seg;
    segtree(int N){
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
        return n;
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
