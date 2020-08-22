//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <utility>

//using namespace std;

////Divide and Conquer approach
//bool CheckIsSorted(int arr[], int startIndex, int endIndex){
//    //return true if array has no item
//    if(endIndex <= 0){
//        return true;
//    }
//    // return false if item in a larger index is greater than any index upfront
//    if(arr[endIndex] < arr[startIndex]){
//        return false;
//    }
//    //define midindex
//    int midIndex = (startIndex + endIndex) / 2;
//    //check both half of the array
//    return(
//    CheckIsSorted(arr, startIndex, midIndex) &&
//    CheckIsSorted(arr, midIndex + 1, endIndex)
//    );
//}

//bool flgIsSorted(int arr[]){
//    int size;
//    cout << "array size: ";
//    cin >> size; // get the size of the array
//    return CheckIsSorted(arr, 0, size - 1);
//}

////int main(){
////    const int size = 10;
////    int list1[size] = {1,2,3,4,5,7,6,8,9,11};
////    int list3[size] = {1,2,3,4,5,6,7,8,9,10};
////    int list2[size] = {0,1,3,5,7,9,11,12,13,16};
////    cout << flgIsSorted(list1) << endl;
////    cout << flgIsSorted(list3) << endl;
////    cout << flgIsSorted(list2) << endl;
////}
