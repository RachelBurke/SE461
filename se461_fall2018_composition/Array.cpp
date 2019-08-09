// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void):Base_Array<T>::Base_Array(), max_size_(100)
{
    //Comment: Moved body of constructor to initialization list
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length):Base_Array<T>::Base_Array(length), max_size_(100) { }

//
// Array (size_t, T)
//
template <typename T>
Array <T>::Array (size_t length, T fill):Base_Array<T>::Base_Array(length, fill), max_size_(100 ){ }

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array):Base_Array<T>::Base_Array(array), max_size_(array.max_size_) { }

//
// ~Array
//
template <typename T>
Array <T>::~Array (void) { }

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    try
    {
        //Is the rhs the same as the lhs? If so, don't redo it
        if(this != &rhs){
            //Resize and get ready for the copy
            if(this->cur_size_ != rhs.cur_size_){
                delete [] this->data_;
                this->cur_size_ = rhs.cur_size_;
                this->max_size_ = rhs.max_size_;
                this->data_ = new T[this->cur_size_];
            }
            //Copy the rhs to the lhs
            for(int i = 0; i < this->cur_size_; i++)
                this->data_[i] = rhs.data_[i];
        }
    }
    catch (std::exception ex)
    {
        ex.what();
    }
}

//
// resize
//
template <typename T>
void Array <T> ::resize (size_t new_size)
{
    try
    {  
        //Is the new size too small?
        if (new_size < 0)
            throw new_size;

        //Create a temp to store data during resize
        T * temp_data = new T[new_size];

        //Figure out if new size is smaller than just the max size or current too to find stopping point
        size_t stop;
        if (new_size < this->cur_size_)
            stop = new_size;
        else
            stop = this->cur_size_;

        for (int i = 0; i < stop; i++)         //Copy all the old data you need
            temp_data[i] = this->data_[i];

        //Delete, resize, and create data
        if (this->data_ != 0)
            delete [] this->data_;
        this->cur_size_ = new_size;
        this->data_ = new T[this->cur_size_];

        //Make sure that current size is no more than max and change it if it needs to be
        if(this->cur_size_> this->max_size_)
            this->max_size_ = this->cur_size_;

        //Copy everything back
        for (int i = 0; i < this->cur_size_; i++)
            this->data_[i] = temp_data[i];

        delete[] temp_data;
    }
    //Yes? Then throw the error
    catch(std::out_of_range outOfRange)
    {
        outOfRange.what();
    }
}