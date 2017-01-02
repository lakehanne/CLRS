static const int SLOT_SIZE = 128;

// Default hash function class
template <typename K>
struct KeyHash 
{
    unsigned long operator()(K&& key) const
    {
        return reinterpret_cast<unsigned long>(key) % SLOT_SIZE;
    }
};