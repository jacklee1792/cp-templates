// FRACTION TYPE ************************************************************************

// typecast: get the floating point representation of the fraction
//   -> O(1)
// reduce: reduce the fraction to lowest terms
//   -> O(logn)
// reciprocate: reciprocate the fraction
//   -> O(1)
// add, subtract, divide, multiply
//  -> O(logn)
// compare
//  -> O(1)
// abs: take the absolute value of the fraction
//  -> O(1)

template<class T>
struct frac{
	T num,den;

	frac(T num=0,T den=1){this->num=num;this->den=den;reduce();}

	operator float() const {return (float)num/den;}
	operator double() const {return (double)num/den;}
	operator long double() const {return (long double)num/den;}

	void reduce(){T g=gcd(num,den);num/=g;den/=g;}
	frac operator-() const{return frac(-num,den);}
  	frac operator!() const{return frac(den,num);}

	frac& operator+=(const frac& ot){
		T nden=std::lcm(den,ot.den);
		num*=nden/den;num+=ot.num*(nden/ot.den);den=nden;
		reduce();
		return *this;
	}
	frac& operator-=(const frac& ot){return *this+=-ot;}
  	frac& operator*=(const frac& ot){num*=ot.num;den*=ot.den;reduce();return *this;}
  	frac& operator/=(const frac& ot){return *this*=!ot;}
  	
  	friend frac operator+(frac a,frac const b){return a+=b;}
  	friend frac operator-(frac a,frac const b){return a-=b;}
  	friend frac operator*(frac a,frac const b){return a*=b;}
  	friend frac operator/(frac a,frac const b){return a/=b;}

  	friend bool operator==(frac const& a,frac const& b){return a.num==b.num&&a.den==b.den;}
  	friend bool operator!=(frac const& a,frac const& b){return a.num!=b.num||a.den!=b.den;}
  	friend bool operator>(frac const& a,frac const& b){return (a-b).num>0;}
  	friend bool operator>=(frac const& a,frac const& b){return (a-b).num>=0;}
  	friend bool operator<(frac const& a,frac const& b){return (a-b).num<0;}
  	friend bool operator<=(frac const& a,frac const& b){return (a-b).num<=0;}

  	friend ostream& operator<<(ostream& o,frac const& f){return o<<f.num<<"/"<<f.den;}
};

template<class T>
frac<T> abs(frac<T> f){
	f.num=std::abs(f.num);
	return f;
}

// **************************************************************************************
