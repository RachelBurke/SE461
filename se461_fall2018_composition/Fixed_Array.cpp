// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#include "Fixed_Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void):Base_Array<T>::Base_Array(N)
{
    //Initialize an array with size N
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr):Base_Array<T>::Base_Array(arr)
{
    //Initialize an array with size N and copy over arr data
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr):Base_Array<T>::Base_Array(N)
{
	try
    {
        *this = arr;
    }
    catch(std::exception ex)
    {
        ex.what();
    }
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill):Base_Array<T>::Base_Array(N, fill)
{
    //Initialize an array with size N and fill it with fill
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
    //Taken care of with the base class Base_Array
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	try
    {
        //Is the rhs the same as the lhs? If so, don't redo it
        if(this != &rhs)
        {
            for(int i = 0; i < N; i++)
                this->set(i, rhs[i]);
            return *this;
        }
        //If we get here then the rhs and lhs were the same
        else
            throw rhs;
    }
    catch (std::exception ex)
    {
        ex.what();
    }
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
    try
    {
        if(M > N)
        {
            //Copy RHS
            for(int i = 0; i < N; i++)
                this->set(i, rhs[i]);
            return *this;
        }
        else
        {
            //Copy RHS
            for(int i = 0; i < M; i++)
                this->set(i, rhs[i]);
            //If needed set the rest to null because M < N
            for(int i = M; i < N; i++)
                this->set(i, 0);
            return *this;
        }
    }
    catch (std::exception ex)
    {
        ex.what();
    }
}
