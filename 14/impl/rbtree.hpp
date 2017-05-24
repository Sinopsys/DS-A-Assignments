////////////////////////////////////////////////////////////////////////////////
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

//
// KUPRIYANOV KIRILL BSE 151
//

namespace xi
{
//==============================================================================
// class RBTree::node
//==============================================================================

    template<typename Element, typename Compar>
    RBTree<Element, Compar>::Node::~Node()
    {
        if (_left)
            delete _left;
        if (_right)
            delete _right;
    }


    template<typename Element, typename Compar>
    typename RBTree<Element, Compar>::Node *RBTree<Element, Compar>::Node::setLeft(Node *lf)
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

        // если у текущего уже был один левый — отменяем его родительскую связь и вернем его
        Node *prevLeft = _left;
        _left = lf;

        if (prevLeft)
            prevLeft->_parent = nullptr;

        return prevLeft;
    }


    template<typename Element, typename Compar>
    typename RBTree<Element, Compar>::Node *RBTree<Element, Compar>::Node::setRight(Node *rg)
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

        // если у текущего уже был один левый — отменяем его родительскую связь и вернем его
        Node *prevRight = _right;
        _right = rg;

        if (prevRight)
            prevRight->_parent = nullptr;

        return prevRight;
    }


//==============================================================================
// class RBTree
//==============================================================================

    template<typename Element, typename Compar>
    RBTree<Element, Compar>::RBTree()
    {
        _root = nullptr;
        _dumper = nullptr;
    }

    template<typename Element, typename Compar>
    RBTree<Element, Compar>::~RBTree()
    {
        if (_root)
            this->deleteNode(_root);
    }


    template<typename Element, typename Compar>
    void RBTree<Element, Compar>::deleteNode(Node *nd)
    {
        if (nd->_left)
            this->deleteNode(nd->_left);
        if (nd->_right)
            this->deleteNode(nd->_right);
        if (!nd->_parent)
            delete nd->_parent;
    }

    template<typename Element, typename Compar>
    void RBTree<Element, Compar>::insert(const Element &key)
    {
        // этот метод можно оставить студентам целиком
        Node *newNode = insertNewBstEl(key);

        // отладочное событие
        if (_dumper)
            _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_BST_INS, this, newNode);

        if (newNode != _root)
            newNode->_color = RED;

        rebalance(newNode);

        // отладочное событие
        if (_dumper)
            _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_INSERT, this, newNode);

    }


    template<typename Element, typename Compar>
    typename RBTree<Element, Compar>::Node *
    RBTree<Element, Compar>::insertNewBstEl(const Element &key)
    {
        Node *z = new Node(key);
        Node *y = nullptr;
        Node *nd = _root;
        while (nd)
        {
            y = nd;
            if (z->_key < nd->_key)
                nd = nd->_left;
            else if (z->_key > nd->_key)
                nd = nd->_right;
            else
            {
                std::cerr << "key already exists" << std::endl;
                return z;
            }
        }
        z->_parent = y;
        if (!y)
            _root = z;
        else if (z->_key < y->_key)
            y->setLeft(z);
        else
            y->setRight(z);
        return z;
    }


    template<typename Element, typename Compar>
    void RBTree<Element, Compar>::rebalance(Node *z)
    {
        Node *y = nullptr;
        while (z->_parent != nullptr && z->_parent->_color == RED)
        {
            if (z->_parent == z->_parent->_parent->_left)
            {
                y = z->_parent->_parent->_right;
                if (y && y->_color == RED) //case1
                {
                    z->_parent->setBlack();
                    y->setBlack();
                    z->_parent->_parent->setRed();

                    z = z->_parent->_parent;
                } else
                {
                    if (z == z->_parent->_right) //case2
                    {
                        z = z->_parent;
                        rotLeft(z);
                    }
                    z->_parent->setBlack(); //case3
                    z->_parent->_parent->setRed();
                    rotRight(z->_parent->_parent);

                }
            } else
            {
                y = z->_parent->_parent->_left;
                if (y && y->_color == RED) //case4
                {
                    z->_parent->_color = BLACK;
                    y->setBlack();
                    z->_parent->_parent->setRed();

                    z = z->_parent->_parent;
                } else
                {
                    if (z == z->_parent->_left) //case5
                    {
                        z = z->_parent;
                        rotRight(z);
                    }
                    z->_parent->setBlack(); //case6
                    z->_parent->_parent->setRed();
                    rotLeft(z->_parent->_parent);

                }
            }
        }
        _root->setBlack();
        return;
    }

    template<typename Element, typename Compar>
    void RBTree<Element, Compar>::rotLeft(typename RBTree<Element, Compar>::Node *nd)
    {
        Node *y = nd->_right;
        if (!y)
            throw std::invalid_argument("Can't rotate _left since the _right child is nil");
        nd->_right = y->_left;

        if (y->_left)
            y->_left->_parent = nd;

        y->_parent = nd->_parent;

        if (!nd->_parent)
            _root = y;
        else if (nd == nd->_parent->_left)
            nd->_parent->_left = y;
        else
            nd->_parent->_right = y;

        y->_left = nd;
        nd->_parent = y;
        // отладочное событие
        if (_dumper)
            _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_LROT, this, nd);
    }


    template<typename Element, typename Compar>
    void RBTree<Element, Compar>::rotRight(typename RBTree<Element, Compar>::Node *nd)
    {
        Node *x = nd->_left;
        nd->_left = x->_right;

        if (x->_right != nullptr)
            x->_right->_parent = nd;

        x->_parent = nd->_parent;

        if (nd->_parent == nullptr)
            _root = x;
        else if (nd == nd->_parent->_left)

            nd->_parent->_left = x;
        else
            nd->_parent->_right = x;

        x->_right = nd;
        nd->_parent = x;

        // отладочное событие
        if (_dumper)
            _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RROT, this, nd);
    }
} // namespace xi


// EOF
