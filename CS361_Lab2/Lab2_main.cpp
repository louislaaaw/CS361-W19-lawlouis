#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <deque>
#include <vector>

int partition(int arr[], int start, int end){
    int mid = (start + end) / 2; // our pivot index is the middle item
    int pivot = arr[mid]; // pivot value for comparison
    arr[mid] = arr[end]; // swap the middle item and the pivot
    arr[end] = pivot; // swap the middle item and the pivot
    int i = start; // the swap index for the comparison
    for(int j = start; j < end; j++){
        if(arr[j] <= pivot){
            // compare with the pivot value and swap if smaller
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    //swap the pivot back to the last sorted index and return
    int temp1 = arr[end];
    arr[end] = arr[i];
    arr[i] = temp1;
    return i;
}

void AuxQuickSort(int array[], int startIndex, int endIndex){
    if(startIndex < endIndex){
        int pivot = partition(array, startIndex, endIndex);
        AuxQuickSort(array, startIndex, pivot - 1);
        AuxQuickSort(array, pivot + 1, endIndex);
    }
}

using namespace std;

bool CheckIsSorted(int arr[], int startIndex, int endIndex){
    if(startIndex <= 0){
        return true;
    }
    if(arr[endIndex] < arr[startIndex]){
        return false;
    }
    int midIndex = (startIndex + endIndex) / 2;
    return(
    CheckIsSorted(arr, startIndex, midIndex) &&
    CheckIsSorted(arr, midIndex + 1, endIndex)
    );
}

bool flgIsSorted(int arr[]){
    int size;
    cout << "array size: ";
    cin >> size;
    return CheckIsSorted(arr, 0, size - 1);
}

void CountingSort(int arr[], int size, int placeValue){
    int* B = new int[size]; // Array B stores the output
    int* C = new int[10]; //Array C stores the counter
    //initialize the Array C to 0
    for(int i = 0; i < 10; i++){
        C[i] = 0;
    }
    //store the # of each value in Array C
    for(int j = 0; j < size; j++){
        C[(arr[j] / placeValue) % 10] += 1;
    }
    // add up the value in Array C which will give us the index that we should put into our Array B
    for(int k = 1; k < 10; k++){
        C[k] += C[k - 1];
    }
    // put the numbers into array B base on the Index in array C
    for(int l = size - 1; l >= 0; l--){
        B[C[(arr[l] / placeValue) % 10] - 1] = arr[l];
        C[(arr[l] / placeValue) % 10] -= 1;
    }
    // Copy the whole output array back into the original
    for(int m = 0; m < size; m++){
        arr[m] = B[m];
    }
}

void RadixSort(int arr[], int size, int LargestDigit){
    int placevalue = 1; // initial place value from the right to the left
    // counting sort each place value
    for(int i = 1; i <= LargestDigit; i++){
        CountingSort(arr, size, placevalue);
        placevalue *= 10;
    }
}

void InsertionSort(vector<int>& list){
    int i;
    int k;
    int temp;
    for(i = 1; i < list.size(); i++){
        k = list.at(i);
        temp = i - 1;
        while(temp >= 0 && list.at(temp) > k){
            list.at(temp + 1) = list.at(temp);
            temp--;
        }
        list.at(temp + 1) = k;
    }
}

void BucketSort(int arr[], int size){
    int bucketSize = 100000; // causing memory problems with too many buckets
    vector<int> bucket[bucketSize]; //initialize buckets
    // puting all the items into its designated buckets
    for(int i = 0; i < size; i++){
        int bucketIndex = arr[i] / bucketSize;
        if(bucketIndex >= bucketSize){
            bucketIndex = bucketSize - 1;
        }
        bucket[bucketIndex].push_back(arr[i]);
    }
    // insertion sort each buckets
    for(int i = 0; i < bucketSize ; i++){
        InsertionSort(bucket[i]);
    }
    int k = 0; // array index
    // concatenate each bucket back into an original array
    for(int i = 0; i < bucketSize; i++){
        for(auto it = bucket[i].begin(); it != bucket[i].end(); ++it){
            arr[k] = *it;
            k++;
        }
    }

}

vector<int> FindTenLargest(int arr[], int startIndex, int endIndex){
    vector<int> largest = {0};
    if(endIndex == 0 && largest.size() == 10){
        return largest;
    }
    else{
        largest = FindTenLargest(arr, startIndex, endIndex - 1);
        if(arr[endIndex] > arr[endIndex - 1]){
            largest.push_back(arr[endIndex]);
        }
    }
}

void PrintTenLargest(int arr[], int startIndex ,int endIndex){
    vector<int> largest = FindTenLargest(arr, startIndex, endIndex);
    InsertionSort(largest);
    for(auto i = largest.rend(); i != largest.rbegin(); --i){
        cout << *i << endl;
    }
}

//Reading our files into an array
void ReadFileIntoArray(int arr[], ifstream& File, string FileName){
    File.open(FileName);

    if(File.fail()){
        cout << "Fail to read" << endl;
        return;
    }
    int i = 0;

    while(!File.eof()){
        int temp;
        File >> temp;
        arr[i] = temp;
        if(File.fail()){
            break;
        }
        i++;
    }
}



int main()
{
    
    ifstream InFile;
    const int size = 10000000;
    int* list = new int[size];
    ReadFileIntoArray(list, InFile, "lab2_data.txt");
    clock_t start = clock();
//    RadixSort(list, 10000000, 7);
    BucketSort(list, 1000000);
    clock_t end = clock();
    clock_t time = end - start;
    cout << "It takes: " << time * 1.000000000 / CLOCKS_PER_SEC << "s" << endl;
    for(int i = 0; i < 1000; i++){
        cout << list[i] << endl;
    }
    return 0;
}
