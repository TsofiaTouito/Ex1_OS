#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono> 

using namespace std;

//Generate a random number in the range [-25, 74]
int randGen(int min , int max ){
    return min + (rand() % (max - min + 1));
}



void genRandArray(int arr[], int size){

    for(int i = 0 ; i < size ; i++){
        arr[i] = randGen(-25, 75);
    }
}





// Time complexity of the algorithm is : O(n)
int MaxSubArray(int arr[], int size){

        
    int max_sum = 0, sum = 0;
    for(int i = 0 ; i < size ; i++){
        sum = max(arr[i] + sum, arr[i]);
        max_sum = max(sum, max_sum);
        }

    return max_sum;
}


//Function to print the array
void printArray(int arr[], int size){

    cout << "[";
    
    for(int i = 0 ; i < size ; i++){
        cout << arr[i] ;
        
        if(i < size-1){
            cout<< ",";
        }
    }

    cout << "]" << endl;;
}





int main(int args, char* argv[]){

    if(args !=  3){
        cerr << "Usage :" << argv[0] << " seed | input size \n" ;
        return 1;
    }

    int seed = atoi(argv[1]);
    int size = atoi(argv[2]);


    if(size <= 0 ){
        cerr << "The input size must be positive " ;
        return 1;
    }


    // Initialize the random number generator with the seed
    srand(seed);  


    int arr[size];
    genRandArray(arr, size);


    cout <<"The values of the calculated array :" << endl;
    printArray(arr, size);


    int max_sum = MaxSubArray(arr, size);
    cout << "Max sub-array sum is : " << max_sum << endl;



return 0;
}
