
/* ************************************************************************** */

namespace lasd {

////////////////////////////////////////////////////////////////////// Node

// Operator ==
template <typename Data>
bool BinaryTree<Data>::Node::operator == (const Node& otherNode) const noexcept{
    
    if(this->key != otherNode.key){ return false; }

    // Has no child
    if(!this->HasLeftChild() && !this->HasRightChild()){
        if(otherNode.HasLeftChild() || otherNode.HasRightChild()){ return false; }
        return true;
    }

    // Has Left Child only
    if(this->HasLeftChild() && !this->HasRightChild()){
        if(!otherNode.HasLeftChild() || otherNode.HasRightChild()){ return false; }
        if(this->LeftChild() != otherNode.LeftChild()){ return false; }
        return true;
    }

    // Has Right Child only
    if(!this->HasLeftChild() && this->HasRightChild()){
        if(otherNode.HasLeftChild() || !otherNode.HasRightChild()){ return false; }
        if(this->RightChild() != otherNode.RightChild()){ return false; }
        return true;
    }

    // Has both Left and Right Child
    if(this->HasLeftChild() && this->HasRightChild()){
        if(!otherNode.HasLeftChild() || !otherNode.HasRightChild()){ return false; }
        if(this->LeftChild() != otherNode.LeftChild()){ return false; }
        if(this->RightChild() != otherNode.RightChild()){ return false; }
        return true;
    }
}


// Operator !=
template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& otherNode) const noexcept{
    
    return !(*this == otherNode);
}


// Function IsLeaf
template <typename Data>
bool BinaryTree<Data>::Node::IsLeaf() const noexcept{

    if(!this->HasLeftChild() && !this->HasRightChild()){ return true; }
    return false;
}


////////////////////////////////////////////////////////////////////// BinaryTree

// Operator ==
template <typename Data>
bool BinaryTree<Data>::operator == (const BinaryTree<Data>& otherTree) const noexcept{

    if(this->size == 0 && otherTree.size == 0){ return true; }
    if(this->Root() == otherTree.Root()){ return true; }
    return false;
}

// Operator !=
template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& otherTree) const noexcept{
    
    return !(*this == otherTree);
}

// Function Fold
template <typename Data>
void BinaryTree<Data>::Fold(FoldFunctor f , void * acc) const{

    this->PreOrderMap([acc, f](const Data& value){ f(value,acc); });
}


// Function Map
template <typename Data>
void BinaryTree<Data>::Map(MapFunctor foldfunc ) const{ this->PreOrderMap(foldfunc); }


// Function PreOrderMap (Normal)
template <typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor mapfunc) const{
    
    if(size != 0){ PreOrderMap(mapfunc, Root()); }
}


// Function PostOrderMap (Normal)
template <typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor mapfunc) const{
    
    if(size != 0){ PostOrderMap(mapfunc, Root()); }
}


// Function InOrderMap (Normal)
template <typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor mapfunc) const{

    if(size != 0){ InOrderMap(mapfunc , Root()); }
}


// Function BreadthMap
template <typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor mapfunc) const{

   if(size != 0){ BreadthMap(mapfunc, Root()); }
}


// AUXILIARY - Function PreOrderMap
template <typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor mapfunc ,const Node& temp) const{
    
    mapfunc(temp.Element());
    if(temp.HasLeftChild()){ PreOrderMap(mapfunc , temp.LeftChild()); }
    if(temp.HasRightChild()){ PreOrderMap(mapfunc , temp.RightChild()); }
}


// AUXILIARY - Function PostOrderMap
template <typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor mapfunc , const Node& temp) const{
    
    if(temp.HasLeftChild()){ PostOrderMap(mapfunc , temp.LeftChild()); }
    if(temp.HasRightChild()){ PostOrderMap(mapfunc , temp.RightChild()); }
    mapfunc(temp.Element());
}


// AUXILIARY - Function InOrderMap
template <typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor mapfunc ,const Node& temp) const{

    if(temp.HasLeftChild()){ InOrderMap(mapfunc , temp.LeftChild()); }
    mapfunc(temp.Element());
    if(temp.HasRightChild()){ InOrderMap(mapfunc , temp.RightChild()); }
}


