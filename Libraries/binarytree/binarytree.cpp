#include "binarytree.hpp"

namespace lasd {
//NODO NOT MUTABLE BINARY TREE
//EQUALS TRA DUE NODI
template<typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& nodo) const noexcept
{
    if(Element()==nodo.Element())
        return true;

    return false;
}
//NOT EQUALS TRA DUE NODI
template<typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& nodo) const noexcept
{
    return !(*this==nodo);
}

// IS A LEF ?
template<typename Data>
bool BinaryTree<Data>::Node::IsLeaf() const noexcept
{
    return (!HasRightChild() && !HasLeftChild());
}

// BYNARY TREE NOT MUTABLE

//MAP IN PREORDER + AUX FUNCTION
template<typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor mapfunc) const
{
    if(size != 0) PreOrderMap(mapfunc , Root());
}

template<typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor mapfunc ,const Node& temp)const
{
    mapfunc(temp.Element());
    if(temp.HasLeftChild()) PreOrderMap(mapfunc , temp.LeftChild());
    if(temp.HasRightChild()) PreOrderMap(mapfunc , temp.RightChild());
}

//MAP IN POST ORDER + AUX FUNCTION
template<typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor mapfunc) const
{
    if(size != 0) PostOrderMap(mapfunc , Root());
}

template<typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor mapfunc , const Node& temp)const
{
    if(temp.HasLeftChild())
        PostOrderMap(mapfunc , temp.LeftChild());
    if(temp.HasRightChild())
        PostOrderMap(mapfunc , temp.RightChild());

    mapfunc(temp.Element());
}

//MAP IN ORDER + AUX FUNCTION 
template<typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor mapfunc) const
{
    if(size != 0) InOrderMap(mapfunc , Root());
}

template<typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor mapfunc ,const Node& temp)const
{
    if(temp.HasLeftChild())
        InOrderMap(mapfunc , temp.LeftChild());

    mapfunc(temp.Element());

    if(temp.HasRightChild())
        InOrderMap(mapfunc , temp.RightChild());
}

//BREADTH MAP + AUX FUNCTION
template<typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor mapfunc) const
{
   if(size != 0) BreadthMap(mapfunc, Root());
}

template<typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor mapfunc ,const Node& temp) const
{
    using Node = typename BinaryTree<Data>::Node;
    QueueLst<Node const*> auxcoda;
    auxcoda.Enqueue(&temp);

    while(!auxcoda.Empty())
    {
        const Node* current = auxcoda.HeadNDequeue();
        mapfunc(current->Element());
        if(temp.HasLeftChild())
            auxcoda.Enqueue(&(current->LeftChild()));
        if(temp.HasRightChild())
            auxcoda.Enqueue(&(current->RightChild()));
    }
}
// FOLD BINARY TREE
template<typename Data>
void BinaryTree<Data>::Fold(FoldFunctor foldfunc , void * acc) const 
{
    PreOrderMap([acc,foldfunc](const Data& value){
        foldfunc(value,acc);
    }
    );
}

template<typename Data>
void BinaryTree<Data>::Map(MapFunctor foldfunc ) const 
{
    PreOrderMap(foldfunc);
}

//UGUAGLIANZA TRA DUE BINARYTREE + AUX FUNCTION
template<typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& tree) const noexcept
{
    if(size != tree.size)
        return false;
    
    return AuxEqualsBinaryTree(&(Root()), &(tree.Root()));
}

template<typename Data>
bool BinaryTree<Data>::AuxEqualsBinaryTree (const Node* node1 , const Node* node2) const noexcept
{
    if(node1==nullptr && node2==nullptr)
        return true;
    
    if(node1==nullptr || node2==nullptr)
        return false;

    if(node1->Element() != node2->Element())
        return false;

    return (AuxEqualsBinaryTree(&(node1->LeftChild()),&(node2->LeftChild())) && AuxEqualsBinaryTree(&(node1->RightChild()),&(node2->RightChild())));

}

