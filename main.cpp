#include <iostream>
#include <map>
#include<iomanip>
#include <unordered_map>
#include <vector>
using namespace std;
class AdjList{
private:
    //the integer will be used ot store the out degree rather than the reciprocol
    //this makes it easier to keep track of Out Degree for when it may be needed
    //indegree can be kept track of by taking the size of the value

    map<string,vector<string>> AdjacencyList;
    //in and out degree respectively for rank calculations
    unordered_map<string, pair<int,int>> AdjDegrees;
    //for storing Page Rank for later interations
    map<string, double> PageRank;
    int getNumVertices(){
        return AdjacencyList.size();
    };
    bool isEdge(string &from, string &to) {
        for (auto i: AdjacencyList[to]) {
            if (i.compare(from) == 0) {
                return true;
            }
        }
        return false;
    }
public:
    AdjList(){}
    void insertEdge(string &from, string &to){
        //assume no parallel edges
        if(AdjacencyList.find(to) == AdjacencyList.end()){
            //initialize and define values to be zero
            AdjacencyList[to].emplace_back(from);
            AdjDegrees[to].first = 1;
            AdjDegrees[to].second = 0;
        }
        else{
            AdjacencyList[to].emplace_back(from);
            AdjDegrees[to].first ++;
        }
        //found first instance of website
        if(AdjacencyList.find(from) == AdjacencyList.end()){
            AdjacencyList[from];
            AdjDegrees[from].first = 0;
            AdjDegrees[from].second = 1;
        }
        else{
            AdjDegrees[from].second ++;
        }
    }
};
int main() {
    AdjList my_ADJ;
    string dal = "dalia";
    string z = "zeek";
    string l = "lorenz";
    string corey = "flores";
    string rob = "Roberto:)";
    string mari = "Mariangel";
    my_ADJ.insertEdge(dal, z);
    my_ADJ.insertEdge(corey,l);
    my_ADJ.insertEdge(z,corey);
    my_ADJ.insertEdge(mari,dal);
    my_ADJ.insertEdge(dal,corey);
    my_ADJ.insertEdge(z,mari);
    my_ADJ.insertEdge(z,rob);
    return 0;
}
