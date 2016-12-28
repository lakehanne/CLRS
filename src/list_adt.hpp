
//List Abstract Design Template
template<typename T>
class List{
public:
	List(){};	//Default Constructor
	virtual ~List(){}	//Base Destructor

	//delete copy constructors and copy assignment operator based on c++11 
	List(const List&) = delete;
	List& operator=(const List&) = delete;

	virtual void clear() = 0; //clear list contents
	virtual void insert(const T& elem) = 0; //insert an element at the current location
	virtual void append(const T& elem) = 0; // append an element to the list
	virtual T remove() = 0;  //remove and return the current element
	virtual void begin() = 0;  //set the current position to start of the list
	virtual void end() = 0; //set the current position to the end of the list
	virtual void prev() = 0; //move the current position one step left
	virtual void next() = 0; //move the current position one step to the right
	virtual int size() const = 0; //return the number of elements in the list
	virtual int currPos() const = 0; //return the current position in the list
	virtual void setPos(int pos) = 0; //set the current position to pos
	virtual const T& getCurElem() = 0; //get the current element
};