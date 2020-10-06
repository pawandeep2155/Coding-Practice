#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    int min_apples = 13;
    int current_apples = 0;
    int index = 1;
    while(current_apples < min_apples){
        current_apples += 12*index;
        index++;
    }
    int perimeter = 8*(index-1);
    cout<<"Perimiter "<<perimeter<<endl;
    return 0;
}