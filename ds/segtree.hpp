// SEGMENT TREE ****************************************************************

// Supports 1D point update/range query in O(log n).

template<class T,class Func=plus<>,T Identity=0>
class segtree{
	vector<T> _t;
	void _set(size_t pos,T val,size_t v,size_t tl,size_t tr){
		if(tl==tr)_t[v]=val;
		else{
			size_t tm=(tl+tr)>>1;
			if(pos<=tm)_set(pos,val,v<<1,tl,tm);
			else _set(pos,val,v<<1|1,tm+1,tr);
			_t[v]=Func{}(_t[v<<1],_t[v<<1|1]);
		}
	}
	T _query(size_t l,size_t r,size_t v,size_t tl,size_t tr){
		if(tl>r||tr<l)return Identity;
		if(l<=tl&&tr<=r)return _t[v];
		size_t tm=(tl+tr)>>1;
		return Func{}(_query(l,r,v<<1,tl,tm),_query(l,r,v<<1|1,tm+1,tr));
	}
public:
	segtree(size_t n):_t(vector<T>(n<<2,Identity)){}
	void set(size_t pos,size_t val){
		_set(pos,val,1,0,(_t.size()>>2)-1);
	}
	T query(size_t l,size_t r){
		return _query(l,r,1,0,(_t.size()>>2)-1);
	}
	class reference{
	segtree& _st;
	size_t _pos;
	public:
		reference(segtree& st,size_t pos):_st(st),_pos(pos){}
		reference& operator=(T val)&&{_st.set(_pos,val);return *this;}
		reference& operator+=(T val)&&{_st.set(_pos,_st[_pos]+val);return *this;}
		reference& operator-=(T val)&&{_st.set(_pos,_st[_pos]-val);return *this;}
		reference& operator*=(T val)&&{_st.set(_pos,_st[_pos]*val);return *this;}
		reference& operator/=(T val)&&{_st.set(_pos,_st[_pos]/val);return *this;}
		reference& operator++(signed)&&{_st.set(_pos,_st[_pos]+1);return *this;}
		reference& operator--(signed)&&{_st.set(_pos,_st[_pos]-1);return *this;}
		operator T()&&{return _st.query(_pos,_pos);}
	};
	reference operator[](size_t pos){
		return reference(*this,pos);
	}
};

// *****************************************************************************
