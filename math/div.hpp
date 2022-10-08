// DIVISION TOOLS **************************************************************

// Various tools to make division-related operations easier.

// mod:  returns the value of x mod m, works for negative x too
// fdiv: calculate floor(x,y), works for all integers
// cdiv: calculate ceil(x,y), works for all integers
// drop: calculate nearest multiple of y less than or equal to x
// lift: calculate nearest multiple of y greater than or equal to x

template<class T>
T mod(T x,T m){return (x%m+m)%m;}
template<class T>
T fdiv(T x,T y){return x/y-((x^y)<0&&x%y);}
template<class T>
T cdiv(T x,T y){return x/y+((x^y)>0&&x%y);}
template<class T>
T drop(T x,T y){y=abs(y);return fdiv(x,y)*y;}
template<class T>
T lift(T x,T y){y=abs(y);return cdiv(x,y)*y;}

// *****************************************************************************
