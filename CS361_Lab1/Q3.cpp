//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <utility>

//using namespace std;

//int partition(int arr[], int start, int end){
//    int mid = (start + end) / 2; // our pivot index is the middle item
//    int pivot = arr[mid]; // pivot value for comparison
//    arr[mid] = arr[end]; // swap the middle item and the pivot
//    arr[end] = pivot; // swap the middle item and the pivot
//    int i = start; // the swap index for the comparison
//    for(int j = start; j < end; j++){
//        if(arr[j] <= pivot){
//            // compare with the pivot value and swap if smaller
//            int temp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = temp;
//            i++;
//        }
//    }

//    //swap the pivot back to the last sorted index and return
//    int temp1 = arr[end];
//    arr[end] = arr[i];
//    arr[i] = temp1;
//    return i;
//}

//void AuxQuickSort(int array[], int startIndex, int endIndex){
//    if(startIndex < endIndex){
//        int pivot = partition(array, startIndex, endIndex);
//        AuxQuickSort(array, startIndex, pivot - 1);
//        AuxQuickSort(array, pivot + 1, endIndex);
//    }
//}
