// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#include "Array.h"
#include "Fixed_Array.h"
#include "Stack.h"
#include "Queue.h"

#include <iostream>
#include <stdexcept>
#include <cstdlib>

//
// main
//
int main (int argc, char * argv [])
{


/// Testing the Base_Array

    std::cout << "ARRAYARRAYARRAYARRAY" << std::endl;

    Base_Array<int> arr1 = Base_Array<int>(15, 5);
    std::cout << "Base_Array 1 made" << std::endl;
    Base_Array<int> arr2 = Base_Array<int>();
    std::cout << "Base_Array 2 made" << std::endl;
    Base_Array<int> arr3 = arr1;
    std::cout << "Base_Array 3 made" << std::endl;
    Base_Array<int> arr4 = arr1;
    std::cout << "Base_Array 4 made" << std::endl;

    std::cout << "Base_Array 1:" << std::endl;
    for(int i = 0; i < arr1.size(); i++){
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    arr2 = arr1;

    std::cout << "Base_Array 2:" << std::endl;
    for(int i = 0; i < arr2.size(); i++){
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    arr3.set(12,6);

    std::cout << "Base_Array 3:" << std::endl;
    for(int i = 0; i < arr3.size(); i++){
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    std::cout << arr3.get(0) << std::endl;

    std::cout << arr3.find(6) << std::endl;

    std::cout << arr1.find(6, 5) << std::endl;

    std::cout << "Base_Array 1:" << std::endl;
    for(int i = 0; i < arr1.size(); i++){
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Base_Array 2:" << std::endl;
    for(int i = 0; i < arr2.size(); i++){
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Base_Array 3:" << std::endl;
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

    std::cout << arr3.size() << std::endl;

    arr4.fill(10);
    std::cout << "Base_Array 4:" << std::endl;
    for(int i = 0; i < arr4.size(); i++){
        std::cout << arr4[i] << " ";
    }
    std::cout << std::endl;

    const int x = arr1[1];

    std::cout << x << std::endl;

    std::cout << "TEST" << std::endl;

    if(arr2 != arr2){
        std::cout << " Self False" << std::endl;
    }
    else{
        std::cout << "Self True" << std::endl;
    }

///Testing the Stack

    std::cout << "STACKSTACKSTACKSTACK" << std::endl;

    Stack<int> stack1 = Stack<int>();
    
    stack1.push(5);
    
    std::cout << stack1.top() << std::endl;

    stack1.push(10);
    stack1.push(500);

    Stack<int> stack2 = stack1;
    stack2.pop();

    std::cout << stack2.top() << std::endl;

    std::cout << stack1.size() << " " << stack1.is_empty() << std::endl;
    stack1.clear();
    std::cout << stack1.size() << " " << stack1.is_empty() << std::endl;


///Testing the Queue

    std::cout << "QUEUEQUEUEQUEUEQUEUE" << std::endl;

    Queue<int> queue1 = Queue<int>();
    
    queue1.enqueue(5);
    queue1.enqueue(10);
    queue1.enqueue(500);

    std::cout << queue1.size() << std::endl;

    Queue<int> queue2 = queue1;
    std::cout << queue2.dequeue() << std::endl;

    std::cout << queue2.size() << std::endl;

    std::cout << queue1.size() << " " << queue1.is_empty() << std::endl;
    queue1.clear();
    std::cout << queue1.size() << " " << queue1.is_empty() << std::endl;

///Testin the Resize Array

    std::cout << "RESIZEEEEEEEEEEEEEEEEEEEEEEEEEEEE" << std::endl;

    Array<int> r_arr1 = Array<int>(15, 5);
    std::cout << "Array 1 made" << std::endl;
    Array<int> r_arr2;
    std::cout << "Array 2 made" << std::endl;
    Array<int> r_arr3 = r_arr1;
    std::cout << "Array 3 made" << std::endl;
    Array<int> r_arr4 = r_arr1;
    std::cout << "Array 4 made" << std::endl;

    std::cout << "Array 1:" << std::endl;
    for(int i = 0; i < r_arr1.size(); i++){
        std::cout << r_arr1[i] << " ";
    }
    std::cout << std::endl;

    r_arr2 = r_arr1;

    std::cout << "Array 2:" << std::endl;
    for(int i = 0; i < r_arr2.size(); i++){
        std::cout << r_arr2[i] << " ";
    }
    std::cout << std::endl;

    r_arr3.set(12,6);

    std::cout << "Array 3:" << std::endl;
    for(int i = 0; i < r_arr3.size(); i++){
        std::cout << r_arr3[i] << " ";
    }
    std::cout << std::endl;

    std::cout << r_arr3.get(0) << std::endl;

    std::cout << r_arr3.find(6) << std::endl;

    std::cout << r_arr1.find(6, 5) << std::endl;

    std::cout << "Array 1:" << std::endl;
    for(int i = 0; i < r_arr1.size(); i++){
        std::cout << r_arr1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 2:" << std::endl;
    for(int i = 0; i < r_arr2.size(); i++){
        std::cout << r_arr2[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Array 3:" << std::endl;
    for(int i = 0; i < r_arr3.size(); i++){
        std::cout << r_arr3[i] << " ";
    }
    std::cout << std::endl;

    if (r_arr1 == r_arr2){
        std::cout << "True A1=A2" << std::endl;
    }
    else{
        std::cout << "False A1=A2" << std::endl;
    }

    if (r_arr1 == r_arr3){
        std::cout << "True A1=A3" << std::endl;
    }
    else{
        std::cout << "False A1=A3" << std::endl;
    }

    if (r_arr2 == r_arr3){
        std::cout << "True A2=A3" << std::endl;
    }
    else{
        std::cout << "False A2=A3" << std::endl;
    }

    std::cout << std::endl;

    if (r_arr1 != r_arr2){
        std::cout << "True A1!=A2" << std::endl;
    }
    else{
        std::cout << "False A1!=A2" << std::endl;
    }

    if (r_arr1 != r_arr3){
        std::cout << "True A1!=A3" << std::endl;
    }
    else{
        std::cout << "False A1!=A3" << std::endl;
    }

    if (r_arr2 != r_arr3){
        std::cout << "True A2!=A3" << std::endl;
    }
    else{
        std::cout << "False A2!=A3" << std::endl;
    }

    std::cout << r_arr3.size() << " " << r_arr3.max_size() << std::endl;

    r_arr4.fill(10);
    std::cout << "Array 4:" << std::endl;
    for(int i = 0; i < r_arr4.size(); i++){
        std::cout << r_arr4[i] << " ";
    }
    std::cout << std::endl;

    const int y = r_arr1[1];

    std::cout << y << std::endl;

    std::cout << "TEST" << std::endl;

    if(r_arr2 != r_arr2){
        std::cout << " Self False" << std::endl;
    }
    else{
        std::cout << "Self True" << std::endl;
    }

    r_arr1.resize(500);

    std::cout << r_arr1.size() << " " << r_arr1.max_size() << std::endl;

    ///Testin the Fixed Array

    std::cout << "FFFFFFFFIIIIIIIIIIXXXXXXEEEEEEEDDDD" << std::endl;

    Fixed_Array<int, 15> f_arr1 = Fixed_Array<int, 50>(15);
    std::cout << "Fixed_Array 1 made" << std::endl;
    Fixed_Array<int, 10> f_arr2 = Fixed_Array<int, 10>(10);
    std::cout << "Fixed_Array 2 made" << std::endl;
    Fixed_Array<int, 15> f_arr3 = f_arr2;
    std::cout << "Fixed_Array 3 made" << std::endl;
    Fixed_Array<int, 15> f_arr4 = f_arr1;
    std::cout << "Fixed_Array 4 made" << std::endl;

    std::cout << "Fixed_Array 1:" << std::endl;
    for(int i = 0; i < f_arr1.size(); i++){
        std::cout << f_arr1[i] << " ";
    }
    std::cout << std::endl;

    std::cout<< f_arr2.size() << std::endl;

    f_arr2 = f_arr1;

    std::cout<< f_arr2.size() << std::endl;

    std::cout << "Fixed_Array 2:" << std::endl;
    for(int i = 0; i < f_arr2.size(); i++){
        std::cout << f_arr2[i] << " ";
    }
    std::cout << std::endl;

    f_arr3.set(12,6);

    std::cout << "Fixed_Array 3:" << std::endl;
    for(int i = 0; i < f_arr3.size(); i++){
        std::cout << f_arr3[i] << " ";
    }
    std::cout << std::endl;

    std::cout << f_arr3.get(0) << std::endl;

    std::cout << f_arr3.find(6) << std::endl;

    std::cout << f_arr1.find(6, 5) << std::endl;

    std::cout << "Fixed_Array 1:" << std::endl;
    for(int i = 0; i < f_arr1.size(); i++){
        std::cout << f_arr1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Fixed_Array 2:" << std::endl;
    for(int i = 0; i < f_arr2.size(); i++){
        std::cout << f_arr2[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Fixed_Array 3:" << std::endl;
    for(int i = 0; i < f_arr3.size(); i++){
        std::cout << f_arr3[i] << " ";
    }
    std::cout << std::endl;

    if (f_arr1 == f_arr2){
        std::cout << "True A1=A2" << std::endl;
    }
    else{
        std::cout << "False A1=A2" << std::endl;
    }

    if (f_arr1 == f_arr3){
        std::cout << "True A1=A3" << std::endl;
    }
    else{
        std::cout << "False A1=A3" << std::endl;
    }

    if (f_arr2 == f_arr3){
        std::cout << "True A2=A3" << std::endl;
    }
    else{
        std::cout << "False A2=A3" << std::endl;
    }

    std::cout << std::endl;

    if (f_arr1 != f_arr2){
        std::cout << "True A1!=A2" << std::endl;
    }
    else{
        std::cout << "False A1!=A2" << std::endl;
    }

    if (f_arr1 != f_arr3){
        std::cout << "True A1!=A3" << std::endl;
    }
    else{
        std::cout << "False A1!=A3" << std::endl;
    }

    if (f_arr2 != f_arr3){
        std::cout << "True A2!=A3" << std::endl;
    }
    else{
        std::cout << "False A2!=A3" << std::endl;
    }

    std::cout << f_arr3.size() << std::endl;

    std::cout << "Fixed_Array 4:" << std::endl;
    for(int i = 0; i < f_arr4.size(); i++){
        std::cout << f_arr4[i] << " ";
    }
    f_arr4.fill(10);
    std::cout << "Fixed_Array 4:" << std::endl;
    for(int i = 0; i < f_arr4.size(); i++){
        std::cout << f_arr4[i] << " ";
    }
    std::cout << std::endl;

    const int z = f_arr1[1];

    std::cout << z << std::endl;

    std::cout << "TEST" << std::endl;

    if(f_arr2 != f_arr2){
        std::cout << " Self False" << std::endl;
    }
    else{
        std::cout << "Self True" << std::endl;
    }

    return 0; 
}
