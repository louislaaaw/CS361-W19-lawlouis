#include <iostream>
#include <list>
#include <vector>
#include <set>

using namespace std;

struct vertex{
    int name;
    int distance;
    int predecessor;
};

class graph{
    vector<vertex> v;
    int** adjacencyMatrix;
public:
    graph(vector<vertex> ver, int** adj){
        this->v = ver;
        this->adjacencyMatrix = new int*[ver.size()];
        for(int i = 0; i < ver.size(); i++){
            adjacencyMatrix[i] = new int[ver.size()];
            for(int j = 0; j < ver.size(); j++){
                adjacencyMatrix[i][j] = adj[i][j];
            }
        }
    }
    void relax(vertex u, vertex v){
        if(v.distance > u.distance + adjacencyMatrix[u.name][v.name]){
            v.distance = u.distance + adjacencyMatrix[u.name][v.name];
            v.predecessor = u.name;
        }
    }
    bool BellmanFord(vertex start){
        start.distance = 0;
        for(int a = 0; a < v.size(); a++){
            for(int i = 0; i < v.size(); i++){
                for(int j = 0; j < v.size(); j++){
                    if(adjacencyMatrix[i][j] != INT_MAX){
                        relax(v[i],v[j]);
                    }
                }
            }
        }
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v.size(); j++){
                if(adjacencyMatrix[i][j] != INT_MAX){
                    if(v[i].distance > v[j].distance + adjacencyMatrix[i][j]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    void printGraph(){
        for(auto it = v.begin(); it != v.end(); ++it){
            cout << it->name << endl;
            cout << "distance: " << it->distance << endl;
            cout << "predecessor: " << it->predecessor << endl;
        }
    }
};

class DFA{
private:
    // five tuples
    vector<int> state;
    int startState ;
    vector<int> acceptState;
    vector<char> input;
    int** location;
public:
    //constructor takes 5 tuples input
    DFA(vector<int> stateSet, int s, vector<int> endStates, vector<char> i, int** transition){
        this->state = stateSet;
        this->startState = s;
        this->acceptState = endStates;
        this->input = i;
        this->location = new int* [state.size()];
        // initialize the table
        for(int j = 0; j < stateSet.size(); j++){
            location[j] = new int [i.size()];
            for(int k = 0; k < i.size(); k++){
                location[j][k] = transition[j][k];
            }
        }
    }
    bool DFAmatcher(char pattern[], int patternSize){
        int currentstate = startState;
        for(int i = 0; i < patternSize; i++){ // check the entire string by character
            int charlocation;
            for(int a = 0; a < input.size(); a++){ //check the column location of the transition table by looping the whole input set
                if(input[a] == pattern[i]){
                    charlocation = a;
                    currentstate = location[currentstate][charlocation]; //move state
                }
            }
        }
        for(int j = 0; j < acceptState.size(); j++){ //check if current state is on any of the accept state
            if(currentstate == acceptState.at(j)){
                return true;
            }
        }
        return false; //return false w/ no matches found
    }
};


int main()
{
    vector<int> state = {0,1,2,3,4};
    int start = 0;
    vector<int> accept = {1,3};
    vector<char> input = {'a','b'};
    int** trans = new int*[state.size()];
    for(int i = 0; i < state.size(); i++){
        trans[i] = new int[input.size()];
    }
    trans[0][0] = 1;
    trans[0][1] = 3;
    trans[1][0] = 1;
    trans[1][1] = 2;
    trans[2][0] = 1;
    trans[2][1] = 2;
    trans[3][0] = 4;
    trans[3][1] = 3;
    trans[4][0] = 4;
    trans[4][1] = 3;
    DFA a(state, start, accept, input, trans);
    char* pattern1 = new char[5];
    pattern1[0] = 'a';
    pattern1[1] = 'b';
    pattern1[2] = 'a';
    pattern1[3] = 'b';
    pattern1[4] = 'a';
    char* pattern2 = new char[4];
    pattern2[0] = 'b';
    pattern2[1] = 'a';
    pattern2[2] = 'b';
    pattern2[3] = 'a';
    char* pattern3 = new char[8];
    pattern3[0] = 'a';
    pattern3[1] = 'a';
    pattern3[2] = 'b';
    pattern3[3] = 'a';
    pattern3[4] = 'b';
    pattern3[5] = 'a';
    pattern3[6] = 'a';
    pattern3[7] = 'b';
    char* pattern5 = new char[11];
    pattern5[0] = 'b';
    pattern5[1] = 'a';
    pattern5[2] = 'b';
    pattern5[3] = 'a';
    pattern5[4] = 'a';
    pattern5[5] = 'b';
    pattern5[6] = 'a';
    pattern5[7] = 'a';
    pattern5[8] = 'a';
    pattern5[9] = 'b';
    pattern5[10] = 'b';
    cout << "ababa: " << a.DFAmatcher(pattern1,5) << endl;
    cout << "baba: " << a.DFAmatcher(pattern2,4) << endl;
    cout << "aababaab: " << a.DFAmatcher(pattern3,8) << endl;
    cout << "babaabaaabb: " << a.DFAmatcher(pattern5,11) << endl;
    vector<vertex> v;
    for(int i = 0; i < v.size(); i++){
        v[i].name = i;
        v[i].distance = INT_MAX;
        v[i].predecessor = -1;
    }
    int** adj = new int*[v.size()];
    for(int i = 0; i < v.size(); i++){
        adj[i] = new int[v.size()];
    }
    adj = {};
    graph g(v,adj);
    cout << "Does bellmanFord word? " << g.BellmanFord(v[0]) << endl;
    g.printGraph();
    return 0;
}