template<typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& tree) const noexcept
{
    return !(*this==tree);
}
/* ************************************************************************** */
//MUTABLE BINARY TREE

//MAP IN PREORDER + AUX FUNCTION
template<typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MutableMapFunctor mapfunc) 
{
    PreOrderMap(mapfunc , Root());
}
template<typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MutableMapFunctor mapfunc , MutableNode& temp) 
{
    if(&temp!=nullptr)
    {
    mapfunc(temp.Element());

    if(temp.HasLeftChild())
        PreOrderMap(mapfunc , temp.LeftChild());
    if(temp.HasRightChild())
        PreOrderMap(mapfunc , temp.RightChild());
    } 

}
//MAP IN POST ORDER + AUX FUNCTION
template<typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MutableMapFunctor mapfunc) 
{
    PostOrderMap(mapfunc , Root());
}
template<typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MutableMapFunctor mapfunc , MutableNode& temp) 
{
    if(&temp!=nullptr)
    {
    if(temp.HasLeftChild())
        PostOrderMap(mapfunc , temp.LeftChild());
    if(temp.HasRightChild())
        PostOrderMap(mapfunc , temp.RightChild());

    mapfunc(temp.Element());
    }

    
}
//MAP IN ORDER + AUX FUNCTION 
template<typename Data>
void MutableBinaryTree<Data>::InOrderMap(MutableMapFunctor mapfunc) 
{
    InOrderMap(mapfunc , Root());
}
template<typename Data>
void MutableBinaryTree<Data>::InOrderMap(MutableMapFunctor mapfunc , MutableNode& temp) 
{
    if(&temp!=nullptr)
    {
    if(temp.HasLeftChild())
        InOrderMap(mapfunc , temp.LeftChild());

    mapfunc(temp.Element());

    if(temp.HasRightChild())
        InOrderMap(mapfunc , temp.RightChild());
    }

}
//BREADTH MAP + AUX FUNCTION
template<typename Data>
void MutableBinaryTree<Data>::BreadthMap(MutableMapFunctor mapfunc) 
{
   BreadthMap(mapfunc, Root());
}
template<typename Data>
void MutableBinaryTree<Data>::BreadthMap(MutableMapFunctor mapfunc , MutableNode& temp)
{
    if(&temp==nullptr)
        return;
    
    QueueLst<MutableNode*> auxcoda;
    auxcoda.Enqueue(&temp);
    while(!auxcoda.Empty())
    {
        MutableNode* current = auxcoda.HeadNDequeue();
        mapfunc(current->Element());
        if(temp.HasLeftChild())
            auxcoda.Enqueue(&(current->LeftChild()));
        if(temp.HasRightChild())
            auxcoda.Enqueue(&(current->RightChild()));
    }
}

template<typename Data>
void MutableBinaryTree<Data>::Map(MutableMapFunctor mapfunc )  
{
    PreOrderMap(mapfunc);
}

/* ************************************************************************** */
//BTPREORDER ITERATOR

template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& tree)
{
    current=&(tree.Root());
    root=current;
}

template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator& actual_iterator) 
{
    root = actual_iterator.root;
    current=actual_iterator.current;
    elements=actual_iterator.elements;
}

template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator&& actual_iterator)
{
    std::swap(root,actual_iterator.root);
    std::swap(current,actual_iterator.current);
    std::swap(elements,actual_iterator.elements);
}

template<typename Data>
BTPreOrderIterator<Data>::~BTPreOrderIterator()
{
    elements.Clear();
    current=nullptr ;
    root=nullptr ;
}

template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator& copyiterator)
{
    root = copyiterator.root ;
    elements=copyiterator.elements;
    current=copyiterator.current ;

    return *this;
}

template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=( BTPreOrderIterator&& moveiterator)
{
    
    std::swap(elements, moveiterator.elements);
    std::swap(root, moveiterator.root);
    std::swap(current , moveiterator.current);

    return *this;
}

