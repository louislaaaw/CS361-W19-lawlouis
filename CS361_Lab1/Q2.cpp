////#include <iostream>
////#include <fstream>
////#include <iomanip>

////using namespace std;

//void combine(int arr[], int start, int mid, int end){
//    int firsthalf = mid - start + 1; // size of first half of the array
//    int secondhalf = end - mid; // size of second half of the array
//    int* left = new int[firsthalf]; // temp array for the firsthalf
//    int* right = new int[secondhalf]; // temp array for the secondhalf
//    for(int i = 0; i < firsthalf; i++){
//        left[i] = arr[start + i]; // divide the array and copy items to the firsthalf temp array
//    }
//    for(int r = 0; r < secondhalf; r++){
//        right[r] = arr[mid + 1 + r]; // divide the array and copy items to the secondhalf temp array
//    }
//    int a = 0; // index for the firsthalf starting with 0
//    int b = 0; // index for the secondhalf starting with 0
//    int s = start;

//    // combine two arrays by comparing items on both side
//    while(a < firsthalf && b < secondhalf){
//        if(left[a] <= right[b]){
//            arr[s] = left[a];
//            a++;
//        }else{
//            arr[s] = right[b];
//            b++;
//        }
//        s++;
//    }

//    // take care of the remaining items
//    while(a < firsthalf){
//        arr[s] = left[a];
//        a++;
//        s++;
//    }
//    while(b < secondhalf){
//        arr[s] = right[b];
//        b++;
//        s++;
//    }
//}


//void AuxMergeSort(int arr[], int startIndex, int endIndex){
//    if(startIndex < endIndex){
//        int midIndex = (startIndex + endIndex) / 2;

//        // keep dividing the array to half until single then combine all the subarrays back
//        AuxMergeSort(arr, startIndex, midIndex);
//        AuxMergeSort(arr, midIndex + 1, endIndex);
//        combine(arr, startIndex, midIndex, endIndex);
//    }
//}


