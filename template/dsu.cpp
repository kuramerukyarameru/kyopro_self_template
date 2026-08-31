//#include<vector>
//using namespace std;


struct dsu{
    vector<int> p;vector<int> sz;int group_count;
    dsu(int n){p.resize(n,-1);sz.resize(n,1);group_count=n;}
    int leader(int x){if(p[x]==-1)return x;else return p[x]=leader(p[x]);}
    void merge(int x,int y){x = leader(x);y = leader(y);if(x==y)return;if(sz[x]>sz[y])swap(x,y);sz[y]+=sz[x];p[x]=y;group_count--;}
    bool same(int x,int y){return leader(x)==leader(y);}
    int groups(){return group_count;}
    int size(int x){return sz[leader(x)];}
};
