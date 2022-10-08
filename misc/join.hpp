// JOIN FUNCTION ***************************************************************

// Function which converts an iterable range into a string. Takes 4 forms:
// join(Iter begin, Iter end, string delim, Functor fmt)
// join(Iter begin, Iter end, string delim)
// join(Iter begin, Iter end, Functor fmt)
// join(Iter begin, Iter end)

template<class IterType,class Functor>
string join(IterType begin,IterType end,string delim,Functor fmt){
	stringstream ret;
	for(auto it=begin;it!=end;it++){
		if(it!=begin)ret<<delim;
		ret<<fmt(*it);
	}
	return ret.str();
}
template<class IterType,class T>
string join(IterType begin,IterType end,T third_arg){
	if constexpr(is_same_v<T,string>||is_same_v<T,const char*>) {
		using U=typename iterator_traits<IterType>::value_type;
		return join(begin,end,third_arg,[](U x){return x;});
	}
	else{
		return join(begin,end," ",third_arg);
	}
}
template<class IterType>
string join(IterType begin,IterType end){
	using T=typename iterator_traits<IterType>::value_type;
	return join(begin,end," ",[](T x){return x;});
}

// *****************************************************************************
