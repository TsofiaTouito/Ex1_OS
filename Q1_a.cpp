#include <stdio.h>

int infinit_recursion(int num){
    return infinit_recursion(num)+1; //recursive call without termination condition
}


int main(){

int num = infinit_recursion(7);  //calling the function causing infinite recursion

return 0;
}