template<typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator& equaliterator) const noexcept
{
    if(root=equaliterator.root)
        if(current== equaliterator.current)
            if(elements==equaliterator.elements)
                return true;
        
    return false;
}
template<typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator& notequalsiterator) const noexcept
{
    return !(*this==notequalsiterator);
}

template<typename Data>
const Data& BTPreOrderIterator<Data>::operator*() const
{
    if(Terminated())
        throw std::out_of_range("Iterator was terminated ! ");
    
    return current->Element();
}

template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++()
{
    if(Terminated())
        throw std::out_of_range("Iterator was terminated ! ");

    if(current->HasRightChild())
        elements.Push(&(current->RightChild()));

    if(current->HasLeftChild())
        elements.Push(&(current->LeftChild()));
    
    if(elements.Empty())
        current=nullptr;
    else
    {
        current=elements.TopNPop();
    }

    return *this;
}

template<typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept 
{
    return (current==nullptr);
}

template<typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept
{
    elements.Clear();
    current=root;
}

//BTPREORDER MUTABLE  ITERATOR
template<typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator( MutableBinaryTree<Data>& tree) : BTPreOrderIterator<Data>(tree)
{
    //current=&(tree.Root());
    //root = current ;
}

template<typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const BTPreOrderMutableIterator<Data>& iterator) : BTPreOrderIterator<Data>(iterator)
{
    //elements=StackLst<typename MutableBinaryTree<Data>::MutableNode *>(iterator.elements);
    //current=iterator.current;
    //root = iterator.root;
}

template<typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator( BTPreOrderMutableIterator<Data>&& iterator) : BTPreOrderIterator<Data>(std::move(iterator))
{
    //elements=StackLst<typename MutableBinaryTree<Data>::MutableNode *>(std::move(iterator.elements));
    //std::swap(root,iterator.root);
    //std::swap(current,iterator.current);
}

template<typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator<Data>& iterator)
{
    root = iterator.root;
    current=iterator.current;
    elements=iterator.elements;

    return *this;
}

template<typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=( BTPreOrderMutableIterator<Data>&& iterator)
{
    std::swap(root,iterator.root);
    std::swap(current,iterator.current);
    std::swap(elements,iterator.elements);

    return *this;
}

template<typename Data>
BTPreOrderMutableIterator<Data>::~BTPreOrderMutableIterator()
{
    elements.Clear();
    current=nullptr ;
    root = nullptr ;
}

template<typename Data>
bool BTPreOrderMutableIterator<Data>::operator==(const BTPreOrderMutableIterator<Data>& equaliterator) const noexcept
{
    /*if(current== equaliterator.current)
        if(elements==equaliterator.elements)
            return true;
        
    return false;*/

    return (BTPreOrderIterator<Data>::operator==(equaliterator));
}
template<typename Data>
bool BTPreOrderMutableIterator<Data>::operator!=(const BTPreOrderMutableIterator<Data>& notequalsiterator) const noexcept
{
    return !(*this==notequalsiterator);
}

template<typename Data>
Data& BTPreOrderMutableIterator<Data>::operator*()
{
    return const_cast<Data&>(BTPreOrderIterator<Data>::operator*());
}

// ...
/* ************************************************************************** */
//BTPOSTORDER ITERATOR NOT MUTABLE
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& tree)
{
    LastLeftLeaf(&(tree.Root()));
    current=elements.TopNPop();
    root = &(tree.Root()) ;
}

template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& iterator)
{
    root = iterator.root;
    current=iterator.current;
    elements=iterator.elements;
}

template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator( BTPostOrderIterator&& iterator)
{
    //root=std::move(iterator.root);
    //current=std::move(iterator.current);
    //elements=StackLst<typename BinaryTree<Data>::Node*>(std::move(iterator.elements));

    std::swap(root,iterator.root);
    std::swap(current,iterator.current);
    std::swap(elements,iterator.elements);
}

template<typename Data>
BTPostOrderIterator<Data>::~BTPostOrderIterator()
{
    elements.Clear();
    current=nullptr;
    root=nullptr ;
}

