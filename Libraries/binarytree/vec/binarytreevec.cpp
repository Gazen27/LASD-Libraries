
namespace lasd {

/* ************************************************************************** */

//////////////////////////////////////////////////////////////////////////// BinaryTreeVec::NodeVec

// Specific constructor 1
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& data){ key = data; }


// Specific constructor 2
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& data){ key = std::move(data); }


// Copy assignment
template <typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator = (const BinaryTreeVec<Data>::NodeVec& otherNode) noexcept{

    index = otherNode.index;
    left = otherNode.left;
    right = otherNode.right;
    key = otherNode.key;
    treePointer = otherNode.treePointer;

    return *(this);
}


// Override function Element (Mutable)
template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept{ return this->key; }


// Override function Element (Non-Mutable)
template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept{ return this->key; }


// Override function IsLeaf
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept{

    if(!HasLeftChild() && !HasRightChild()){ return true; }
    return false;
}


// Overide function HasLeftChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{

    ulong tempSize = treePointer->Size();

    if(this->left < tempSize){ return true; }
    return false;
}


// Override function HasRightChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{

    ulong tempSize = treePointer->Size();

    if(this->right < tempSize){ return true; }
    return false;
}


// Override function LeftChild (Non-Mutable)
template <typename Data>
const BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const{

    if(!this->HasLeftChild()){ throw std::out_of_range("Error: Left child does not exist!"); }
    return treePointer-> nodeArray[left];
}


// Override function LeftChild (Mutable)
template <typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild(){

    if(!this->HasLeftChild()){ throw std::out_of_range("Error: Left child does not exist!"); }
    return treePointer-> nodeArray[left];
}


// Override function RightChild (Non-Mutable)
template <typename Data>
const BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const{

    if(!this->HasRightChild()){ throw std::out_of_range("Error: Left child does not exist!"); }
    return treePointer->nodeArray[right];
}


// Override function RightChild (Non-Mutable)
template <typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild(){

    if(!this->HasRightChild()){ throw std::out_of_range("Error: Left child does not exist!"); }
    return treePointer->nodeArray[right];
}

//////////////////////////////////////////////////////////////////////////// BinaryTreeVec

// Specific constructor #1: BinaryTreeVec obtained from a MappableContainer
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const MappableContainer<Data>& container) noexcept{

    ulong point = 0;
    this->size = container.Size();
    nodeArray = new NodeVec[size];

    container.Map(

        [this, &point](const Data& data){

            nodeArray[point] = NodeVec(data);
            nodeArray[point].left = (point + 1) * 2 - 1;
            nodeArray[point].right = (point + 1) * 2;
            nodeArray[point].index = point;
            nodeArray[point].treePointer = this;
            point ++;
        }
    );
}


// Specific constructor #2: BinaryTreeVec obtained from a MutableMappableContainer
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MutableMappableContainer<Data>&& container) noexcept{

    ulong point = 0;
    this->size = container.Size();
    nodeArray = new NodeVec[size];

    container.Map(

        [this, &point](const Data& data){

            nodeArray[point] = NodeVec(std::move(data));
            nodeArray[point].left = (point + 1) * 2 - 1;
            nodeArray[point].right = (point + 1) * 2;
            nodeArray[point].index = point;
            nodeArray[point].treePointer = this;
            point ++;
        }
    );
}


// Copy constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& otherTree){

    this->size = otherTree.size;
    nodeArray = new NodeVec[size];

    for(ulong i = 0; i < size; i++){
        
        Data temp = otherTree.nodeArray[i].Element();

        nodeArray[i] = NodeVec(temp);
        nodeArray[i].index = otherTree.nodeArray[i].index;
        nodeArray[i].left = otherTree.nodeArray[i].left;
        nodeArray[i].right = otherTree.nodeArray[i].right;
        nodeArray[i].treePointer = this;
    }
}


// Move constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& otherTree) noexcept{

    std::swap(this->size, otherTree.size);
    std::swap(this->nodeArray, otherTree.nodeArray);
    for(ulong i = 0; i < size; i++){ nodeArray[i].treePointer = this; }
}


// Destructor
template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec(){ Clear(); }


// Copy assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator = (const BinaryTreeVec<Data>& otherTree){

    Clear();

    this->size = otherTree.size;
    nodeArray = new NodeVec[size];

    for(ulong i = 0; i < size; i++){
        
        Data temp = otherTree.nodeArray[i].Element();

        nodeArray[i] = NodeVec(temp);
        nodeArray[i].index = otherTree.nodeArray[i].index;
        nodeArray[i].left = otherTree.nodeArray[i].left;
        nodeArray[i].right = otherTree.nodeArray[i].right;
        nodeArray[i].treePointer = this;
    }

    return *(this);
}


// Move assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator = (BinaryTreeVec<Data>&& otherTree) noexcept{
    
    std::swap(this->size, otherTree.size);
    std::swap(this->nodeArray, otherTree.nodeArray);
    for(ulong i = 0; i < size; i++){ nodeArray[i].treePointer = this; }

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
    return nodeArray[0];
}


// Override function Root (Mutable)
template <typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root(){

    if(size == 0){ throw std::length_error("Error: Tree is Empty!"); }
    return nodeArray[0];
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
        
        Data temp = nodeArray[i].Element();
        f(temp, acc);
    }
}


// Override function BreadthMap (from BreadthMappableContainer)
template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFunctor mapFunctor) const{

    for(ulong i = 0; i < size; i++){ mapFunctor(nodeArray[i].Element()); }
}


// Override function BreadthMap (from MutableBreadthMappableContainer)
template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MutableMapFunctor mapFunctor){

    for(ulong i = 0; i < size; i++){ mapFunctor(nodeArray[i].Element()); }
}


/* ************************************************************************** */

}
