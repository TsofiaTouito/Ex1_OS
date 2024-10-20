#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

//Generate a random number in the range [-25, 74]
int randGen(int min , int max ){
    return min + (rand() % (max - min + 1));
}


//Max Sub-array in complexity of O(n^3)
int MaxSubArray(int arr[], int size){

    int max_sum = 0;
    for(int i = 0 ; i < size ; i++){
        for(int j = i ; j < size ; j++){
            int sum = 0;

            //sum the current sub-array
            for(int k = i ; k < j ; k++){
                sum += arr[k];
            }
            max_sum = max(sum, max_sum);
        }
    }

    return max_sum;
}


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

    int min = -25;
    int max = 75;

    int arr[size];
    for(int i = 0 ; i < size ; i++){
        arr[i] = randGen(min, max);
    }
    
    cout <<"The values of the calculated array :" << endl;
    printArray(arr, size);

    int max_sum = MaxSubArray(arr, size);
    cout << "Max sub-array sum is : " << max_sum << endl;

return 0;

}
