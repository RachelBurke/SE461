// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

//
// Stack
//
template <typename T>
Stack <T>::Stack (void):array(Array<T>(0))
{
    //Assign Array to an empty array with size 0 to create a stack
    //Comment: Moved body to initialization list
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack):array(0)
{
    try
    {
        //Since the stack data is in an array, use its copy constructor
        array = Array<T>(stack.array);
    }
    catch (std::exception ex)
    {
        ex.what();
    }
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    //Taken care of automatically
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    try
    {
        //Adding an element means the array grew by one
        array.resize(array.size()+1);
        //Add the element to the array
        array[array.size()-1] = element;
    }
    catch (std::exception ex)
    {
        ex.what();
    }
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    try
    {
        //Comment: Use is empty since I have written it
        //Something to pop?
        if(this->is_empty())
            throw array.size();

        //Pop the element
        array[array.size()-1] = 0;
        //Removing an element means the array shrunk by one
        array.resize(array.size()-1);
    }
    catch (std::exception ex)
    {
        ex.what();
    }

}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    try
    {
        //Since the stack data is in an array, copy the array
        array = rhs.array;
    }
    catch (std::exception ex)
    {
        ex.what();
    }
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    try
    {
        //Set the size back to 0 as nothing is in the stack
        //Resize deletes the data in the stack array
        array.resize(0);
    }
    catch (std::exception ex)
    {
        ex.what();
    }
}
