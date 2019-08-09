// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#ifndef MY_EXCEPTIONS_H_
#define MY_EXCEPTIONS_H_

#include <exception>

/**
 * Exception class for modulus-by-zero incident
 */
class Divide_By_Zero : public std::exception {
public:
    /// Default constructor.
    Divide_By_Zero(void): std::exception() { }
};

/**
 * Exception class for modulus-by-zero incident
 */
class Modulus_By_Zero : public std::exception {
public:
    /// Default constructor.
    Modulus_By_Zero(void): std::exception() { }
};

/**
 * Exception class for modulus-by-zero incident
 */
class Unknown_Operator : public std::exception {
public:
    /// Default constructor.
    Unknown_Operator(void): std::exception() { }
};

#endif
