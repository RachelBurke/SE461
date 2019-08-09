// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#include "Base_Array.h"
#include <stdexcept>         // for std::out_of_bounds exception
#include<iostream>

//
// Base_Array
//
template <typename T>
Base_Array <T>::Base_Array (void):cur_size_(10), data_(new T[10]) 
{
    //Comment: Moved body of constructor to initialization list
}

//
// Base_Array (size_t)
//
template <typename T>
Base_Array <T>::Base_Array (size_t length):cur_size_(0), data_(0)
{
    try
    {
        //Cannot have negative length
        if(length < 0 )
            throw length;
        
        //Set current size as well as give data space
        cur_size_ = length;
        data_ = new T[cur_size_];       
    }
    catch(std::out_of_range outOfRange)
    {
        outOfRange.what();
    }
}

//
// Base_Array (size_t, T)
//
template <typename T>
Base_Array <T>::Base_Array (size_t length, T fill):cur_size_(0), data_(0)
{
    try
    {
        //Cannot have negative length
        if(length < 0 )
            throw length;

        //Set current size as well as give data space
        cur_size_ = length;
        data_ = new T[cur_size_];

        //Filling entire array with 'fill' T
        for (int i = 0; i < cur_size_; i++)
            data_[i] = fill;
    }
    catch(std::out_of_range outOfRange)
    {
        outOfRange.what();
    }
}

//
// Base_Array (const Base_Array &)
//
template <typename T>
Base_Array <T>::Base_Array (const Base_Array & array):cur_size_(0), data_(0)
{
    try
    {
        //Set current size
        cur_size_ = array.cur_size_;

        //Making sure the old array has data - otherwise nothing to copy
        if(array.data_ != 0)
        {
            // Give new data space since old has data
            data_ = new T[cur_size_];
            // Copy old array's elements into the elements of new array 
            for(int i = 0; i < cur_size_; i++)
                data_[i] = array.data_[i];
        }
        else
            throw array.data_;
    }
    catch(std::exception ex)
    {
        ex.what();
    }
}

//
// ~Base_Array
//
template <typename T>
Base_Array <T>::~Base_Array (void)
{
    try
    {
        //If data exists, delete it
        if(data_ != 0)
            delete [] data_;
        //Else nothing to delete
    }
    catch(std::exception ex)
    {
        ex.what();
    }
}

//
// operator =
//
template <typename T>
const Base_Array <T> & Base_Array <T>::operator = (const Base_Array & rhs)
{
    try
    {
        //Is the rhs the same as the lhs? If so, don't redo it
        if(this != &rhs){
            //Resize and get ready for the copy
            if(cur_size_ != rhs.cur_size_){
                delete [] data_;
                cur_size_ = rhs.cur_size_;
                data_ = new T[cur_size_];
            }
            //Copy the rhs to the lhs
            for(int i = 0; i < cur_size_; i++)
                data_[i] = rhs.data_[i];
        }
    }
    catch (std::exception ex)
    {
        ex.what();
    }
}

//
// operator []
//
template <typename T>
T & Base_Array <T>::operator [] (size_t index)
{
    try
    {
        //Return the data at this index
        return this -> data_[index]; 
    }
    catch (std::exception ex)
    {
        ex.what();
    }
}

//
// operator [] 
//
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
    try
    {
        //Return the data at this index 
        return this-> data_[index]; 
    }
    catch (std::exception ex)
    {
        ex.what();
    }
}

//
// get
//
template <typename T>
T Base_Array <T>::get (size_t index) const
{
    try
    {
        //Is the index in the range?
        if (index < 0 || index > cur_size_)
            throw index;

        //Yes, return data
        else
            return data_[index];                             
    }
    //No, throw out of range error
    catch(std::out_of_range outOfRange)
    {
        outOfRange.what();
    }
}

//
// set
//
template <typename T>
void Base_Array <T>::set (size_t index, T value)
{
    try
    {
        //Is the index out of range?
        if (index < 0 || index > cur_size_)
            throw index;
        //No? Then set the data
        else
            data_[index] = value;
    }
    //Yes? Then throw an error
    catch(std::out_of_range outOfRange)
    {
        outOfRange.what();
    }
}

//
// find (T)
//
template  <typename T>
int Base_Array <T>::find (T value) const
{
    //Same as find with start position defined.
    //Just send in 0 as start to search whole array
    return find(value, 0);
}

//
// find (T, size_t) 
//
template <typename T>
int Base_Array <T>::find (T val, size_t start) const
{
    try
    {
        //Is starting position in the bounds?
        if (start < 0 || start > cur_size_)
            throw start;

        //Yes? then do your search
        else
        {
            //Search for T until
            for(int i = start; i < cur_size_; i++)
                //if you find it tell, tell where you found it
                if(val == data_[i])
                    return i;
            //if you do not find it, return -1
            return -1;   
        }
    }
    //No? then throw the error
    catch(std::out_of_range outOfRange)
    {
        outOfRange.what();
    }
}

//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const
{
    try
    {
        //Am I making a comparison against myself? Yes? Then they are the same
        if(&data_ == &rhs.data_)
            return true;

        //Are the two array sizes equal? No? Then they aren't the same
        if (cur_size_ != rhs.cur_size_)
            return false;

        //Otherwise check each position to see if there is a match and if there is not a match they are different
        for(int i = 0; i < cur_size_; i++)
            if (data_[i] != rhs.data_[i])
                return false;
        
        //If false was not returned, everything matched!
        return true;  
    }
    catch (std::exception ex)
    {
        ex.what();
    }
}

//
// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array & rhs) const
{
    try
    {
        return !(*this == rhs);
    }
    catch (std::exception ex)
    {
        ex.what();
    } 
}

//
// fill
//
template <typename T>
void Base_Array <T>::fill (T value)
{
    try
    {
        //Set each entry individually
        for(int i = 0; i < cur_size_; i++)
            data_[i] = value;
    }
    catch (std::exception ex)
    {
        ex.what();
    }
}
