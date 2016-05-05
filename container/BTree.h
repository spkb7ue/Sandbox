#pragma once

#include "BNode.h"

#include <functional>
#include <boost/throw_exception.hpp>

namespace raccoon
{
  template<typename T>
  class BTree
  {
  public:

      explicit BTree(BNode<T> *rootBNode);

      BNode<T>* GetRoot()const;

      void SetLeft(BNode<T>* parent, BNode<T>* left);

      void SetRight(BNode<T>* parent, BNode<T>* right);

      void PerformActionOnAllNodes(std::function<void(const T&)> action);

  private:
      void PerformActionOnBNode(BNode<T>* BNode, std::function<void(const T&)> action);
      BNode<T> *m_root;
  };

  template<typename T>
  BTree<T>::BTree(BNode<T> *rootBNode)
  :m_root(rootBNode){
      if(m_root == nullptr)
      {
          BOOST_THROW_EXCEPTION(std::invalid_argument("Cannot create a BTree with a null ptr as root"));
      }
  }

  template<typename T>
  BNode<T>* BTree<T>::GetRoot()const{
      return m_root;
  }

  template<typename T>
  void BTree<T>::SetLeft(BNode<T>* parent, BNode<T>* left){
      parent->SetLeft(left);
  }

  template<typename T>
  void BTree<T>::SetRight(BNode<T>* parent, BNode<T>* right){
      parent->SetRight(right);
  }

  template<typename T>
  void BTree<T>::PerformActionOnAllNodes(std::function<void(const T&)> action)
  {
      PerformActionOnBNode(m_root, action);
  }

  template<typename T>
  void BTree<T>::PerformActionOnBNode(BNode<T>* BNode, std::function<void(const T&)> action)
  {
    if(BNode != nullptr)
    {
        PerformActionOnBNode(BNode->GetLeft(), action);
        PerformActionOnBNode(BNode->GetRight(), action);
        action(BNode->Data());
    }
  }
}
