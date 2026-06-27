class DynamicArray {

private:
    int* arr;
    int length;
    int capacity;

public:

    DynamicArray(int capacity) : capacity(capacity), length(0) {
        arr = new int[capacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (length == capacity) resize();
        arr[length++] = n;
    }

    int popback() {
        length -= 1;
        return arr[length];
    }

    void resize() {
        capacity *= 2;
        int* big = new int[capacity];
        for (int i = 0; i < length; i++) {
            big[i] = arr[i];
        }
        delete[] arr;
        arr = big;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};