template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& copyiterator)
{
    root=copyiterator.root;
    current=copyiterator.current;
    elements=copyiterator.elements;

    return *this;
}

template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=( BTPostOrderIterator&& moveiterator)
{
    std::swap(root,moveiterator.root);
    std::swap(current,moveiterator.current);
    std::swap(elements,moveiterator.elements);

    return *this;
}

template<typename Data>
const Data& BTPostOrderIterator<Data>::operator*() const
{
    if(Terminated())
        throw std::out_of_range("Iteratore was terminated ! ");

    return current->Element();
}

template<typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept
{
    return (current==nullptr);
}

template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++()
{
    if(Terminated())
        throw std::out_of_range("Iterator was terminated !");
    
    if(!elements.Empty()){
        if(elements.Top()->HasLeftChild())
            if(current==&(elements.Top()->LeftChild()))
                if(elements.Top()->HasRightChild())
                    LastLeftLeaf(&(elements.Top()->RightChild()));
        current=elements.TopNPop();
    }
    else
        current=nullptr;
    
    return *this;

}

template<typename Data>
void BTPostOrderIterator<Data>::LastLeftLeaf(const typename BinaryTree<Data>::Node* actual_node)
{
    while(actual_node!=nullptr){
        elements.Push(actual_node);
        if(actual_node->HasLeftChild())
            actual_node=&(actual_node->LeftChild());
        else if (actual_node->HasRightChild())
            actual_node=&(actual_node->RightChild());
        else
            actual_node=nullptr;
    }
}

template<typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept
{
    elements.Clear();
    LastLeftLeaf(root);
    current = elements.Top();
}
/* ************************************************************************** */
template<typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator( MutableBinaryTree<Data>& tree) :BTPostOrderIterator<Data>(tree)
{
    //LastLeftLeaf(tree.Root());
    //current=elements.TopNPop();
    //root = tree.Root() ;
}

template<typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data>& copyiterator) : BTPostOrderIterator<Data>(copyiterator)
{
    //root=copyiterator.root;
    //current=copyiterator.current;
    //elements=copyiterator.elements;
}

template<typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator( BTPostOrderMutableIterator<Data>&& moveiterator) : BTPostOrderIterator<Data>(std::move(moveiterator))
{
    //std::swap(root,moveiterator.root);
    //std::swap(current,moveiterator.current);
    //std::swap(elements,moveiterator.elements);
}

template<typename Data>
BTPostOrderMutableIterator<Data>::~BTPostOrderMutableIterator()
{
    elements.Clear();
    root=current=nullptr;
}

template<typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(const BTPostOrderMutableIterator<Data>& copyiterator)
{
    root=copyiterator.root;
    current=copyiterator.current;
    elements=copyiterator.elements;

    return *this;
}

template<typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator<Data>&& moveiterator)
{
    std::swap(root,moveiterator.root);
    std::swap(current,moveiterator.current);
    std::swap(elements,moveiterator.elements);

    return *this;
}

template<typename Data>
bool BTPostOrderMutableIterator<Data>::operator==(const BTPostOrderMutableIterator<Data>& iterator) const noexcept
{
    if(root==iterator.root )
        if(current==iterator.current)
            if(elements==iterator.elements)
                return true;
    
    return false;
}

template<typename Data>
bool BTPostOrderMutableIterator<Data>::operator!=(const BTPostOrderMutableIterator<Data>& iterator) const noexcept
{
    return !(*this==iterator);
}

template<typename Data>
Data& BTPostOrderMutableIterator<Data>::operator*()
{
    return const_cast<Data&>(BTPostOrderIterator<Data>::operator*());
}
/* ************************************************************************** */
//BTInOrderIterator
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& tree)
{
    LastLeftLeaf(&(tree.Root()));
    current=elements.TopNPop();
    root = &(tree.Root()) ;
}

template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& iterator)
{
    root = iterator.root;
    current=iterator.current;
    elements=iterator.elements;
}

