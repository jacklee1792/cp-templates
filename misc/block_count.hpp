// BLOCK COUNT *****************************************************************

// Count the minimum number of contiguous blocks an iterable needs to be
// divided into such that for all blocks, the elements in them are the same
// Optionally takes a function cmp, which evaluates if two elements are equal

template<class Iter,class Func>
int block_count(Iter first,Iter last,Func cmp){
	int ret=0;
	for(auto it=first;it!=last;it++){
		if(it==first||!cmp(*it,*prev(it)))ret++;
	}
	return ret;
}

template<class Iter,class Func>
int block_count(Iter first,Iter last,Func& cmp){
	int ret=0;
	for(auto it=first;it!=last;it++){
		if(it==first||!cmp(*it,*prev(it)))ret++;
	}
	return ret;
}

template<class Iter>
int block_count(Iter first,Iter last){
	return block_count(first,last,[](auto x,auto y){
		return x==y;
	});
}

// *****************************************************************************
