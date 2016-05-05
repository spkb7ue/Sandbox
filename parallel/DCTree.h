#pragma once
#include <container/BTree.h>
#include <container/BNode.h>

namespace raccoon{
 
    template<typename T>
    class DCTree : public BTree<T>{
    public:
        explicit DCTree(BNode<T> *rootNode);
    };
    
    template<typename T>
    DCTree<T>::DCTree(BNode<T>* rootNode):BTree<T>(rootNode){}
}