// Hash node class template
template <typename K, typename V>
class HashNode {
private:
    // key-value pair
    K key;
    V value;
    // next bucket with the same key
    HashNode *next;
public:
    HashNode(const K& key, const V& value) :
    key(key), value(value), next(nullptr) {
    }

    K getKey() const {
        return key;
    }

    V getValue() const {
        return value;
    }

    void setValue(V value) {
        HashNode::value = value;
    }

    HashNode *getNext() const {
        return next;
    }

    void setNext(HashNode *next) {
        HashNode::next = next;
    }
};