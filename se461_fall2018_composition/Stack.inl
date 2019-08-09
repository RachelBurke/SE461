// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    //Size of the stack is the size of the array
    return array.size();
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
    //Top item is the last item in the array
    return array.get(array.size()-1);
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    //If the size is 0 true
    if(array.size() == 0)
        return true;
    //Otherwise false
    return false;
}
