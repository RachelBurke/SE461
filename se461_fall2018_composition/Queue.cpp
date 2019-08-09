// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

//
// Queue
//
template <typename T>
Queue <T>::Queue (void):array(Array<T>(0))
{
    //Assign Array to an empty array with size 0 to create a queue
    //Comment: Moved body to the initilization list
}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue & queue):array(0)
{
    try
    {
        //Since the queue data is in an array, use its copy constructor
        array = Array<T>(queue.array);
    }
    catch (std::exception ex)
    {
        ex.what();
    }
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{
    //Taken care of automatically
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
    try
    {
        //Adding an element means the array grew by one
        array.resize(array.size()+1);
        //Add the element to the array (set the element)
        array.set(array.size()-1, element);
    }
    catch (std::exception ex)
    {
        ex.what();
    }
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
    try
    {
        //Comment: Use is empty since I have written it
        //Something to dequeue?
        if(this->is_empty())
            throw array.size();

        //Get the element from array
        T item = array.get(0);
        //Move up and Remove the element
        for(int i = 0; i < array.size()-1; i++)
            array.set(i, array.get(i+1));

        //Erase the nth position
        array.set(array.size()-1, 0);
        //Removing an element means the array shrunk by one
        array.resize(array.size()-1);

        //Comment:: Return the dequeued item
        return item;
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
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    try
    {
        //Since the queue data is in an array, copy the array
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
void Queue <T>::clear (void)
{
    try
    {
        //Set the size back to 0 as nothing is in the queue
        //Resize takes care of deleting the elements in the queue array
        array.resize(0);
    }
    catch (std::exception ex)
    {
        ex.what();
    }
}
