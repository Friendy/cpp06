#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data data;
    data.data_int = 78;
    data.data_float = 89.09;
    data.data_str = "jjkkko";
    data.printme();
    Data *data1;
    uintptr_t ptr;
    ptr = Serializer::serialize(&data);
    std::cout << "converted: " << ptr << "\n";
    data1 = Serializer::deserialize(ptr);
    data1->printme();
    // std::cout << "orig" << &data << "\n";
   
    // std::cout << "back" << data1 << "\n";
    

}