template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator( BTInOrderIterator&& moveiterator)
{
    std::swap(root,moveiterator.root);
    std::swap(current,moveiterator.current);
    std::swap(elements,moveiterator.elements);
}

template<typename Data>
BTInOrderIterator<Data>::~BTInOrderIterator()
{
    elements.Clear();
    current=nullptr;
    root=nullptr ;
}

template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator& copyiterator)
{
    root=copyiterator.root;
    current=copyiterator.current;
    elements=copyiterator.elements;

    return *this;
}

template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=( BTInOrderIterator&& moveiterator)
{
    std::swap(root,moveiterator.root);
    std::swap(current,moveiterator.current);
    std::swap(elements,moveiterator.elements);

    return *this;
}

template<typename Data>
const Data& BTInOrderIterator<Data>::operator*() const
{
    if(Terminated())
        throw std::out_of_range("Iteratore was terminated ! ");

    return current->Element();
}

template<typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept
{
    return (current==nullptr);
}

template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++()
{
    if(Terminated())
        throw std::out_of_range("Iterator was terminated !");
    
    if(current->HasRightChild())
        LastLeftLeaf(&(current->RightChild()));

    if(!elements.Empty())
        current=elements.TopNPop();
    else
        current=nullptr;

    return *this;
}

template<typename Data>
void BTInOrderIterator<Data>::LastLeftLeaf(const typename BinaryTree<Data>::Node* actual_node)
{
    while(actual_node!=nullptr)
    {
    elements.Push(actual_node);
    if (actual_node->HasLeftChild()) 
        actual_node = &(actual_node->LeftChild());
    else 
        actual_node = nullptr;
    }
}

template<typename Data>
void BTInOrderIterator<Data>::Reset() noexcept
{
    elements.Clear();
    LastLeftLeaf(root);
    current=elements.Top();
}

/* ************************************************************************** */
//BTInOrderIterator Mutable
template<typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator( MutableBinaryTree<Data>& tree) : BTInOrderIterator<Data>(tree)
{
    //current=tree.Root();
    //root=current ;
}

template<typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const BTInOrderMutableIterator<Data>& copyiterator) : BTInOrderIterator<Data>(copyiterator)
{
    //root=copyiterator.root;
    //current=copyiterator.current;
    //elements=StackLst<typename MutableBinaryTree<Data>::MutableNode* >(copyiterator.elements);
}

template<typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(BTInOrderMutableIterator<Data>&& moveiterator) : BTInOrderIterator<Data>(std::move(moveiterator))
{
    //root=std::move(moveiterator.root);
    //current=std::move(moveiterator.current);
    //elements=StackLst<typename MutableBinaryTree<Data>::MutableNode* >(std::move(moveiterator.elements));
}

template<typename Data>
BTInOrderMutableIterator<Data>::~BTInOrderMutableIterator()
{
    elements.Clear();
    current=nullptr;
    root=nullptr;
}

template<typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator<Data>& copyiterator)
{
    root=copyiterator.root;
    current=copyiterator.current;
    elements=copyiterator.elements;

    return *this;
}
template<typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=( BTInOrderMutableIterator<Data>&& moveiterator)
{
    std::swap(root,moveiterator.root);
    std::swap(current,moveiterator.current);
    std::swap(elements,moveiterator.elements);
    
    return *this;
}

template<typename Data>
bool BTInOrderMutableIterator<Data>::operator==(const BTInOrderMutableIterator<Data>& iterator ) const noexcept
{
    return (BTBreadthIterator<Data>::operator==(iterator));
}

template<typename Data>
bool BTInOrderMutableIterator<Data>::operator!=(const BTInOrderMutableIterator<Data>& iterator ) const noexcept
{
    return !(*this==iterator);
}

template<typename Data>
Data& BTInOrderMutableIterator<Data>::operator*()
{
    return const_cast<Data&>(BTInOrderMutableIterator<Data>::operator*());
}
/* ************************************************************************** */
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& tree)
{
    current=&(tree.Root());
    root=current;
}

