//#include<bits/stdc++.h>
//using namespace std;
//rotate90 ->右回転
//rotate270 ->左回転
vector<string> rotate90(vector<string> S){
    int H=S.size();int W=S[0].size();vector<string> A(W,string(H,'.'));
    for(int i=0;i<H;i++)for(int j=0;j<W;j++){A[j][H-1-i]=S[i][j];}return A; 
}
vector<string> rotate270(vector<string> S){
    int H=S.size();int W=S[0].size();vector<string> A(W,string(H,'.'));
    for(int i=0;i<H;i++)for(int j=0;j<W;j++){A[W-1-j][i]=S[i][j];}return A; 
}
