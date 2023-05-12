
namespace lasd {

/* ************************************************************************** */

//////////////////////////////////////////////////////////////////////////// BinaryTreeVec::NodeVec

// Specific constructor 1
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& data){ key = data; }


// Specific constructor 2
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& data){ key = std::move(data); }


// Override function Element (Mutable)
template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element(){ return this->key; }


// Override function Elemetn (Non-Mutable)
template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const { return this->key; }


// Override function IsLeaf
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept{

    if(!HasLeftChild() && !HasRightChild()){ return true; }
    return false;
}


// Overide function HasLeftChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{

    if(this->left > size - 1){ return true; }
    return false;
}


// Override function HasRightChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{

    if(this->right > size - 1){ return true; }
    return false;
}


// Override function LeftChild
template <typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const{

    if(!this->HasLeftChild()){ throw std::out_of_range("Error: Left child does not exist!"); }
    return *(treePointer-> nodeArray)[left];
}


// Override function RightChild
template <typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const{

    if(!this->HasRightChild()){ throw std::out_of_range("Error: Left child does not exist!"); }
    return *(treePointer-> nodeArray)[right];
}


//////////////////////////////////////////////////////////////////////////// BinaryTreeVec

// Specific constructor #1: BinaryTreeVec obtained from a MappableContainer
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const MappableContainer<Data>& container) noexcept{

    index = 0;
    this->size = container.size;
    for(ulong i = 0; i < size; i++){ nodeArray[i] = nullptr; }

    container.Map(

        [this](const Data& data){

            nodeArray[index] = new Node(data);
            nodeArray[index]->left = (index + 1) * 2 - 1;
            nodeArray[index]->right = (index + 1) * 2;
            nodeArray[index]->treePointer = this;

            index ++;
        }
    );
}


// Specific constructor #2: BinaryTreeVec obtained from a MutableMappableContainer
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MutableMappableContainer<Data>&& container) noexcept{

    index = 0;
    this->size = container.size;
    for(ulong i = 0; i < size; i++){ nodeArray[i] = nullptr; }

    container.Map(

        [this](const Data& data){

            nodeArray[index] = new Node(std::move(data));
            nodeArray[index]->left = (index + 1) * 2 - 1;
            nodeArray[index]->right = (index + 1) * 2;
            nodeArray[index]->treePointer = this;

            index ++;
        }
    );
}


// Copy constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& otherTree){

    this->size = otherTree.size;
    for(ulong i = 0; i < size; i++){ nodeArray[i] = nullptr; }

    for(ulong i = 0; i < size; i++){
        
        Data temp = otherTree.nodeArray[i]->Element();

        nodeArray[i] = new Node(temp);
        nodeArray[i]->index = otherTree.nodeArray[i]->index;
        nodeArray[i]->left = otherTree.nodeArray[i]->left;
        nodeArray[i]->right = otherTree.nodeArray[i]->right;
        nodeArray[i]->treePointer = this;
    }
}


// Move constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& otherTree) noexcept{

    std::swap(this->size, otherTree.size);
    for(ulong i = 0; i < size; i++){ nodeArray[i] = nullptr; }

    std::swap(this->nodeArray, otherTree.nodeArray);
    for(ulong i = 0; i < size; i++){ nodeArray[i]->treePointer = this; }
}


// Destructor
template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec(){ Clear(); }


// Copy assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator = (const BinaryTreeVec<Data>& otherTree){

    Clear();
    this->size = otherTree.size;
    for(ulong i = 0; i < size; i++){ nodeArray[i] = nullptr; }

    for(ulong i = 0; i < size; i++){
        
        Data temp = otherTree.nodeArray[i]->Element();

        nodeArray[i] = new Node(temp);
        nodeArray[i]->index = otherTree.nodeArray[i]->index;
        nodeArray[i]->left = otherTree.nodeArray[i]->left;
        nodeArray[i]->right = otherTree.nodeArray[i]->right;
        nodeArray[i]->treePointer = this;
    }

    return *(this);
} 


// Move assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator = (BinaryTreeVec<Data>&& otherTree) noexcept{

    std::swap(this->size, otherTree.size);
    std::swap(this->nodeArray, otherTree.nodeArray);
    for(ulong i = 0; i < size; i++){ nodeArray[i]->treePointer = this; }

    return *(this);
}


// Operator ==
template <typename Data>
bool BinaryTreeVec<Data>::operator == (const BinaryTreeVec<Data>& otherTree) const noexcept{

    if(this->size == 0 && otherTree.size == 0){ return true; }
    if(this->size != otherTree.size){ return false; }

    for(ulong i = 0; i < size; i++){

        if(this->nodeArray[i] != otherTree.nodeArray[i]){ return false; }
    }

    return true;
}
 

// Operator !=
template <typename Data>
bool BinaryTreeVec<Data>::operator != (const BinaryTreeVec<Data>& otherTree) const noexcept{

    return !(*(this) == otherTree);
}


// Override function Root (Non-Mutable)
template <typename Data>
const BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const{

    if(size == 0){ throw std::length_error("Error: Tree is Empty!"); }
    return *nodeArray[0];
}


// Override function Root (Mutable)
template <typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root(){

    if(size == 0){ throw std::length_error("Error: Tree is Empty!"); }
    return *nodeArray[0];
}


// Override function Clear
template <typename Data>
void BinaryTreeVec<Data>::Clear() noexcept{

    delete[] nodeArray;
    nodeArray = nullptr;

    size = 0;
}


// Override function BreadthFold
template <typename Data>
void BinaryTreeVec<Data>::BreadthFold(FoldFunctor f, void* acc) const{

    for(ulong i = 0; i < size; i++){
        
        temp = nodeArray[i]->Element();
        f(temp, acc);
    }
}


// Override function BreadthMap (from BreadthMappableContainer)
template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFunctor mapFunctor) const{

    for(ulong i = 0; i < size; i++){ mapFunctor(nodeArray[i]->Element()); }
}


// Override function BreadthMap (from MutableBreadthMappableContainer)
template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MutableMapFunctor mapFunctor){

    for(ulong i = 0; i < size; i++){ mapFunctor(nodeArray[i]->Element()); }
}


/* ************************************************************************** */

}
