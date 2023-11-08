#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
class Adj_List{
private:
    //unordered maps used
    unordered_map<string, int> ODeg;
    unordered_map<string, vector<string>> IDeg;
    map<string, double> PageRank;

    int get_in_deg(){
        return IDeg.size();
    };
    int get_out_deg(){
        return ODeg.size();
    };
public:
    Adj_List(){}

};


int main() {

}
