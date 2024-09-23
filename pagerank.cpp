
#include <iostream>
#include <map>
#include<iomanip>
#include <vector>
using namespace std;
class AdjList{
private:
    //the integer will be used to store the out-degree rather than the reciprocal
    //this makes it easier to keep track of out-degree for when it may be needed
    //in-degree can be kept track of by taking the size of the value

    map<string,vector<string>> AdjacencyList;

    //out degree for rank calculations
    map<string, double> AdjDegrees;

    //for storing Page Rank for final calculations
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
    double CalculatePageRank(int powerIterations){
        for(int i =0; i < powerIterations; i++){

        }
    }
public:
    AdjList()=default;
    void insertEdge(string &from, string &to){
        //assume no parallel edges
        if(AdjacencyList.find(to) == AdjacencyList.end() || AdjDegrees.find(to) == AdjDegrees.end()){
            //initialize and define values to be zero
            AdjacencyList[to].push_back(from);
            AdjDegrees[to] = 0.0;
        }
        else{
            AdjacencyList[to].push_back(from);
        }
        //found first instance of website
        if(AdjacencyList.find(from) == AdjacencyList.end() || AdjDegrees.find(from) == AdjDegrees.end()){
            AdjDegrees[from] = 1.0;
        }
        else{
            AdjDegrees[from] += 1.0;
        }
    }
    //only called with all inputs are recevied
    void createFirstRanks(){
        for(auto i: AdjacencyList){
            PageRank[i.first] = 1.0f/(double)getNumVertices();
        }
    }
    void CalculatePageRanks(int power_iterations){
        createFirstRanks();
        if(power_iterations == 1){return;}
        int num_vert = getNumVertices();
        double matrix[num_vert][num_vert] ;
        map<string,double> temp;
//        fill the matrix with the right values
        for(int i =0; i < getNumVertices(); i++){
            for(int j = 0; i < getNumVertices(); j++){
                for(auto h : AdjDegrees){
                    if(h.second == 0.0){
                    }
                    else{
                        matrix[i][j] = 1/h.second;
                    }
                }
            }
        }
        //this operation will run as many times as there are power iterations
        for(int k =1; k<power_iterations; k++){
            for(auto n: PageRank){
                double sum = 0;
                double product;
                for(int l = 0; l<getNumVertices(); l++){
                    for(int m = 0; m < getNumVertices(); m++){
                        for(auto o: PageRank){
                            product = matrix[l][m] * o.second;
                            sum += product;
                        }
                    }
                }
                temp[n.first] = sum;
            }
        }
    }
};
//Essential functions included