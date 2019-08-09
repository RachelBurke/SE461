#include <iostream>
#include "Array.h"

int main () {

    Array arr1 = Array(15, 'a');
    std::cout << "Array 1 made" << std::endl;
    Array arr2;
    std::cout << "Array 2 made" << std::endl;
    Array arr3 = arr1;
    std::cout << "Array 3 made" << std::endl;
    Array arr4 = arr1;
    std::cout << "Array 4 made" << std::endl;

    std::cout << "Array 1:" << std::endl;
    for(int i = 0; i < arr1.size(); i++){
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    arr2 = arr1;

    std::cout << "Array 2:" << std::endl;
    for(int i = 0; i < arr2.size(); i++){
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    arr3.set(12,'b');

    std::cout << "Array 3:" << std::endl;
    for(int i = 0; i < arr3.size(); i++){
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    std::cout << arr1.get(14) << std::endl;

    std::cout << arr3.find('b') << std::endl;

    std::cout << arr1.find('b', 5) << std::endl;

    std::cout << "Array 1:" << std::endl;
    for(int i = 0; i < arr1.size(); i++){
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 2:" << std::endl;
    for(int i = 0; i < arr2.size(); i++){
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Array 3:" << std::endl;
    for(int i = 0; i < arr3.size(); i++){
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    if (arr1 == arr2){
        std::cout << "True A1=A2" << std::endl;
    }
    else{
        std::cout << "False A1=A2" << std::endl;
    }

    if (arr1 == arr3){
        std::cout << "True A1=A3" << std::endl;
    }
    else{
        std::cout << "False A1=A3" << std::endl;
    }

    if (arr2 == arr3){
        std::cout << "True A2=A3" << std::endl;
    }
    else{
        std::cout << "False A2=A3" << std::endl;
    }

    std::cout << std::endl;

    if (arr1 != arr2){
        std::cout << "True A1!=A2" << std::endl;
    }
    else{
        std::cout << "False A1!=A2" << std::endl;
    }

    if (arr1 != arr3){
        std::cout << "True A1!=A3" << std::endl;
    }
    else{
        std::cout << "False A1!=A3" << std::endl;
    }

    if (arr2 != arr3){
        std::cout << "True A2!=A3" << std::endl;
    }
    else{
        std::cout << "False A2!=A3" << std::endl;
    }

    std::cout << arr3.size() << " " << arr3.max_size() << std::endl;
    arr3.resize(125);
    std::cout << arr3.size() << " " << arr3.max_size() << std::endl;

    arr4.fill('b');
    std::cout << "Array 4:" << std::endl;
    for(int i = 0; i < arr4.size(); i++){
        std::cout << arr4[i] << " ";
    }
    std::cout << std::endl;

    const char x = arr1[1];

    std::cout << x << std::endl;

    std::cout << "TEST" << std::endl;

    if(arr2 != arr2){
        std::cout << " Self False" << std::endl;
    }
    else{
        std::cout << "Self True" << std::endl;
    }

    Array arr5;

    arr5.resize(150);

	return 0;
}