// AUXILIARY - Function BreadthMap
template <typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor mapfunc ,const Node& temp) const{

    using Node = typename BinaryTree<Data>::Node;

    QueueLst<Node const*> que;
    que.Enqueue(&temp);

    while(!que.Empty())
    {
        const Node* current = que.HeadNDequeue();
        mapfunc(current->Element());

        if(temp.HasLeftChild()){ que.Enqueue(&(current->LeftChild())); }
        if(temp.HasRightChild()){ que.Enqueue(&(current->RightChild())); }
    }
}


////////////////////////////////////////////////////////////////////// MutableBinaryTree

// Function Map
template <typename Data>
void MutableBinaryTree<Data>::Map(MutableMapFunctor mapfunc ){ PreOrderMap(mapfunc); }

// Function PreOrderMap
template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MutableMapFunctor mapfunc){ PreOrderMap(mapfunc , Root()); }

// Function PostOrderMap
template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MutableMapFunctor mapfunc){ PostOrderMap(mapfunc , Root()); }

// Function InOrderMap
template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MutableMapFunctor mapfunc){ InOrderMap(mapfunc , Root()); }

// Function BreadthMap
template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MutableMapFunctor mapfunc){ BreadthMap(mapfunc, Root()); }


// AUXILIARY - Function PreOrderMap
template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MutableMapFunctor mapfunc, MutableNode& temp) 
{
    if(&temp!=nullptr){

        mapfunc(temp.Element());
        if(temp.HasLeftChild()){ PreOrderMap(mapfunc , temp.LeftChild()); }
        if(temp.HasRightChild()){ PreOrderMap(mapfunc , temp.RightChild()); }
    } 
}


//AUXILIARY - Function PostOrderMap
template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MutableMapFunctor mapfunc, MutableNode& temp){
    
    if(&temp!=nullptr){

        if(temp.HasLeftChild()){ PostOrderMap(mapfunc , temp.LeftChild()); }
        if(temp.HasRightChild()){ PostOrderMap(mapfunc , temp.RightChild()); }
        mapfunc(temp.Element());
    }
}


//AUXILIARY - Function InOrderMap
template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MutableMapFunctor mapfunc, MutableNode& temp) 
{
    if(&temp != nullptr){

        if(temp.HasLeftChild()){ InOrderMap(mapfunc , temp.LeftChild()); }
        mapfunc(temp.Element());
        if(temp.HasRightChild()){ InOrderMap(mapfunc , temp.RightChild()); }
    }
}


//AUXILIARY - Function BreadthMap
template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MutableMapFunctor mapfunc, MutableNode& temp){

    if(&temp == nullptr){ return; }
    
    QueueLst<MutableNode*> que;
    que.Enqueue(&temp);

    while(!que.Empty()){

        MutableNode* current = que.HeadNDequeue();
        mapfunc(current->Element());
        if(temp.HasLeftChild()){ que.Enqueue(&(current->LeftChild())); }
        if(temp.HasRightChild()){ que.Enqueue(&(current->RightChild())); }
    }
}


////////////////////////////////////////////////////////////////////// BTPreOrderIterator

// Specific constructor: Iterator over a given binary tree
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& tree){
    
    current = &(tree.Root());
    root = current;
}


// Copy constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator& otherIterator){
    
    root = otherIterator.root;
    current = otherIterator.current;
    elements = otherIterator.elements;
}


// Move constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator&& otherIterator){

    std::swap(root, otherIterator.root);
    std::swap(current, otherIterator.current);
    std::swap(elements, otherIterator.elements);
}


// Destructor
template<typename Data>
BTPreOrderIterator<Data>::~BTPreOrderIterator(){
    
    elements.Clear();
    current = nullptr ;
    root = nullptr ;
}


// Copy assignment
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator = (const BTPreOrderIterator& otherIterator){
    
    root = otherIterator.root ;
    current = otherIterator.current ;
    elements = otherIterator.elements;

    return *this;
}


