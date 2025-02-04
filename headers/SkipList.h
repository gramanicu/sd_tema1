// Copyright Grama Nicolae 2019
#ifndef HEADERS_SKIPLIST_H_
#define HEADERS_SKIPLIST_H_

#include <math.h>
#include <stdint.h>
#include <iostream>

#include "Random.h"

template <typename T>
class SkipList {
 private:
  class SkipNode {
   public:
    // Number of levels
    int32_t levels;
    // The value/element stored in the node
    T value;
    // "Express" links to other nodes
    SkipNode** shortcut;
    // Next node in list
    SkipNode* next;

    // Constructors
    explicit SkipNode(const int32_t _levels) : levels(_levels), value(0){
      shortcut = new SkipNode*[levels];
    }

    SkipNode(const T& _value, const int32_t _levels)
        : levels(_levels), value(_value) {
      shortcut = new SkipNode*[levels];
    }

    // Copy-Constructor
    SkipNode(const SkipNode& other) : value(other.value), levels(other.levels) {
      SkipNode* shortcut[levels];
      for (int32_t i = 1; i <= levels; ++i) {
        shortcut[i] = other.shortcut[i];
      }
    }

    // Destructor
    ~SkipNode() { delete[] shortcut; }
  };

  // Maximum level in the skiplist
  int32_t maxLevel;
  // Total number of elements in the skiplist
  int32_t numElements;

 public:
  // The head of the skiplist
  SkipNode* first;

  /*
      Initialize the skiplist. A head "template" can be set. This should be
      a value that will not appear in the skiplist . Also, the maximum size
      of the skiplist can be set.
  */
  explicit SkipList(const T& head = 0, const int32_t& maxSize = 1000)
      : maxLevel(ceil(log2(maxSize))), numElements(0) {
    first = new SkipNode(head, maxLevel);
    first->next = nullptr;
    for (int32_t i = 0; i < maxLevel; i++) {
      first->shortcut[i] = nullptr;
    }
  }

  // Destructor
  ~SkipList() {
    SkipNode* curr = first;
    SkipNode* next;
    int32_t count = 0;

    while (count < numElements + 1) {
      next = curr->next;
      delete curr;
      curr = next;
      count++;
    }
  }

  int32_t getCount() const { return numElements; }

  // Search for a node. Return a nullptr if it doesn't exist
  // The algorithm is explained in Readme
  SkipNode* Search(const T& value) {
    SkipNode* node = first;
    int32_t currLevel = maxLevel - 1;

    while (node->next) {
      if (node->value == value) {
        return node;
      }

      if (currLevel > 0) {
        if (node->shortcut[currLevel]) {
          if (node->shortcut[currLevel]->value > value) {
            currLevel--;
          } else if (node->shortcut[currLevel]->value < value) {
            node = node->shortcut[currLevel];
          } else {
            return node->shortcut[currLevel];
          }
        } else {
          currLevel--;
        }
      } else {
        if (node->next) {
          if (node->next->value < value) {
            node = node->next;
          } else if (node->next->value == value) {
            return node->next;
          } else {
            return nullptr;
          }
        } else {
          return nullptr;
        }
      }
    }
    return nullptr;
  }

  // Insert a value (element) in the skiplist
  void Insert(const T& value) {
    if (Search(value) == nullptr) {
      int32_t levels = 0;
      while (CoinFlip::flip() && levels < maxLevel) {
        levels++;
      }

      SkipNode* node = new SkipNode(value, levels);
      node->next = nullptr;
      for (int32_t i = 0; i < levels; i++) {
        node->shortcut[i] = nullptr;
      }

      // Search & Link on all shortcut levels
      // It searches on the top level, links there, then continues
      // the search on a lower level
      SkipNode* curr = first;
      for (int32_t i = levels - 1; i >= 0; i--) {
        while (curr->shortcut[i] != nullptr) {
          if (curr->shortcut[i]->value < value) {
            curr = curr->shortcut[i];
          } else {
            break;
          }
        }

        node->shortcut[i] = curr->shortcut[i];
        curr->shortcut[i] = node;
      }

      // Search on the bottom list
      while (curr->next != nullptr && curr->next->value < value) {
        curr = curr->next;
      }
      node->next = curr->next;
      curr->next = node;

      numElements++;
    }
  }

  // Print all data in the skiplist
  friend std::ostream& operator<<(std::ostream& output, const SkipList& list) {
    SkipNode* curr = list.first;
    int32_t count = 0;
    if (list.getCount() != 0) {
      curr = curr->next;
      while (count < list.getCount()) {
        output << curr->value << " ";
        curr = curr->next;
        count++;
      }
    } else {
      output << "Empty SkipList";
    }
    return output;
  }

  // Return the max level
  int32_t get_maxLevel() { return maxLevel; }
};

#endif  // HEADERS_SKIPLIST_H_
