// RANDOM UTILITIES ************************************************************

// rint: generate a random integer between lo and hi, inclusive
// rreal: generate a random real number between lo and hi, inclusive

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
T rint(T lo,T hi){return uniform_int_distribution<T>(lo,hi)(rng);}
template<class T>
T rreal(T lo,T hi){return uniform_real_distribution<T>(lo,hi)(rng);}

// *****************************************************************************
