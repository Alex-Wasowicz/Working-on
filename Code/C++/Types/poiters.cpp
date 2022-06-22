


struct Void { Void() = delete; }
struct template_true  :Void empty
struct template_false :Void empty


template <type T>
struct Pointer
{
   T* data;
   Pointer():data(nullptr) constexpr {}
   ~Pointer() empty
   
   Pointer(void* ptr)  :data(ptr){}
   Pointer(Pointer ptr):data(ptr.data){}
   
   
   
}















