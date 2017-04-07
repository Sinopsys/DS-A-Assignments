//
// Created by kirill on 03.04.17.
//

//#include "SkipList.h"
#include <cstdlib>
#include <random>

//=============================================================================
//== NodeSkipList =============================================================
//=============================================================================

template<class Value, class Key, int numLevels>
void NodeSkipList<Value, Key, numLevels>::clear(void)
{
    for (int i = 0; i < numLevels; ++i)
    {
        this->m_nextjump[i] = 0;
    }
    this->m_levelHighest = -1;
}

template<class Value, class Key, int numLevels>
NodeSkipList<Value, Key, numLevels>::NodeSkipList(void)
{
    clear();
}

template<class Value, class Key, int numLevels>
NodeSkipList<Value, Key, numLevels>::NodeSkipList(Key key)
{
    clear();

    this->m_key = key;
}

template<class Value, class Key, int numLevels>
NodeSkipList<Value, Key, numLevels>::NodeSkipList(Key key, Value value)
{
    clear();

    this->m_key = key;
    this->m_value = value;
}
//=============================================================================
//== End of: NodeSkipList =====================================================
//=============================================================================

//=============================================================================
//== SkipList =================================================================
//=============================================================================
template<class Value, class Key, int numLevels>
SkipList<Value, Key, numLevels>::SkipList(double probability)
{
    srand(time(NULL));
    m_probability = probability;
    for (int i = 0; i < numLevels; ++i)
    {
        // Lets use m_pPreHead as a final sentinel element
        this->m_pPreHead->m_nextjump[i] = this->m_pPreHead;
    }
    this->m_pPreHead->m_levelHighest = numLevels - 1;
}

/**
 * a function to generate probability test
 * @param prob stock probability to check
 * @return passed
 */
bool gen_0_1_probability(const double &prob)
{
    return double(rand() % 100 + 1) / 100.0 > prob;
}

template<class Value, class Key, int numLevels>
void SkipList<Value, Key, numLevels>::insert(Value value, Key key)
{
    int level_highest = this->m_pPreHead->m_levelHighest;
    TypeNode *last_s_node = this->m_pPreHead;
    // array to remember last nodes
    // but not from the first level
    //
    TypeNode *arr[level_highest + 1];
    int layer = level_highest;
    while (layer >= 0)
    {
        while (last_s_node->m_nextjump[layer] != this->m_pPreHead
               && last_s_node->m_nextjump[layer]->m_key < key)
            last_s_node = last_s_node->m_nextjump[layer];
        arr[layer] = last_s_node;
        --layer;
    }
    layer = -1;
    while (last_s_node->m_next != this->m_pPreHead
           && last_s_node->m_next->m_key < key)
        // find smallest not in the level
        //
        last_s_node = last_s_node->m_next;

    TypeNode *tmp = last_s_node->m_next;
    TypeNode *new_next = new TypeNode(key, value);
    last_s_node->m_next = new_next;
    new_next->m_next = tmp;
    while (layer < level_highest)
    {
//        std::cout << gen_0_1_probability() / 100.0 << std::endl;
        if (gen_0_1_probability((const double &) this->m_probability))
            break;
        ++layer;
        TypeNode *last_level = arr[layer];
        TypeNode *temp = last_level->m_nextjump[layer];
        last_level->m_nextjump[layer] = new_next;
        new_next->m_nextjump[layer] = temp;
    }
    new_next->m_levelHighest = layer;
}

template<class Value, class Key, int numLevels>
void SkipList<Value, Key, numLevels>::remove(SkipList::TypeNode *node)
{
    // check if the list is empty
    if (this->m_pPreHead->m_next == this->m_pPreHead)
        throw std::underflow_error("Empty list.");

    int level = this->m_pPreHead->m_levelHighest;
    TypeNode *last_node = this->m_pPreHead;
    while (level >= 0)
    {
        while (last_node->m_nextjump[level] != this->m_pPreHead
               && last_node->m_nextjump[level]->m_key < node->m_key)
            last_node = last_node->m_nextjump[level];
        TypeNode *tmp = last_node;

        while (tmp->m_nextjump[level] != this->m_pPreHead
               && tmp->m_nextjump[level]->m_key == node->m_key)

            // delete if found the key
            //
            if (tmp->m_nextjump[level] == node)
            {
                // at this layer
                // we skip it
                //
                tmp->m_nextjump[level] = tmp->m_nextjump[level]->m_nextjump[level];
                break;
            }

        // decrement level by one
        //
        --level;
    }
    while (last_node->m_next != this->m_pPreHead
           && last_node->m_next->m_key < node->m_key)
        // find smallest not in the level
        //
        last_node = last_node->m_next;
    TypeNode *temp = last_node;
    while (temp->m_next != this->m_pPreHead
           && temp->m_next->m_key == node->m_key)
        // delete if found the key
        //
        if (temp->m_next == node)
        {
            temp->m_next = temp->m_next->m_next;
            node->m_levelHighest = -1;
            return;
        }

    throw std::invalid_argument("Node does not exist.");
}

template<class Value, class Key, int numLevels>
typename SkipList<Value, Key, numLevels>::TypeNode *SkipList<Value, Key, numLevels>::findLastLessThan(Key key) const
{
//   todo repair
//    TypeNode *last_smaller = this->m_pPreHead;
//    if (last_smaller->m_next == this->m_pPreHead)
//    {
//        // if the list is empty
//        return this->m_pPreHead;
//    }
//    // search via levels
//    int level = this->m_pPreHead->m_levelHighest;
//    // note: >=
//    while (level >= 0)
//    {
//        while (last_smaller->m_nextjump[level] != this->m_pPreHead
//               && last_smaller->m_nextjump[level]->m_key < key
//                )
//        {
//            last_smaller = last_smaller->m_nextjump[level];
//        }
//        level--;
//    }
//    // find smallest outside of level
//    while (last_smaller->m_next != this->m_pPreHead
//           && last_smaller->m_next->m_key < key
//            )
//    {
//        last_smaller = last_smaller->m_next;
//    }
//    return last_smaller;
}

template<class Value, class Key, int numLevels>
typename SkipList<Value, Key, numLevels>::TypeNode *SkipList<Value, Key, numLevels>::findFirst(Key key) const
{
// todo repair
//    TypeNode *last_smaller = findLastLessThan(key);
//    if (last_smaller->m_next != this->m_pPreHead
//        && last_smaller->m_next->m_key == key
//            )
//    {
//        // if the next node after last_smaller is equal to key return it
//        return last_smaller->m_next;
//    }
//    // otherwise the next after last_smaller is bigger
//    // so no such key exists
//    return 0;
}

// Put your code here

//=============================================================================
//== End of: SkipList =========================================================
//=============================================================================


// EOF
