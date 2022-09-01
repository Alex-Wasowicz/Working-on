
/*
User def. Promotion is posible in C++20

Before I start, I want to specify what I mean.
I mean Promotion like "Numeric Promotion" in Java...
In C++ this is "Numeric Promotion":
*/

void fun(char x);
void fun(long x);

int main(){
   fun(5); //error ambiguous
}
/*
All promotions in c++ are to int, axcept float to double.
Both casts are "Integral Conversion", int to long is not a "Numeric Promotion"
*/














template <bool T = true> concept Force_0 = T;
template <bool T = true> concept Force_1 = Force_0<T>;
template <bool T = true> concept Force_2 = Force_1<T>;
template <bool T = true> concept Force_3 = Force_2<T>;

template <int T> concept Force_0 = 
   (T<0)? false:
   (T>3)? Force_3:
   (T==0)? true:
   (T==1)? Force_0:
   (T==2)? Force_1:
   Force_2;

template <typename T> class Box : T
{
   template <typename T2> operator T2(const &T) = delete;
}



int main()
{
   
}



