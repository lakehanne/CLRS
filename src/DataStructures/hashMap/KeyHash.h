static const int SLOT_SIZE = 128;

template <typename K>
struct KeyHash {
    unsigned long operator()(const K& key) const
    {
        return reinterpret_cast<unsigned long>(key) % SLOT_SIZE;
    }
};