// Move assignment
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=( BTPreOrderIterator&& otherIterator){
    
    std::swap(root, otherIterator.root);
    std::swap(current , otherIterator.current);
    std::swap(elements, otherIterator.elements);

    return *this;
}


// Operator == 
template<typename Data>
bool BTPreOrderIterator<Data>::operator == (const BTPreOrderIterator& otherIterator) const noexcept{
    
    if(root != otherIterator.root){ return false; }
    if(current != otherIterator.current){ return false; }
    if(elements != otherIterator.elements){ return false; }
    
    return true;
}

// Operator !=
template<typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator& otherIterator) const noexcept{
    
    return !(*this == otherIterator);
}


// Operator *
template<typename Data>
const Data& BTPreOrderIterator<Data>::operator * () const{

    if(Terminated()){ throw std::out_of_range("Error: Iterator is terminated!"); }
    return current->Element();
}


// Function Terminated
template<typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept{

    return (current == nullptr);
}


// Operator ++
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++(){

    if(Terminated()){ throw std::out_of_range("Iterator was terminated ! "); }

    if(current->HasRightChild()){ elements.Push(&(current->RightChild())); }

    if(current->HasLeftChild()){ elements.Push(&(current->LeftChild())); }
    
    if(elements.Empty()){ current=nullptr; }
    else{ current=elements.TopNPop(); }

    return *this;
}


// Function Reset
template<typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept{

    elements.Clear();
    current = root;
}


////////////////////////////////////////////////////////////////////// BTPreOrderMutableIterator

// Specific constructor: Iterator over a given mutable binary tree
template<typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(MutableBinaryTree<Data>& tree) : BTPreOrderIterator<Data>(tree){}

// Copy constructor
template<typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const BTPreOrderMutableIterator<Data>& iterator) : BTPreOrderIterator<Data>(iterator){}

// Move constructor
template<typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(BTPreOrderMutableIterator<Data>&& iterator) : BTPreOrderIterator<Data>(std::move(iterator)){}

// Destructor
template<typename Data>
BTPreOrderMutableIterator<Data>::~BTPreOrderMutableIterator(){
    elements.Clear();
    current = nullptr ;
    root = nullptr ;
}


// Copy assignment
template<typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator<Data>& iterator){
    
    root = iterator.root;
    current = iterator.current;
    elements = iterator.elements;

    return *this;
}


// Move assignment
template<typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=( BTPreOrderMutableIterator<Data>&& iterator){

    std::swap(root,iterator.root);
    std::swap(current,iterator.current);
    std::swap(elements,iterator.elements);

    return *this;
}


// Operator ==
template<typename Data>
bool BTPreOrderMutableIterator<Data>::operator==(const BTPreOrderMutableIterator<Data>& otherIterator) const noexcept{

    return (BTPreOrderIterator<Data>::operator == (otherIterator));
}


// Operator !=
template<typename Data>
bool BTPreOrderMutableIterator<Data>::operator!=(const BTPreOrderMutableIterator<Data>& otherIterator) const noexcept{

    return !(*this == otherIterator);
}


// Operator *
template<typename Data>
Data& BTPreOrderMutableIterator<Data>::operator*(){

    return const_cast<Data&>(BTPreOrderIterator<Data>::operator*());
}


////////////////////////////////////////////////////////////////////// BTPostOrderIterator

// Specific constructor: Iterator over a given binary tree
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& tree){
    
    MostLeftLeaf(&(tree.Root()));
    current = elements.TopNPop();
    root = &(tree.Root()) ;
}


// Copy constructor
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& iterator){
    
    root = iterator.root;
    current = iterator.current;
    elements = iterator.elements;
}


// Move constructor
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& iterator){

    std::swap(root, iterator.root);
    std::swap(current, iterator.current);
    std::swap(elements, iterator.elements);
}


// Destructor
template<typename Data>
BTPostOrderIterator<Data>::~BTPostOrderIterator(){

    elements.Clear();
    current = nullptr;
    root = nullptr ;
}


