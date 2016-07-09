#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define edge pair<int,int>

vector<pair<int, edge>> edgelist,mst;
int parent[3001],rnk[3001];
int total=0;

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    x = findset(x), y = findset(y);
    if (rnk[x] > rnk[y]){
        parent[y]=x;
        rnk[x]+=rnk[y];
    }
    else{
        parent[x]= y;
        rnk[y]+=rnk[x];
    }
}

void Kruskal(){
    sort(edgelist.begin(),edgelist.end());
    for (int i = 0; i < edgelist.size(); ++i) {
        int pu= findset(edgelist[i].second.first);
        int pv= findset(edgelist[i].second.second);
        if(pu != pv){
            mst.push_back(edgelist[i]);
            total+=edgelist[i].first;
            unionset(pu,pv);
        }
    }
}

void printmst() {
    for(int i=0; i<mst.size(); i++) {
        cout<<mst[i].second.first<<" "<<mst[i].second.second<<" "<<mst[i].first<<endl;
    }
    cout<<"Minimum Weight:"<<total;
}

int main() {
    int n,m,x,y,w;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        edgelist.push_back(pair<int,edge>(w,edge(x,y)));
    }
    int s;
    cin>>s;
    for(int i=0; i<=n; i++){
        parent[i]=i;
        rnk[i]=1;
    }
    Kruskal();
    printmst();
    return 0;
}