template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& copyiterator)
{
    root=copyiterator.root;
    current=copyiterator.current;
    elements=copyiterator.elements;
}

template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& moveiterator)
{
    std::swap(root,moveiterator.root);
    std::swap(current,moveiterator.current);
    std::swap(elements,moveiterator.elements);
}
template<typename Data>
BTBreadthIterator<Data>::~BTBreadthIterator()
{
    elements.Clear();
    current=nullptr;
    root=nullptr;
}

template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data>& copyiterator)
{
    root=copyiterator.root;
    current=copyiterator.current;
    elements=copyiterator.elements;

    return *this;
}
template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=( BTBreadthIterator<Data>&& moveiterator)
{
    std::swap(root,moveiterator.root);
    std::swap(current,moveiterator.current);
    std::swap(elements,moveiterator.elements);

    return *this;
}
template<typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data>& iterator) const noexcept
{
    if(root!=iterator.root)
        if(current==iterator.current)
            if(elements==iterator.elements)
                return true;

    return false;
}
template<typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data>& iterator) const noexcept
{
    return !(*this==iterator);
}
template<typename Data>
const Data& BTBreadthIterator<Data>::operator*() const
{
    if(Terminated())
        throw std::out_of_range("Iterator was terminated ! ");

    return current->Element();
}

template<typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept
{
    return (current==nullptr);
}

template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++()
{
    if(Terminated())
        throw std::out_of_range("Iterator was terminated ! ");
    
    if(current->HasLeftChild())
        elements.Enqueue(&(current->LeftChild()));

    if(current->HasRightChild())
        elements.Enqueue(&(current->RightChild()));

    if(elements.Empty())
        current=nullptr;
    else
    {
        current=elements.HeadNDequeue();
    }

    return *this;
}

template<typename Data>
void BTBreadthIterator<Data>::Reset() noexcept
{
    elements.Clear();
    current=root;
}
//BREADTH ITERATOR MUTABLE
template<typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator( MutableBinaryTree<Data>& tree) :BTBreadthIterator<Data>(tree)
{
    //current=tree.Root();
    //root=current ;
}

template<typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(const BTBreadthMutableIterator<Data>& copyiterator) : BTBreadthIterator<Data>(copyiterator)
{
    //root=copyiterator.root;
    //current=copyiterator.current;
    //elements=QueueLst<typename MutableBinaryTree<Data>::MutableNode* >(copyiterator.elements);
}

template<typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(BTBreadthMutableIterator<Data>&& moveiterator) : BTBreadthIterator<Data>(std::move(moveiterator))
{
    //root=std::move(moveiterator.root);
    //current=std::move(moveiterator.current);
    //elements=QueueLst<typename MutableBinaryTree<Data>::MutableNode* >(std::move(moveiterator.elements));
}

template<typename Data>
BTBreadthMutableIterator<Data>::~BTBreadthMutableIterator()
{
    elements.Clear();
    current=nullptr;
    root=nullptr;
}

template<typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator<Data>& copyiterator)
{
    root=copyiterator.root;
    current=copyiterator.current;
    elements=copyiterator.elements;

    return *this;
}
template<typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=( BTBreadthMutableIterator<Data>&& moveiterator)
{
    std::swap(root,moveiterator.root);
    std::swap(current,moveiterator.current);
    std::swap(elements,moveiterator.elements);
    
    return *this;
}

template<typename Data>
bool BTBreadthMutableIterator<Data>::operator==(const BTBreadthMutableIterator<Data>& iterator ) const noexcept
{
    return (BTBreadthIterator<Data>::operator==(iterator));
}

template<typename Data>
bool BTBreadthMutableIterator<Data>::operator!=(const BTBreadthMutableIterator<Data>& iterator ) const noexcept
{
    return !(*this==iterator);
}

template<typename Data>
Data& BTBreadthMutableIterator<Data>::operator*()
{
    return const_cast<Data&>(BTBreadthIterator<Data>::operator*());
}
}
