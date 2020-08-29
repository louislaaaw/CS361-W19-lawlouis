//#include <iostream>
//#include <fstream>
//#include <string>
//#include <ctime>

//using namespace std;

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

//bool CheckIsSorted(int arr[], int startIndex, int endIndex){
//    if(startIndex <= 0){
//        return true;
//    }
//    if(arr[endIndex] < arr[startIndex]){
//        return false;
//    }
//    int midIndex = (startIndex + endIndex) / 2;
//    return(
//    CheckIsSorted(arr, startIndex, midIndex) &&
//    CheckIsSorted(arr, midIndex + 1, endIndex)
//    );
//}

//bool flgIsSorted(int arr[]){
//    int size;
//    cout << "array size: ";
//    cin >> size;
//    return CheckIsSorted(arr, 0, size - 1);
//}

//int main()
//{

//    ifstream inFile;
//    inFile.open("lab1_data.txt");

//    if(inFile.fail()){
//        cout << "Fail to read" << endl;
//        return 0;
//    }

//    const int size = 10000000;
//    int* list = new int[size];
//    int i = 0;

//    while(!inFile.eof()){
//        int temp;
//        inFile >> temp;
//        list[i] = temp;
//        if(inFile.fail()){
//            break;
//        }
//        i++;
//    }
//    clock_t startTime1 = clock();
//    AuxMergeSort(list, 0, 999);
//    cout << "MergeSorted first 1000 items:" << endl;
//    for(int j = 0; j < 1000; j++){
//        cout << list[j] << endl;
//    }
//    AuxMergeSort(list, 0, 9999);
//    AuxMergeSort(list, 0, 99999);
//    AuxMergeSort(list, 0, 999999);

//    AuxQuickSort(list, 0, 999);
//    cout << "QuickSorted first 100 items:" << endl;
//    for(int j = 0; j < 1000; j++){
//        cout << list[j] << endl;
//    }
//    AuxQuickSort(list, 0, 9999);
//    AuxQuickSort(list, 0, 99999);
//    AuxQuickSort(list, 0, 999999);
//    AuxQuickSort(list, 0, size - 1);
//    bool check = flgIsSorted(list);
//    cout << check << endl;

////    clock_t endTime1 = clock();
////    clock_t elapsed = endTime1 - startTime1;

//////    cout << "It takes: " << 1.000000000 * elapsed / CLOCKS_PER_SEC << "s " << endl;



//    return 0;
//}
