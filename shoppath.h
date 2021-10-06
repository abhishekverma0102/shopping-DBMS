#include <iostream>
#include<list>
#include<set>
#include<stack>
#include<unordered_map>
using namespace std;
template<typename T>
class graph{
unordered_map<T,list<pair<T,int>>> l;
unordered_map<T,list<pair<T,T>>> givedir;
public:
void addedge(T x,T y,string dir,int dis,bool bi=true){
    l[x].push_back(make_pair(y,dis));
    givedir[x].push_back(make_pair(y,dir));
    if(bi){
        l[y].push_back(make_pair(x,dis));
        if(dir=="left")
            givedir[y].push_back(make_pair(x,"right"));
        else
            givedir[y].push_back(make_pair(x,"left"));
    }
}
void djki(T src,T destination){
    unordered_map<T,int> dist;
    for(auto j:l){
        dist[j.first]=214000;
    }
    unordered_map<T,T> parent;
    set<pair<int,T>> s;
    dist[src]=0;
    s.insert(make_pair(0,src));
    while(!s.empty()){
        auto p= *(s.begin());
        T node=p.second;
        int nodedis=p.first;
        s.erase(s.begin());

        for(auto nbr:l[node]){

            if(nodedis+nbr.second<dist[nbr.first]){
                T des=nbr.first;
                parent[nbr.first]=node;

                auto f=s.find(make_pair(dist[des],des));
                if(f!=s.end()){
                    s.erase(f);
                }
                dist[des]=nodedis+nbr.second;
                s.insert(make_pair(dist[des],des));
            }

        }
    }
   // for(auto d:dist){
      //  cout<<d.first<<" is located at a distance of "<<d.second<<endl;
    //}
    cout<<endl<<endl<<endl;
    //for( auto par: parent){
      //  cout<<par.first<<"      "<<par.second<<endl;
    //}
       cout<<"You should follow this path: "<<endl;
    stack<T> storepath;
    stack<int> distancepath;
    T fin=destination;
    while(fin!=src){
         T temp=parent[fin];
         int distance= dist[fin]-dist[temp];
         storepath.push(fin);
         distancepath.push(distance);
       // cout<<fin<<" <---"<<distance<<" m ---- ";

        fin=temp;

    }
     storepath.push(src);

     while(!distancepath.empty()){
        T tem=storepath.top();
            storepath.pop();
        string direction;
        for(auto n: givedir[tem]){
            if(n.first==storepath.top())
                  direction=n.second;
        }
        cout<<tem<<" ---- Now take "<<direction<<" and Move "<<distancepath.top()<<" m ,you will reach at---> ";

        distancepath.pop();

     }
     cout<<storepath.top();

}
};



class printpath{

public:

    printpath(){}
    printpath(string src, string des){
      graph<string> g;
    g.addedge("ENTRY GATE","SPORTS","left",2);
    g.addedge("ENTRY GATE","ARROW","right",4);
    g.addedge("SPORTS","JACK & JONES","left",3);
    g.addedge("JACK & JONES","ARROW","right",1);
    g.addedge("JACK & JONES","PIZZA HUT","left",3);
    g.addedge("ARROW","PIZZA HUT","right",2);
    g.addedge("PIZZA HUT","BURGER KING","left",4);
    g.addedge("PIZZA HUT","PVR","right",5);
    g.addedge("BURGER KING","BATA","left",2);
    g.addedge("PVR","SAMSUNG","right",3);
    g.addedge("BATA","LOCK & LOAD","left",1);
    g.addedge("BATA","ICONIC KID'S","right",15);
    g.addedge("NYKAA","SAMSUNG","left",2);
    g.addedge("NYKAA","HELIOS","right",3);
    g.addedge("SAMSUNG","BEAU MONDE","left",3);
    g.addedge("HELIOS","BEAU MONDE","right",3);
    g.addedge("BEAU MONDE","BIRYANI BLUES","left",2);
    g.addedge("BIRYANI BLUES","STARBUCKS","right",4);
    g.addedge("STARBUCKS","HOME CENTRE","left",2);
    g.addedge("HOME CENTRE","LIFESTYLE","right",1);
    g.addedge("ICONIC KID'S","HOME CENTRE","left",4);
    g.addedge("LOCK & LOAD","NYKAA","right",2);
    g.djki(src,des);
    }


};
