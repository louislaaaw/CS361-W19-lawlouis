#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

class AdjacencyMatrix{
public:
    AdjacencyMatrix();
    AdjacencyMatrix(int row, int col, int martrix);
    bool matrix[ROW_SIZE][COL_SIZE];
};

#endif // ADJACENCYMATRIX_H
