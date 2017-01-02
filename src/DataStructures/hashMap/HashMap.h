/*  
*  Copyright December 2016
*  Author: Olalekan P. Ogunmolu
*
* Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* 
* See the License for the specific language governing permissions and
* limitations under the License.
* 
*/

#include "HashNode.h"
#include "KeyHash.h"

// Hash map class template
template <typename K, typename V, typename Func = KeyHash<K> >
class HashMap 
{
private:
    // hash slot
    // std::unique_ptr<<K, V>[]> slot;
    HashNode<K, V>** slot;
    Func hashFunc;
public:
    HashMap() {
        // construct zero initialized hash slot of size
        slot = new HashNode<K, V> *[SLOT_SIZE]();
        // slot = new HashNode<K, V>[SLOT_SIZE]();
    }

    ~HashMap() {
        // destroy all buckets one by one
        for (int i = 0; i < SLOT_SIZE; ++i) {            
            // std::unique_ptr<HashNode<K,V>> elem = slot[i];
            HashNode<K, V> *elem = slot[i];
            while (elem != nullptr) {
                // std::unique_ptr<HashNode<K, V>> prev = elem;
                HashNode<K, V> *prev = elem;
                elem = elem->getNext();
                delete prev;
            }
            slot[i] = nullptr;
        }
        // destroy the hash slot
        delete [] slot;
    }

    bool get(K&& key, V &value) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *elem = slot[hashValue];
        // std::unique_ptr<HashNode<K, V>> elem = slot[hashValue];

        while (elem != nullptr) 
        {
            if (elem->getKey() == key) 
            {
                value = elem->getValue();
                return true;
            }
            elem = elem->getNext();
        }
        return false;
    }

    void put(K&& key, V&& value) 
    {
        unsigned long hashValue = hashFunc(key);
        // std::unique_ptr<HashNode<K, V>> prev = nullptr;
        HashNode<K, V> *prev = nullptr;
        HashNode<K, V> *elem = slot[hashValue];
        // std::unique_ptr<K, V> elem = slot[hashValue];

        while (elem != nullptr && elem->getKey() != key) 
        {
            prev = elem;
            elem = elem->getNext();
        }

        if (elem == nullptr) {
            // std::unique_ptr<HashNode<K, V>(key, value)> elem;
            elem = new HashNode<K, V>(key, value);
            if (prev == nullptr) {
                // insert as first bucket
                slot[hashValue] = elem;
            } else {
                prev->setNext(elem);
            }
        } else {
            // just update the value
            elem->setValue(value);
        }
    }

    void remove(const K &key) {
        unsigned long hashValue = hashFunc(key);
        // std::unique_ptr<HashNode<K, V> > prev = nullptr;
        HashNode<K, V> *prev = nullptr;
        // std::unique_ptr<HashNode<K, V> > elem = slot[hashValue];
        HashNode<K, V> *elem = slot[hashValue];

        while (elem != nullptr && elem->getKey() != key) {
            prev = elem;
            elem = elem->getNext();
        }

        if (elem == nullptr) {
            // key not found
            return;
        }
        else {
            if (prev == nullptr) {
                // remove first bucket of the list
                slot[hashValue] = elem->getNext();
            } else {
                prev->setNext(elem->getNext());
            }
            delete elem;
        }
    }
};
