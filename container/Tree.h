#pragma once

#include "Node.h"

#include <functional>
#include <boost/throw_exception.hpp>

namespace raccoon
{
  template<typename T>
  class Tree
  {      
  public:
      
      explicit Tree(Node<T> *rootNode);
      
      Node<T>* GetRoot()const;
      
      void AddNode(Node<T>* parent, Node<T>* node);
      
      void PerformActionOnAllNodes(std::function<void(const T&)> action);
      
  private:
      void PerformActionOnNode(Node<T>* node, std::function<void(const T&)> action);
      Node<T> *m_root;
  };
  
  template<typename T>
  Tree<T>::Tree(Node<T> *rootNode)
  :m_root(rootNode){
      if(m_root == nullptr)
      {
          BOOST_THROW_EXCEPTION(std::invalid_argument("Cannot create a tree with a null ptr as root"));
      }
  }
  
  template<typename T>
  Node<T>* Tree<T>::GetRoot()const{
      return m_root;
  }
  
  template<typename T>
  void Tree<T>::AddNode(Node<T>* parent, Node<T>* node){
      parent->AddChild(node);
  }
  
  template<typename T>
  void Tree<T>::PerformActionOnAllNodes(std::function<void(const T&)> action)
  {
      PerformActionOnNode(m_root, action);
  }
  
  template<typename T>
  void Tree<T>::PerformActionOnNode(Node<T>* node, std::function<void(const T&)> action)
  {
      for(unsigned i=0; i<node->GetNumChildren(); ++i)
      {
          PerformActionOnNode(node->GetChild(i), action);
      }
      action(node->Data());
  }
}