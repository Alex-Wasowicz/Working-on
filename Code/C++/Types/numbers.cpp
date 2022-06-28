
#include <climits>

//temporary defined
#define type typename
#define name namespace

struct Void { Void() = delete; };
template <bool constrain> concept tif = constrain; //template_if "tif"
template <type...> struct Glue;

struct  int_8; //sizes in at least units!
struct uint_8;
struct  int_16;
struct uint_16;
struct  int_32;
struct uint_32;
struct  int_64;
struct uint_64;
struct  int_128;
struct uint_128;
template <type> struct int_from;
template <uint_16 size> struct int_x;
template <type, type> struct int_glued;

struct float_16; //half
struct float_32; //float
struct float_64; //double
struct float_128;//quadruple
struct base_30;  //from 0 to 1 in 5 digits of base 30 (30=0b1'1110=2*3*5) 32 bits
template <uint_16 point, type size> struct fixed;
template <uint_16 exponent, uint_16 mantissa> struct float_x;

template <type base> struct int_from
{
    base;
};

#undef type
#undef name


