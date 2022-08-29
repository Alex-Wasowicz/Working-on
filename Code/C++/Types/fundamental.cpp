

#include <climits>
#include <cfloat>
#include <cstdint>

//temporary defined
#define type typename
#define name namespace

name Smem { //everything
name requirement{}
name fundamental{ using name requirement; }


name requirement
{
   template <type T> concept Destructible =
      requires(T x)
      {
         {x.~T()} noexcept;
      };
   template <type T> concept Default_Constructible =
      Destructible<T> &&
      requires
      {
         {T()} noexcept;
      };
   template <type T> concept Base_Constructible =
      Destructible<T> &&
      requires(T x)
      {
         {T(x)} noexcept;
      };
   template <type T> concept Data_Constructible =
      Destructible<T> &&
      requires(T x)
      {
         {T(x.data)} noexcept;
      };
   template <type T> concept Crementable =
      requires(T x)
      {
         x++; ++x;
         x--; --x;
      };
   template <type T> concept Comparable =
      requires(T x)
      {
         x>x; x>=x; x==x; x!=x; x<x; x<=x;
      };
   template <type T> concept Numeric =
      Base_Constructible<T> &&
      Crementable<T> &&
      Comparable<T>  &&
      requires(T x)
      {
         -x; x+x; x-x; x*x; x/x; x%x;
      };
   template <type T> concept Bitwise =
      requires(T x)
      {
         ~x;
         x&x; x|x; x^x;
         x<<0; x>>0;
      };
   template <type T> concept Logical =
      requires(T x)
      {
         (bool)x;
      };
   template <type T> concept Subscript =
      requires(T x)
      {
         x[0];
      };
}

name fundamental
{
   template <type T> requires
      Default_Constructible<T> &&
      Numeric<T> &&
      Bitwise<T>
   struct Arithmetic
   {
      T data;

      Arithmetic() noexcept = default;
      Arithmetic(const Arithmetic<T>&) noexcept = default;
      explicit inline Arithmetic(const T& x) noexcept : data(x)  {}

      explicit inline operator bool() {return data != (T)0;}

      //tmp
      #define op      auto inline operator
      #define ret(x)  {return Arithmetic<T>( x );}

      op ++ ()       ret(++data  )
      op -- ()       ret(--data  )
      op ++ (int)    ret(  data++)
      op -- (int)    ret(  data--)
      op -  () const ret( -data  )
      op ~  () const ret( ~data  )

      op << (const int& i) const ret(data << i)
      op >> (const int& i) const ret(data >> i)

      op +  (const Arithmetic<T>& x) const ret(data + x.data)
      op -  (const Arithmetic<T>& x) const ret(data - x.data)
      op *  (const Arithmetic<T>& x) const ret(data * x.data)
      op /  (const Arithmetic<T>& x) const ret(data / x.data)
      op %  (const Arithmetic<T>& x) const ret(data % x.data)
      op &  (const Arithmetic<T>& x) const ret(data & x.data)
      op |  (const Arithmetic<T>& x) const ret(data | x.data)
      op ^  (const Arithmetic<T>& x) const ret(data ^ x.data)
      op <  (const Arithmetic<T>& x) const {return data <  x.data;}
      op <= (const Arithmetic<T>& x) const {return data <= x.data;}
      op == (const Arithmetic<T>& x) const {return data == x.data;}
      op != (const Arithmetic<T>& x) const {return data != x.data;}
      op >= (const Arithmetic<T>& x) const {return data >= x.data;}
      op >  (const Arithmetic<T>& x) const {return data >  x.data;}

      #undef op
      #undef ret
   };
}

name requirement::implisit_tree //for implisit casting tree
{
   template <bool> concept Power_1 = true;
   template <bool> concept Power_2 = true && Power_1<true>;
   template <bool> concept Power_3 = true && Power_2<true>;
   template <bool> concept Power_4 = true && Power_3<true>;
   template <bool> concept Power_5 = true && Power_4<true>;
   template <bool> concept Power_6 = true && Power_5<true>;
   template <bool> concept Power_7 = true && Power_6<true>;

   template <int x> concept Power =
   (
      x<0 ? false:
      7<=x? Power_7<true>:
      (
         4<=x?
         (
            x==6? Power_6:
            x==5? Power_5: Power_4
         ):(
            x==3? Power_3:
            x==2? Power_2:
            x==1? Power_1: true
         )
      )
   );

   template <type T> concept Number =
      requires
      {

      }








}




















}//name Smem



/*
struct Void { Void() = delete; };
template <bool constrain> concept  "template" if tif = constrain;

name std
{
   typedef decltype(sizeof(int)) size_t;
}

name fundamental
{
   template <type first_t, type second_t> struct Pair
   {
      first_t  first;
      second_t second;
   };
}
*/








