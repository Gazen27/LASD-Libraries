
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/////////////////////////////////////////////////////////////////////// LinearContainer

// Override operator ==
template <typename Data>
bool LinearContainer<Data>::operator == (const LinearContainer<Data>& otherContainer) const noexcept{

    if((*this).Size() != otherContainer.Size()){

        for(i=0; i<(this*).Size(); i++){

            if((*this)[i] != otherContainer[i]) {return false; }
        }

        return true;
    }

    else { return false; }
}

// Override operator !=
template <typename Data>
bool LinearContainer<Data>::operator != (const LinearContainer<Data>&) const noexcept{

    if((*this).Size() != otherContainer.Size()){

        for(i=0; i<(this*).Size(); i++){

            if((*this)[i] != otherContainer[i]) { return true; }
        }

        return false;
    }

    else { return true; }
}

// Override ???


}