// Copy assignment
template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& otherIterator){
    
    root = otherIterator.root;
    current = otherIterator.current;
    elements = otherIterator.elements;

    return *this;
}


// Move assignment
template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=( BTPostOrderIterator&& otherIterator)
{

    std::swap(root, otherIterator.root);
    std::swap(current, otherIterator.current);
    std::swap(elements, otherIterator.elements);

    return *this;
}


// Operator *
template<typename Data>
const Data& BTPostOrderIterator<Data>::operator*() const{
    
    if(Terminated()){ throw std::out_of_range("Iteratore was terminated ! "); }
    return current->Element();
}


// Function Terminated
template<typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept{
    
    if(current == nullptr){ return true; }
    return false;
}


// Operator ++
template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++(){

    if(Terminated()){ throw std::out_of_range("Error: Iterator is terminated!"); }

    if(elements.Empty()){

        current = nullptr;
        return *this;
    }
    
    if(elements.Top()->HasLeftChild()){
        if(current == &(elements.Top()->LeftChild())){

            if(elements.Top()->HasRightChild()){ MostLeftLeaf(&(elements.Top()->RightChild())); }
        }
    }       

    current = elements.TopNPop();
    return *this;
}


// Auxiliary function MostLeftLeaf
template<typename Data>
void BTPostOrderIterator<Data>::MostLeftLeaf(const typename BinaryTree<Data>::Node* theNode){

    while(theNode != nullptr){

        elements.Push(theNode);

        if(theNode->HasLeftChild()){ theNode= &(theNode->LeftChild()); }
        else if(theNode->HasRightChild()){ theNode= &(theNode->RightChild()); }
        else{ theNode = nullptr; }
    }
}


// Function Reset
template<typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept{

    elements.Clear();
    MostLeftLeaf(root);
    current = elements.Top();
}


////////////////////////////////////////////////////////////////////// BTPostOrderMutableIterator

// Specific constructor: Iterator over a given mutable binary tree
template<typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator( MutableBinaryTree<Data>& tree) :BTPostOrderIterator<Data>(tree){}

// Copy constructor
template<typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data>& otherIterator) : BTPostOrderIterator<Data>(otherIterator){}

// Move constructor
template<typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator( BTPostOrderMutableIterator<Data>&& otherIterator) : BTPostOrderIterator<Data>(std::move(otherIterator)){}

// Destructor
template<typename Data>
BTPostOrderMutableIterator<Data>::~BTPostOrderMutableIterator(){
    
    elements.Clear();
    current = nullptr;
    root = nullptr ;
}


// Copy assignment
template<typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(const BTPostOrderMutableIterator<Data>& otherIterator){
   
    root = otherIterator.root;
    current = otherIterator.current;
    elements = otherIterator.elements;

    return *this;
}


// Move assignment
template<typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator<Data>&& otherIterator){
    
    std::swap(root, otherIterator.root);
    std::swap(current, otherIterator.current);
    std::swap(elements, otherIterator.elements);

    return *this;
}


// Operator ==
template<typename Data>
bool BTPostOrderMutableIterator<Data>::operator==(const BTPostOrderMutableIterator<Data>& iterator) const noexcept
{
    if(root != iterator.root){ return false; }
    if(current != iterator.current){ return false; }
    if(elements != iterator.elements){ return false; }
    
    return true;
}


// Operator !=
template<typename Data>
bool BTPostOrderMutableIterator<Data>::operator!=(const BTPostOrderMutableIterator<Data>& iterator) const noexcept{
    
    return !(*this==iterator);
}


// Operator *
template<typename Data>
Data& BTPostOrderMutableIterator<Data>::operator*(){
    
    return const_cast<Data&>(BTPostOrderIterator<Data>::operator*());
}


////////////////////////////////////////////////////////////////////// BTInOrderIterator

// Specific constructor: Iterator over a given binary tree
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& tree){
    
    MostLeftLeaf(&(tree.Root()));
    current = elements.TopNPop();
    root = &(tree.Root()) ;
}


