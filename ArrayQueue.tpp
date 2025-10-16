template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
    this->length = 0;
    maxSize = i;
    buffer = new T[maxSize];
    backIndex = 0;
    frontIndex = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    return *buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    frontIndex = 0;
    backIndex = 0;
    for (int i = 0; i < maxSize; i++) {
        *buffer[i] = NULL;
    }
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    buffer = copyObj.buffer;
    maxSize = copyObj.getMaxSize();
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;
    // TODO
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    *buffer[frontIndex] = NULL;
    if (frontIndex < maxSize - 1) {frontIndex++;} else {frontIndex = 0;};
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if (backIndex < maxSize - 1) {backIndex++;} else {backIndex = 0;};
    *buffer[backIndex] = elem;
}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
