// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#include "Array.h"
#include <iostream>
#include <stdexcept>

// Comment: Fixed mixing of initialization and assignment - Used initialization list
Array::Array (void):cur_size_(0), max_size_(0), data_(NULL) 
{
    //Default current and max sizes with give data space
    cur_size_ = 10;
    max_size_ = 100;
    data_ = new char[cur_size_];
}

// Comment: Fixed mixing of initialization and assignment - Used initialization list
Array::Array (size_t length): cur_size_(0), max_size_(0), data_(NULL)
{
    try
    {
        //Cannot have negative length
        if(length < 0 )
            throw length;
        
        //Set current and max sizes as well as give data space
        cur_size_ = length;
        max_size_ = 100;
        data_ = new char[cur_size_];       
    }
    catch(std::out_of_range outOfRange)
    {
        outOfRange.what();
    }
    catch (...)
    {
        std::cout << "LENGTH SMALLER THAN 0" << std::endl;
    }
}

// Comment: Fixed mixing of initialization and assignment - Used initialization list
Array::Array (size_t length, char fill): cur_size_(0), max_size_(0), data_(NULL)
{
    try
    {
        //Cannot have negative length
        if(length < 0 )
            throw length;

        //Set current and max sizes as well as give data space
        cur_size_ = length;
        max_size_ = 100;
        data_ = new char[cur_size_];

        //Filling entire array with 'fill' character
        for (int i = 0; i < cur_size_; i++)
            data_[i] = fill;
    }
    catch(std::out_of_range outOfRange)
    {
        outOfRange.what();
    }
    catch (...)
    {
        std::cout << "LENGTH SMALLER THAN 0" << std::endl;
    }
}

// Comment: Fixed mixing of initialization and assignment - Used initialization list
Array::Array (const Array & array): cur_size_(0), max_size_(0), data_(NULL)
{
    try
    {
        //Set current and max sizes
        cur_size_ = array.cur_size_;
        max_size_ = array.max_size_;

        //Making sure the old array has data - otherwise nothing to copy
        if(array.data_ != NULL){
            //Fixed possible segmentation fault
            // Give new data space since old has data
            data_ = new char[cur_size_];
            // Copy old array's elements into the elements of new array 
            for(int i = 0; i < cur_size_; i++)
                data_[i] = array.data_[i];
        }
        else{
            throw array.data_;
        }
    }
    catch(std::out_of_range outOfRange)
    {
        outOfRange.what();
    }
    catch (...)
    {
        std::cout << "COPY CONSTRUCTOR - ARRAY CONTAINS NO DATA" << std::endl;
    }
}

// Comment: Ensuring data is not null 
Array::~Array (void)
{
    try
    {
        //If data exists, delete it
        if(data_ != 0)
            delete [] data_;

        //Else nothing to delete
        
    }
    catch (...)
    {
        std::cout << "DATA NOT DELETED" << std::endl;
    }
    
}

const Array & Array::operator = (const Array & rhs)
{
    try
    {
        //Is the rhs the same as the lhs? If so, don't redo it
        if(this != &rhs){
            //Resize and get ready for the copy
            if(cur_size_ != rhs.cur_size_){
                delete [] data_;
                cur_size_ = rhs.cur_size_;
                max_size_ = rhs.max_size_;
                data_ = new char[cur_size_];
            }
            //Copy the rhs to the lhs
            for(int i = 0; i < cur_size_; i++)
                data_[i] = rhs.data_[i];
        }
    }
    catch (...)
    {
        std::cout << "UNABLE TO SET LHS = RHS" << std::endl;
    }
}

char & Array::operator [] (size_t index)
{
    try
    {
        //Return the data at this index
        return this -> data_[index]; 
    }
    catch (...)
    {
        std::cout << "UNABLE TO GET MODIFIABLE CHARACTER" << std::endl;
    }
}

const char & Array::operator [] (size_t index) const
{
    try
    {
        //Return the data at this index 
        return this -> data_[index]; 
    }
    catch (...)
    {
        std::cout << "UNABLE TO GET UNMODIFIABLE CHARACTER" << std::endl;
    }
}

char Array::get (size_t index) const
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
    catch (...)
    {
        std::cout << "GET INDEX OUT OF RANGE EXCEPTION" << std::endl;
    }
}

void Array::set (size_t index, char value)
{
    try
    {
        //Is the index out of range?
        if (index < 0 || index > cur_size_){
            throw index;
        }
        //No? Then set the data
        else{
            data_[index] = value;
        }
    }
    //Yes? Then throw an error
    catch(std::out_of_range outOfRange)
    {
        outOfRange.what();
    }
    catch (...)
    {
        std::cout << "SET INDEX OUT OF RANGE EXCEPTION" << std::endl;
    }
}

void Array::resize (size_t new_size)
{
    try
    {  
        //Is the new size too small?
        if (new_size < 0)
            throw new_size;

        //Is the new size smaller than the max size, but larger than current size?
        if (new_size < max_size_) {
            cur_size_ = new_size;
            return;
        }

        //Create a temp to store data during resize
        char * temp_data = new char[new_size];

        //Figure out if new size is smaller than just the max size or current too to find stopping point
        size_t stop;
        if (new_size < cur_size_)
            stop = new_size;
        else
            stop = cur_size_;

        for (int i = 0; i < stop; i++)         //Copy all the old data you need
            temp_data[i] = data_[i];

        //Delete, resize, and create data
        delete [] data_;
        cur_size_ = new_size;
        data_ = new char[cur_size_];

        //Make sure that current size is no more than max and change it if it needs to be
        if(cur_size_ > max_size_)
            max_size_=cur_size_;

        //Copy everything back
        for (int i = 0; i < cur_size_; i++)
            data_[i] = temp_data[i];

        delete[] temp_data;
    }
    //Yes? Then throw the error
    catch(std::out_of_range outOfRange)
    {
        outOfRange.what();
    }
    catch (...)
    {
        std::cout << "RESIZE MAX SIZE OF ARRAY IS TOO SMALL" << std::endl;
    }
}
int Array::find (char ch) const
{
    //Same as find with start position defined.
    //Just send in 0 as start to search whole array
    find(ch, 0);
}

int Array::find (char ch, size_t start) const
{
    try
    {
        //Is starting position in the bounds?
        if (start < 0 || start > cur_size_)
            throw start;

        //Yes? then do your search
        else{
            //Search for the character until
            for(int i = start; i < cur_size_; i++)
                //if you find it tell, tell where you found it
                if(ch == data_[i])
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
    catch (...)
    {
        std::cout << "FIND START POSITION EXCEEDED BOUNDS OF ARRAY." << std::endl;
    }
}

// Comment: Checking to see a comparision is being made against myself
bool Array::operator == (const Array & rhs) const
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
    catch (...)
    {
        std::cout << "UNABLE TO EVALUATE BOOLEAN EQUALITY" << std::endl;
    }
}

// Comment: Removing redundant code by making use of the == operator
bool Array::operator != (const Array & rhs) const
{
    try
    {
        return !(*this == rhs);
    }
        catch (...)
    {
        std::cout << "UNABLE TO EVALUATE BOOLEAN EQUALITY" << std::endl;
    }    
}

void Array::fill (char ch)
{
    try
    {
        //Set each character individually
        for(int i = 0; i < cur_size_; i++)
            data_[i] = ch;
    }
    catch (...) 
    {
        std::cout << "UNABLE TO FILL" << std::endl;
    }
}