// Copy constructor
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& iterator){
    
    root = iterator.root;
    current = iterator.current;
    elements = iterator.elements;
}


// Move constructor
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator( BTInOrderIterator&& iterator){
   
    std::swap(root, iterator.root);
    std::swap(current, iterator.current);
    std::swap(elements, iterator.elements);
}


// Destructor
template<typename Data>
BTInOrderIterator<Data>::~BTInOrderIterator(){
    
    elements.Clear();
    current = nullptr;
    root = nullptr ;
}


// Copy assignment
template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator = (const BTInOrderIterator& iterator){
   
    root = iterator.root;
    current = iterator.current;
    elements = iterator.elements;

    return *this;
}


// Move assignment
template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=( BTInOrderIterator&& iterator)
{
    std::swap(root, iterator.root);
    std::swap(current, iterator.current);
    std::swap(elements, iterator.elements);

    return *this;
}


// Operator *
template<typename Data>
const Data& BTInOrderIterator<Data>::operator*() const{
    
    if(Terminated()){ throw std::out_of_range("Error: Iteratore is terminated!"); }
    return current->Element();
}


// Function Terminated
template<typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept{
    
    if(current == nullptr){ return true; }
    return false;
}


// Operator ++
template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++(){
    
    if(Terminated()){ throw std::out_of_range("Error: Iterator is terminated!"); }
    
    if(current->HasRightChild()){ MostLeftLeaf(&(current->RightChild())); }
    if(!elements.Empty()){ current = elements.TopNPop(); }
    else{ current=nullptr; }

    return *this;
}


// Auxiliary function MostLeftLeaf
template<typename Data>
void BTInOrderIterator<Data>::MostLeftLeaf(const typename BinaryTree<Data>::Node* theNode){
    
    while(theNode != nullptr){

        elements.Push(theNode);
        if(theNode->HasLeftChild()){ theNode = &(theNode->LeftChild()); } 
        else{ theNode = nullptr; }
    }
}


// Function Reset
template<typename Data>
void BTInOrderIterator<Data>::Reset() noexcept{
    
    elements.Clear();
    MostLeftLeaf(root);
    current=elements.Top();
}


////////////////////////////////////////////////////////////////////// BTInOrderMutableIterator

// Specific constructor: Iterator over a given mutable binary tree
template<typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(MutableBinaryTree<Data>& tree) : BTInOrderIterator<Data>(tree){}

// Copy constructor
template<typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const BTInOrderMutableIterator<Data>& iterator) : BTInOrderIterator<Data>(iterator){}

// Move constructor
template<typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(BTInOrderMutableIterator<Data>&& iterator) : BTInOrderIterator<Data>(std::move(iterator)){}

// Destructor
template<typename Data>
BTInOrderMutableIterator<Data>::~BTInOrderMutableIterator(){
    
    elements.Clear();
    current = nullptr;
    root = nullptr;
}


// Copy assignment
template<typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator<Data>& iterator){
    
    root = iterator.root;
    current = iterator.current;
    elements = iterator.elements;

    return *this;
}


// Move assignment 
template<typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=( BTInOrderMutableIterator<Data>&& iterator){
    
    std::swap(root, iterator.root);
    std::swap(current, iterator.current);
    std::swap(elements, iterator.elements);
    
    return *this;
}


// Operator ==
template<typename Data>
bool BTInOrderMutableIterator<Data>::operator==(const BTInOrderMutableIterator<Data>& iterator ) const noexcept{
    
    return(BTBreadthIterator<Data>::operator==(iterator));
}


// Operator !=
template<typename Data>
bool BTInOrderMutableIterator<Data>::operator!=(const BTInOrderMutableIterator<Data>& iterator ) const noexcept{
    
    return !(*this == iterator);
}


// Operator *
template<typename Data>
Data& BTInOrderMutableIterator<Data>::operator*(){
    
    return const_cast<Data&>(BTInOrderMutableIterator<Data>::operator*());
}


////////////////////////////////////////////////////////////////////// BTBreadthIterator

// Specific constructor: Iterator over a given binary tre
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& tree){

    current = &(tree.Root());
    root = current;
}


