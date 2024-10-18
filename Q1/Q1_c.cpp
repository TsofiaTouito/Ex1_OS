#include <stdio.h>
#include <iostream>


int main(){
/*
int arr[3] = {3 , 6, 9 };

int value = arr[7];

printf("Value at out of bound index : %d\n ", value);

*/

int* ptr = nullptr;

*ptr = 4;   //causes a segmentation fault


return 0;
}