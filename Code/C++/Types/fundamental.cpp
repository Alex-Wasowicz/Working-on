

#include <climits>
#include <cfloat>
#include <cstdint>

//temporary defined
#define type typename
#define name namespace
#define noex noexcept

struct Void { Void() = delete; };
template <bool constrain> concept /* "template" if */tif = constrain;

name std
{
   typedef decltype(sizeof(int)) size_t;
}

name fundamental
{
   template <type _1st_t, type _2nd_t> struct Pair
   {
      _1st_t _1st;
      _2nd_t _2nd;
   };
   
   //#if ( CHAR_BIT == sizeof(int_least8_t) )
      typedef int_least8_t byte;
   //#else
   //   #include "byte.cpp"
   //#endif
   
   enum type_category :byte
   { unknown = 0, integer, exact, floating, quantum };
   
   template <type T>
   constexpr byte type_category() {return unknown;}
   
   #define bitsizeof(T) (CHAR_BIT * sizeof(T))
   
   name ForceNambers
   {
      template <bool> concept Zero  =       true;
      template <bool> concept One   = Zero <true>;
      template <bool> concept Two   = One  <true>;
      template <bool> concept Three = Two  <true>;
      template <bool> concept Four  = Three<true>;
      template <bool> concept Five  = Four <true>;
      template <bool> concept Six   = Five <true>;
      template <bool> concept Seven = Six  <true>;
      
      template <int> struct alias;
      template <> struct alias<0> { using it = Zero <true> };
      template <> struct alias<1> { using it = One  <true> };
      template <> struct alias<2> { using it = Two  <true> };
      template <> struct alias<3> { using it = Three<true> };
      template <> struct alias<4> { using it = Four <true> };
      template <> struct alias<5> { using it = Five <true> };
      template <> struct alias<6> { using it = Six  <true> };
      template <> struct alias<7> { using it = Seven<true> };
   }
   template <int x> using ForceNamber = ForceNambers::alias<x>::it;
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   template <type T> concept Arithetic_compatible = requires(T x)
   {
      {T()}; {T(x)};
      {x++}; {++x}; {x--}; {--x};
      {-x};  {x+x}; {x-x}; {x*x}; {x/x}; {x%x};
      {~x};  {x^x}; {x&x}; {x|x};
      {x>x}; {x>=x}; {x==x}; {x!=x}; {x<x}; {x<=x};
   };

   template <Arithetic_compatible T> struct Arithmetic
   {
      T data;
      
      Arithmetic() = default;
      Arithmetic(const Arithmetic<T>&) = default;
      explicit inline Arithmetic(const T& x): data(x) {} 
      
      auto inline operator++ ()    {return Arithmetic<T>(++data);}
      auto inline operator-- ()    {return Arithmetic<T>(--data);}
      auto inline operator++ (int) {return Arithmetic<T>(data++);}
      auto inline operator-- (int) {return Arithmetic<T>(data--);}
      
      auto inline operator+ () const {return Arithmetic<T>( data);}
      auto inline operator- () const {return Arithmetic<T>(-data);}
      
      #define tmp(OP) \
      auto inline operator OP (const Arithmetic<T>& x) const \
      { return Arithmetic<T>(data OP x.data); }
      
      tmp( + )
      tmp( - )
      tmp( * )
      tmp( / )
      tmp( % )
      
      auto inline operator~ () const {return Arithmetic<T>(~data);}
      tmp( ^ )
      tmp( & )
      tmp( | )
      tmp( << )
      tmp( >> )
      
      #undef tmp
      #define tmp(OP) \
      bool inline operator OP (const Arithmetic<T>& x) const \
      { return (data OP x.data); }
      
      tmp( <  )
      tmp( <= )
      tmp( == )
      tmp( != )
      tmp( >= )
      tmp( >  )
      
      #undef tmp
      
   };
}



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
#undef noex






























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
