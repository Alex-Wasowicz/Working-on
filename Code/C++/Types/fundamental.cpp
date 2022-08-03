

#include <climits>
#include <cfloat>
#include <cstdint>

//temporary defined
#define type typename
#define name namespace
#define noex noexcept

struct Void { Void() = delete; };
template <bool constrain> concept /*template_if*/tif = constrain;

name std
{
   typedef decltype(sizeof(int)) size_t;
   typedef decltype(nullptr) nullptr_t;
}

//#define bitsizeof(x) (sizeof(x)*(size_t)CHAR_BIT)

name fundamental
{
   template <type _1st_type, type _2nd_type> struct Pair
   {
      _1st_type _1st;
      _2nd_type _2nd;
   };
}

#if



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
