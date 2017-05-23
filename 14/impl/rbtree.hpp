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

        // если у текущего уже был один левый — отменяем его родительскую связь и вернем его
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

        // если у текущего уже был один левый — отменяем его родительскую связь и вернем его
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
        // грохаем пока что всех через корень
        if (_root)
            delete _root;
    }


    template<typename Element, typename Compar>
    void RBTree<Element, Compar>::deleteNode(Node *nd)
    {
        // если переданный узел не существует, просто ничего не делаем, т.к. в вызывающем проверок нет
        if (nd == nullptr)
            return;

        // потомков убьет в деструкторе
        delete nd;
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
    const typename RBTree<Element, Compar>::Node *RBTree<Element, Compar>::find(const Element &key)
    {
        if (_root == nullptr)
            return nullptr;
        else
        {
            Node *x = _root;
            while (x != nullptr)
                if (key < x->_key)
                    x = x->_left;
                else if (key > x->_key)
                    x = x->_right;
                else
                    return x;
        }
        return nullptr;
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
            y->_left = z;
        else
            y->_right = z;
        return z;
    }


    template<typename Element, typename Compar>
    typename RBTree<Element, Compar>::Node *
    RBTree<Element, Compar>::rebalanceDUG(Node *nd)
    {
        // TODO: этот метод студенты могут оставить и реализовать при декомпозиции балансировки дерева
        // В методе оставлены некоторые важные комментарии/snippet-ы





        // попадание в этот метод уже означает, что папа есть (а вот про дедушку пока не известно)
        //...

//    Node* uncle = ...; // для левого случая нужен правый дядя и наоборот.

        // если дядя такой же красный, как сам нод и его папа...
//    if (... uncle->isRed() ...)
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
//    if (...)                                        // для левого случая нужен правый узел, поэтом отрицание
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
                    z->_parent->_color = BLACK;
                    y->_color = BLACK;
                    z->_parent->_parent->_color = RED;

                    z = z->_parent->_parent;
                } else
                {
                    if (z == z->_parent->_right) //case2
                    {
                        z = z->_parent;
                        rotLeft(z);
                    }
                    z->_parent->_color = BLACK; //case3
                    z->_parent->_parent->_color = RED;
                    rotRight(z->_parent->_parent);

                }
            } else
            {
                y = z->_parent->_parent->_left;
                if (y && y->_color == RED) //case4
                {
                    z->_parent->_color = BLACK;
                    y->_color = BLACK;
                    z->_parent->_parent->_color = RED;

                    z = z->_parent->_parent;
                } else
                {
                    if (z == z->_parent->_left) //case5
                    {
                        z = z->_parent;
                        rotRight(z);
                    }
                    z->_parent->_color = BLACK; //case6
                    z->_parent->_parent->_color = RED;
                    rotLeft(z->_parent->_parent);

                }
            }
        }
        _root->_color = BLACK;
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
        {
            y->_left->_parent = nd;
        }

        y->_parent = nd->_parent;

        if (!nd->_parent)
        {
            _root = y;
        } else if (nd == nd->_parent->_left)
        {
            nd->_parent->_left = y;
        } else
        {
            nd->_parent->_right = y;
        }

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
        {
            x->_right->_parent = nd;
        }

        x->_parent = nd->_parent;

        if (nd->_parent == nullptr)
        {
            _root = x;
        } else if (nd == nd->_parent->_left)
        {
            nd->_parent->_left = x;
        } else
        {
            nd->_parent->_right = x;
        }

        x->_right = nd;
        nd->_parent = x;

        // отладочное событие
        if (_dumper)
            _dumper->rbTreeEvent(IRBTreeDumper<Element, Compar>::DE_AFTER_RROT, this, nd);
    }
// todo REFACTOR TO SETBLACK ETC

    template<typename Element, typename Compar>
    void RBTree<Element, Compar>::remove(const Element &key)
    {
        Node *z = (Node *) find(key);

        if (z == nullptr)
            std::cout << "key doesn't exist!" << std::endl;
        else
        {
            Node *y = nullptr;
            Node *x = nullptr;

            if (z->_left == nullptr || z->_right == nullptr)
                y = z;
            else
                y = get_successor(z);

            if (y->_left != nullptr)
                x = y->_left;
            else
                x = y->_right;

            x->_parent = y->_parent;

            if (y->_parent == nullptr)
                _root = x;
            else if (y == y->_parent->_left)
                y->_parent->_left = x;
            else
                y->_parent->_right = x;

            if (y != z)
                z->_key = y->_key;

            if (y->_color == BLACK)
                remove_fixup(x);
            delete y;
            std::cout << "node deleted" << std::endl;
        }
        return;
    }

    template<typename Element, typename Compar>
    typename RBTree<Element, Compar>::Node *RBTree<Element, Compar>::get_successor(RBTree::Node *x)
    {
        if (x->_right != nullptr)
        {
            Node *t = x->_right;
            while (t->_left != nullptr)
                t = t->_left;
            return t;
        } else
        {
            Node *y = x->_parent;
            while (y != nullptr && x == y->_right)
            {
                x = y;
                y = y->_parent;
            }
            return y;
        }

    }

    template<typename Element, typename Compar>
    void RBTree<Element, Compar>::remove_fixup(RBTree::Node *x)
    {
        Node *uncle = nullptr;
        if (x->_color == RED)
        {
            x->_color = BLACK;
        } else
        {
            while (x->_color == BLACK && x != _root)
            {
                if (x == x->_parent->_left)
                {
                    uncle = x->_parent->_right;
                    // case1 for _left
                    //
                    if (uncle->_color == RED)
                    {
                        uncle->_color = BLACK;
                        x->_parent->_color = RED;
                        rotLeft(x->_parent);
                        uncle = x->_parent->_right;
                    } else
                    {
                        // case2 for _left
                        //
                        if (uncle->_left->_color == BLACK && uncle->_right->_color == BLACK)
                        {
                            uncle->_color = RED;
                            x = x->_parent;
                        } else
                        {
                            // case3 for _left
                            //
                            if (uncle->_right->_color == BLACK)
                            {
                                uncle->_left->_color = BLACK;
                                uncle->_color = RED;
                                rotRight(uncle);
                                uncle = x->_parent->_right;
                            }
                            // case4 for _left
                            //
                            uncle->_color = x->_parent->_color;
                            x->_parent->_color = BLACK;
                            uncle->_right->_color = BLACK;
                            rotLeft(x->_parent);
                            x = _root;
                        }
                    }
                } else
                {
                    uncle = x->_parent->_left;

                    // case1 for right
                    //
                    if (uncle->_color == RED)
                    {
                        uncle->_color = BLACK;
                        x->_parent->_color = RED;
                        rotRight(x->_parent);
                        uncle = x->_parent->_left;
                    } else
                    {
                        // case2 for right
                        //
                        if (uncle->_left->_color == BLACK && uncle->_right->_color == BLACK)
                        {
                            uncle->_color = RED;
                            x = x->_parent;
                        } else
                        {
                            // case3 for right
                            //
                            if (uncle->_left->_color == BLACK)
                            {
                                uncle->_right->_color = BLACK;
                                uncle->_color = RED;
                                rotLeft(uncle);
                                uncle = x->_parent->_left;
                            }

                            // case4 for right
                            //
                            uncle->_color = x->_parent->_color;
                            x->_parent->_color = BLACK;
                            uncle->_left->_color = BLACK;
                            rotRight(x->_parent);
                            x = _root;
                        }
                    }
                }
            }
        }
        _root->_color = BLACK;

        return;
    }


} // namespace xi

