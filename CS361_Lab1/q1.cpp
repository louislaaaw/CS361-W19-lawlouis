#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ifstream inFile;
    inFile.open("lab1_data.txt");

    if(inFile.fail()){
        cout << "Fail to read" << endl;
        return 0;
    }

    const int size = 10000000;
    long long int* list = new long long int[size];
    long long int sum = 0;
    int i = 0;

    while(!inFile.eof()){
        long long int temp;
        inFile >> temp;
        list[i] = temp;
        if(inFile.fail()){
            break;
        }
        i++;
    }

    for(int t = 0; t < size; t++){
        sum = sum + list[t];
    }
}
