
namespace lasd {

/* ************************************************************************** */

// Specific constructor #1: StackLst obtained from a MappableContainer
template <typename Data>
StackLst<Data>::StackLst(const MappableContainer<Data>& container) noexcept{

    container.Map(

        [this](const Data& element){ this->Push(element); }
    );
}


// Specific constructor #2: StackLst obtained from a MutableMappableContainer
template <typename Data>
StackLst<Data>::StackLst(MutableMappableContainer<Data>&& container) noexcept{

    container.Map(

        [this](const Data& element){ this->Push(std::move(element));}
    )
}


// Copy constructor
template <typename Data>
StackLst<Data>::StackLst(const StackLst& otherStack){

    StackLst temp = otherStack;

    while(this->size != otherStack.size){

        this->Push(temp.TopNPop());
    }
}


// Move constructor
template <typename Data>
StackLst<Data>::StackLst(StackLst&& otherStack) noexcept{

    while(this->size != otherStack.size){

        this->Push(otherStack.TopNPop);

        // this->Push(std::move(otherStack.TopNPop)); // <<<< probably the correct way
    }
}


// Operator ==


/* ************************************************************************** */

}
