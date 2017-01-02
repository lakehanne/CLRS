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

// Hash node class template
#include <memory>

template <typename K, typename V>
class HashNode {
private:
    // key-value pair
    K key;
    V value;
    // next bucket with the same key
    std::unique_ptr<HashNode> next;

public:
    HashNode(K&& key, V&& value) :
    key(key), value(value), next(nullptr) {
    }
 
    K getKey() const 
    {
        return key;
    }
 
    V getValue() const 
    {
        return value;
    }
 
    void setValue(V value) 
    {
        this->value = value;
    }
 
    std::unique_ptr<HashNode> getNext() const 
    {
        return next;
    }
 
    void setNext(std::unique_ptr<HashNode> next) 
    {
        this->next = next;
    }
};