// Copy constructor
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& otherIterator){

    root = otherIterator.root;
    current = otherIterator.current;
    elements = otherIterator.elements;
}


// Move constructor
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& otherIterator){
    
    std::swap(root, otherIterator.root);
    std::swap(current, otherIterator.current);
    std::swap(elements, otherIterator.elements);
}


// Destructor
template<typename Data>
BTBreadthIterator<Data>::~BTBreadthIterator(){
    
    elements.Clear();
    current = nullptr;
    root = nullptr;
}


// Copy assignment
template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data>& otherIterator){
    
    root = otherIterator.root;
    current = otherIterator.current;
    elements = otherIterator.elements;

    return *this;
}


// Move assignment
template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=( BTBreadthIterator<Data>&& otherIterator)
{
    std::swap(root, otherIterator.root);
    std::swap(current, otherIterator.current);
    std::swap(elements, otherIterator.elements);

    return *this;
}


// Operator ==
template<typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data>& iterator) const noexcept{

    if(root != iterator.root){ return false; }
    if(current != iterator.current){ return false; }
    if(elements != iterator.elements){ return false; }

    return true;
}


// Operator !=
template<typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data>& iterator) const noexcept{
    
    return !(*this == iterator);
}


// Operator *
template<typename Data>
const Data& BTBreadthIterator<Data>::operator*() const{

    if(Terminated()){ throw std::out_of_range("Error: Iterator is terminated!"); }
    return current->Element();
}


// Function Terminated
template<typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept{
    
    if(current == nullptr){ return true; }
    return false;
}


// Operator ++
template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++(){
    
    if(Terminated()){ throw std::out_of_range("Error: Iterator is terminated!"); }
    
    if(current->HasLeftChild()){ elements.Enqueue(&(current->LeftChild())); }
    if(current->HasRightChild()){ elements.Enqueue(&(current->RightChild())); }

    if(elements.Empty()){ current = nullptr; }
    else{ current = elements.HeadNDequeue(); }

    return *this;
}


// Function Reset
template<typename Data>
void BTBreadthIterator<Data>::Reset() noexcept{

    elements.Clear();
    current = root;
}


////////////////////////////////////////////////////////////////////// BTBreadthMutableIterator

// Specific constructor: Iterator over a given mutable binary tree
template<typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(MutableBinaryTree<Data>& tree) : BTBreadthIterator<Data>(tree){}

// Copy constructor
template<typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(const BTBreadthMutableIterator<Data>& otherIterator) : BTBreadthIterator<Data>(otherIterator){}

// Move constructor
template<typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(BTBreadthMutableIterator<Data>&& otherIterator) : BTBreadthIterator<Data>(std::move(otherIterator)){}

// Destructor
template<typename Data>
BTBreadthMutableIterator<Data>::~BTBreadthMutableIterator(){

    elements.Clear();
    current = nullptr;
    root = nullptr;
}


// Copy assignment
template<typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator<Data>& otherIterator){

    root = otherIterator.root;
    current = otherIterator.current;
    elements = otherIterator.elements;

    return *this;
}


// Move assignment
template<typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=( BTBreadthMutableIterator<Data>&& otherIterator){

    std::swap(root, otherIterator.root);
    std::swap(current, otherIterator.current);
    std::swap(elements, otherIterator.elements);
    
    return *this;
}


// Operator ==
template<typename Data>
bool BTBreadthMutableIterator<Data>::operator==(const BTBreadthMutableIterator<Data>& iterator) const noexcept{
   
    return (BTBreadthIterator<Data>::operator==(iterator));
}


// Operator !=
template<typename Data>
bool BTBreadthMutableIterator<Data>::operator!=(const BTBreadthMutableIterator<Data>& iterator) const noexcept{
    
    return !(*this==iterator);
}


// Operator *
template<typename Data>
Data& BTBreadthMutableIterator<Data>::operator*(){

    return const_cast<Data&>(BTBreadthIterator<Data>::operator*());
}

/* ************************************************************************** */

}
