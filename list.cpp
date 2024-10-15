#include <iostream>


class DinamicArr {

    public:
    size_t capacity;
    size_t size;
    double* arr;
    static const size_t initial_capacity=2;

    DinamicArr() { //constructor
        capacity = initial_capacity;
        size=0;
        arr=new double[capacity];
    };

    DinamicArr(size_t size_, double elem) {
        size=size_;
        arr=new double[size_];
        for (int i=0; i<size ;++i) {
            arr[i]=elem;
        }
    };

    DinamicArr(const DinamicArr& rhs) {
        size=rhs.size;
        capacity=rhs.capacity;
        arr= new double[capacity];
        for (int i=0;i<size;++i) {
            arr[i]=rhs.arr[i];
        }
    };

    double operator[](int index){
        if (index < 0 || index >= size){
            return 0;
        }
        return arr[index];
    };


    DinamicArr& operator=(const DinamicArr& rhs){
        if (this == &rhs){
            return *this;
        }
        delete [] arr;
        size = rhs.size;
        capacity = rhs.capacity;
        arr = new double [capacity];
        for (int i = 0; i < size; ++i){
            arr[i] = rhs.arr[i];
        }
        return *this;
    };
    ~DinamicArr() { // destructor
        delete[] arr;
    };
    
    void push_back (double l) {
        if (capacity==size) {
            capacity =2;
            double* arr_new=new double[capacity];
            for(int i=0;i<size;++i) {
                arr_new[i]=arr[i];
            }
            delete[] arr;
            arr=arr_new;
        }
        arr[size]=l;
    };

};


int main() {
    system("chcp 65001");
	DinamicArr arr1, arr2(4,3);
	DinamicArr arr3(arr1);
	std::cout << arr2.size << std::endl;
	for (size_t i = 0; i < 3; ++i) {
		arr3.push_back(i);
	}
    std::cout << arr3.size << std::endl;
    return 0;
}