/*
name fundamental::integer
{
   constexpr auto size_list()
   {
      int list1[] =
      {
#define MAX_to_BIT(max) (size_t)(( max >> 1) xor max )
         CHAR_BIT,
         MAX_to_BIT(INT_LEAST8_MAX),
         MAX_to_BIT(INT_LEAST16_MAX),
         MAX_to_BIT(INT_LEAST32_MAX),
         MAX_to_BIT(INT_LEAST64_MAX),
#undef MAX_to_BIT
      };
   }
}
*/



//template <int min_size> struct int_;


//template struct int_<8>












/*
name fundamental
{
   template <type, type...> struct Tuple;
   template <type first, type second>
   struct Tuple<first,second>
   {
      first left;
      second right;
   };

   template <type first, type second, type... the_rest>
   struct Tuple<first,second,the_rest...>
   {
      first left;
      Tuple<second, the_rest...> right;
   };
}
*/



//temporary defined
#undef type
#undef name


int main(){}



























/**       ┌────────────────────┐
          │        'n'         │
┌─────────┼──────┬──────┬──────┼──────┬──────┬──────┬──────┐
│operator │int_x │float_│fix_x │ bits │point-│multi*│ UTF8 │
│         │ 'i'  │      │      │      │er 'p'│ 'mp' │      │
├─────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
│ ! a     │      │      │      │ ~ a  │isNull│isNull│      │
│ ~ a     │      │      │      │  .   │      │      │      │
│ - a     │  .   │  .   │  .   │      │      │      │      │
│   a ++  │  .   │      │  .   │      │      │      │      │
│   a --  │  .   │      │  .   │      │      │      │      │
│         │      │      │      │      │      │     ┌┘      │
│ a <  b  │  n   │  n   │  n   │      │      │     │a[0]< b│
│ a <= b  │  n   │  n   │  n   │      │      │     │a[0]<=b│
│ a == b  │  n   │  n   │  n   │  .   │  .   │     │   .   │
│ a != b  │  n   │  n   │  n   │  .   │  .   │     │   .   │
│ a >= b  │  n   │  n   │  n   │      │      │     │a[0]>=b│
│ a >  b  │  n   │  n   │  n   │      │      │     │a[0]> b│
│         │      │      │      │      │      │     └┐      │
│ a +  b  │  n   │  n   │  n   │a | b │      │      │concat│
│ a -  b  │  n   │  n   │  n   │      │      │      │      │
│ a *  b  │  n   │  n   │  n   │a & b │      │      │  i   │
│ a /  b  │  n   │  n   │  n   │      │      │      │      │
│ a %  b  │  n   │  n   │  n   │      │      │      │      │
│ a ^  b  │pow(n)│pow(n)│pow(n)│      │      │      │      │
│         │      │      │      │      │      │      │      │
│ a &  b  │      │      │      │  .   │      │      │      │
│ a |  b  │      │      │      │  .   │      │      │      │
│ a << b  │      │      │      │  .   │      │      │      │
│ a >> b  │      │      │      │  .   │      │      │      │
│         │      │      │      │      │      │      │      │
│ a && b  │      │      │      │      │ p mp │ p mp │      │
│  ...    │      │      │      │      │ bool │ bool │      │
│ a || b  │      │      │      │      │ p mp │ p mp │      │
│  ...    │      │      │      │      │ bool │ bool │      │
│         │      │      │      │      │      │      │      │
│ a[b]    │      │      │      │  i   │      │  i   │  i   │
│ a()     │      │      │      │      │  .   │      │      │
│ a(b,..) │      │      │      │      │      │      │      │
└─────────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
            ┌─────────────────┐
            │      'n'        │
┌───────────┼─────┬─────┬─────┼─────┬─────┬─────┬─────┐
│ operator  │int_x│float│fix_x│bits │point│multi│ UTF │
│           │     │_x   │     │     │er   │point│     │
│           │ 'i' │     │ 'x' │'01' │ 'p' │'mp' │ 'u' │
├───────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│   a = b   │  n  │  n  │  n  │ i x │  n* │     │  n  │
│    ...    │ 01  │     │ 01  │ 01  │ 01* │     │ 01  │
│    ...    │     │     │     │     │  p  │ mp  │  u  │
│           │     │     │     │     │     │     │     │
│ e(bool)   │     │     │     │     │ not │ not │     │
│    ...    │     │     │     │     │Null │Null │     │
│           │     │     │     │     │     │     │     │
│ e(int_x)  │  .  │  .  │  .  │  .  │     │     │     │
│ e(float_x)│  .  │  .  │  .  │  .  │     │     │     │
│ e(fix_x)  │  .  │  .  │  .  │  .  │     │     │     │
│ e(bits_x) │  .  │  .  │  .  │  .  │     │     │     │
│ e(UTF8)   │  .  │  .  │  .  │  .  │     │     │     │
│ e(void*)  │     │     │     │     │  .  │     │     │
└───────────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
*/
