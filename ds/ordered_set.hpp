// ORDER STATISTIC TREE ********************************************************

// Wrapper for the GNU order statstic tree.

// find_by_order: returns an iterator to the k-th (0-indexed) largest element
// order_of_key: count the number of items in the set that are strictly smaller
// insert: insert an element into the set

// Needed if you're using #define int long long
#undef int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

//Alias for order statistic tree, functor template argument for comparison
template<class T,class C=less<>>
using ordered_set = tree<T,null_type,C,rb_tree_tag,
	tree_order_statistics_node_update>;

#define int long long

// *****************************************************************************
