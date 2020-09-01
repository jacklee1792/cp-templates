// DIVISION TOOLS ***********************************************************************

// mod: returns the value of x mod m, works for all integers
//   -> O(1)
// fdiv: calculate floor(x,y), works for all integers
//   -> O(1)
// cdiv: calculate ceil(x,y), works for all integers
//   -> O(1)
// cdiv0: calculate ceil(x/y) for positive x/y, faster
//   -> O(1)

template<class T>
T mod(T x,T m){return (x%m+m)%m;}
template<class T>
T fdiv(T x,T y){return (x-((x%y+y)%y))/y;}
template<class T>
T cdiv(T x,T y){return -fdiv(-x,y);}
template<class T>
T cdiv0(T x,T y){return (x+y-1)/y;}

// **************************************************************************************
