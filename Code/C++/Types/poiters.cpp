


struct Void
{
   Void() = delete;
};

template <bool constrain>
concept template_if = constrain; //C++20




template <type T>
struct Pointer
{
   T* data;
   Pointer():data(nullptr) constexpr {}
   ~Pointer() empty
   
   Pointer(void* ptr)  :data(ptr){}
   Pointer(Pointer ptr):data(ptr.data){}
   
   
   
}















