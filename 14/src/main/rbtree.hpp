﻿////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Реализация классов красно-черного дерева
/// \author    Sergey Shershakov
/// \version   0.1.0
/// \date      01.05.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
/// "Реализация" (шаблонов) методов, описанных в файле rbtree.h
///
////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>        // std::invalid_argument


namespace xi {


//==============================================================================
// class RBTree::node
//==============================================================================

template <typename Element, typename Compar >
RBTree<Element, Compar>::Node::~Node()
{
    if (_left)
        delete _left;
    if (_right)
        delete _right;
}



template <typename Element, typename Compar>
typename RBTree<Element, Compar>::Node* RBTree<Element, Compar>::Node::setLeft(Node* lf)
{
    // предупреждаем повторное присвоение
    if (_left == lf)
        return nullptr;

    // если новый левый — действительный элемент
    if (lf)
    {
        // если у него был родитель
        if (lf->_parent)
        {
            // ищем у родителя, кем был этот элемент, и вместо него ставим бублик
            if (lf->_parent->_left == lf)
                lf->_parent->_left = nullptr;
            else                                    // доп. не проверяем, что он был правым, иначе нарушение целостности
                lf->_parent->_right = nullptr;      
        }

        // задаем нового родителя
        lf->_parent = this;
    }

    // если у текущего уже был один левый — отменяем его родительскую связь и вернем его
    Node* prevLeft = _left;
    _left = lf;

    if (prevLeft)
        prevLeft->_parent = nullptr;

    return prevLeft;
}


template <typename Element, typename Compar>
typename RBTree<Element, Compar>::Node* RBTree<Element, Compar>::Node::setRight(Node* rg)
{
    // предупреждаем повторное присвоение
    if (_right == rg)
        return nullptr;

    // если новый правый — действительный элемент
    if (rg)
    {
        // если у него был родитель
        if (rg->_parent)
        {
            // ищем у родителя, кем был этот элемент, и вместо него ставим бублик
            if (rg->_parent->_left == rg)
                rg->_parent->_left = nullptr;
            else                                    // доп. не проверяем, что он был правым, иначе нарушение целостности
                rg->_parent->_right = nullptr;
        }

        // задаем нового родителя
        rg->_parent = this;
    }

    // если у текущего уже был один левый — отменяем его родительскую связь и вернем его
    Node* prevRight = _right;
    _right = rg;

    if (prevRight)
        prevRight->_parent = nullptr;

    return prevRight;
}


//==============================================================================
// class RBTree
//==============================================================================

template <typename Element, typename Compar >
RBTree<Element, Compar>::RBTree()
{
    _root = nullptr;
    _dumper = nullptr;
}

template <typename Element, typename Compar >
RBTree<Element, Compar>::~RBTree()
{
    // грохаем пока что всех через корень
    if (_root)
        delete _root;
}


template <typename Element, typename Compar >
void RBTree<Element, Compar>::deleteNode(Node* nd)
{
    // если переданный узел не существует, просто ничего не делаем, т.к. в вызывающем проверок нет
    if (nd == nullptr)
        return;

    // потомков убьет в деструкторе
    delete nd;
}


template <typename Element, typename Compar >
void RBTree<Element, Compar>::insert(const Element& key)
{
    // этот метод можно оставить студентам целиком
    Node* newNode = insertNewBstEl(key);

    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_BST_INS, this, newNode);

    rebalance(newNode);

    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_INSERT, this, newNode);

}




template <typename Element, typename Compar>
const typename RBTree<Element, Compar>::Node* RBTree<Element, Compar>::find(const Element& key)
{
    // TODO: метод реализуют студенты
}

template <typename Element, typename Compar >
typename RBTree<Element, Compar>::Node* 
        RBTree<Element, Compar>::insertNewBstEl(const Element& key)
{
    // TODO: метод реализуют студенты
}


template <typename Element, typename Compar >
typename RBTree<Element, Compar>::Node* 
    RBTree<Element, Compar>::rebalanceDUG(Node* nd)
{
    // TODO: этот метод студенты могут оставить и реализовать при декомпозиции балансировки дерева
    // В методе оставлены некоторые важные комментарии/snippet-ы





    // попадание в этот метод уже означает, что папа есть (а вот про дедушку пока не известно)
    //...

    Node* uncle = ...; // для левого случая нужен правый дядя и наоборот.

    // если дядя такой же красный, как сам нод и его папа...
    if (... uncle->isRed() ...)
    {
        // дядю и папу красим в черное
        // а дедушку — в коммунистические цвета

        // отладочное событие
        if (_dumper)
            _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RECOLOR1, this, nd);

        // теперь чередование цветов "узел-папа-дедушка-дядя" — К-Ч-К-Ч, но надо разобраться, что там
        // с дедушкой и его предками, поэтому продолжим с дедушкой
        //..
    }

    // дядя черный
    // смотрим, является ли узел "правильно-правым" у папочки
    if (...)                                        // для левого случая нужен правый узел, поэтом отрицание
    {                                               // CASE2 в действии

        // ... при вращении будет вызвано отладочное событие 
        // ...

    }


    // ...

    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RECOLOR3D, this, nd);


    // деда в красный

    // ...

    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RECOLOR3G, this, nd);

    // ...


    return nd;
}


template <typename Element, typename Compar >
void RBTree<Element, Compar>::rebalance(Node* nd)
{

    // TODO: метод реализуют студенты

    // ...

    // пока папа — цвета пионерского галстука, действуем
    while (...)
    {
        // локальная перебалансировка семейства "папа, дядя, дедушка" и повторная проверка
        ...
    } 


    // ...

}



template <typename Element, typename Compar>
void RBTree<Element, Compar>::rotLeft(typename RBTree<Element, Compar>::Node* nd)
{
    // TODO: метод реализуют студенты

    // правый потомок, который станет после левого поворота "выше"
    Node* y = nd->_right;
    
    if (!y)
        throw std::invalid_argument("Can't rotate left since the right child is nil");



    // ...


    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_LROT, this, nd);
}



template <typename Element, typename Compar>
void RBTree<Element, Compar>::rotRight(typename RBTree<Element, Compar>::Node* nd)
{
    // TODO: метод реализуют студенты


    // ...

    // отладочное событие
    if (_dumper)
        _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RROT, this, nd);
}


} // namespace xi

