#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

class vertex{
public:
    char name;
    bool* adj;
    list<vertex> adjlist;
    int distance;
    string color; // WHITE, GRAY, BLACK
    char parent;
};

class graph{
private:
    unsigned int numVertex;
    vector<vertex> v; // list of vertex
public:
    graph(unsigned int vertexSize, vector<vertex> vertexSet){
        this->numVertex = vertexSize;
        this->v = vertexSet;
    }
    void BFS_Matrix(vertex startvertex){
        startvertex.color = "GRAY";
        startvertex.parent = -1;
        startvertex.distance = 0;
        deque<vertex> queue;
        queue.push_back(startvertex);
        while(!queue.empty()){
            vertex temp = queue.front();
            queue.pop_front();
            for(unsigned int i = 0; i < numVertex; i++){
                if(temp.adj[i] == 1 && temp.color == "WHITE"){
                    vertex temp2;
                    temp2.color = "GRAY";
                    temp2.distance = temp.distance + 1;
                    temp2.parent = temp.name;
                    v.at(i) = temp2;
                    queue.push_back(temp2);
                }
            }
            temp.color = "BLACK";
        }
    }
    void BFS_LIST(vertex startvertex){
        startvertex.color = "GRAY";
        startvertex.parent = -1;
        startvertex.distance = 0;
        deque<vertex> queue;
        queue.push_back(startvertex);
        while(!queue.empty()){
            vertex temp = queue.front();
            queue.pop_front();
            for(auto it = temp.adjlist.begin(); it != temp.adjlist.end(); ++it){
                if(temp.color == "WHITE"){
                    vertex temp2;
                    temp2.color = "GRAY";
                    temp2.distance = temp.distance + 1;
                    temp2.parent = temp.name;
                    queue.push_back(temp2);
                }
            }
            temp.color = "BLACK";
        }
    }


};


int MatrixChain(int p[] , int i, int j){
    if(i == j){
        return 0;
    }
    int iteration = INT_MAX;
    int q,k;
    for(k = i; k < j; k++){
        q = MatrixChain(p, i, k) + MatrixChain(p, k + 1, j) +
                ((p[i-1] * p[k] * p[j]));
        if(q < iteration){
            iteration = q;
        }
    }
    return iteration;
}

int lookupChain(int iteration, int p[], int i, int j){
    int q;
    if(i == j){
        iteration = 0;
    }
    else{
        for(int k = i; k <= j - 1; k++){
            q = lookupChain(iteration, p, i, k) + lookupChain(iteration, p, k + 1, j) +
                    ((p[i - 1] * p[k] * p[j]));
            if(q < iteration){
                iteration = q;
            }
        }
    }
    return iteration;
}

int memoizedMatrix(int p[], int size){
    int n = size - 1;
    int iteration = INT_MAX;
    return lookupChain(iteration, p, 1, n);
}

//void printOptimal(int iteration, int p[], int i, int j){
//    if(i == j){
//        cout << "A" << i;
//    }
//    else{
//        cout << "(";
//        printOptimal(iteration, p, i, MatrixChain(p, i, j));
//        printOptimal(iteration, p, MatrixChain(p, i, j) + 1, j );
//        cout << ")";
//    }
//

int main()
{
    const int size = 7;
    int dim[size] = {30,4,8,5,10,25,15};
    int iteration = MatrixChain(dim, 1, 6);
    cout << "It took " << iteration << " iterations" << endl;
//    printOptimal(iteration, dim, 1, 6);
    int iteration2 = memoizedMatrix(dim, size);
    cout << "It took " << iteration2 << " iterations" << endl;
    return 0;
}

