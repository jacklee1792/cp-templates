// MODULAR TYPE ****************************************************************

// Class to deal with arithmetic under a given modulo. Most operations work in
// O(1), with the exception of division which works in O(log A)

template<class T,T MOD>
struct modular{
	T val;

	modular(T x=0){val=x%MOD;if(val<0)val+=MOD;}
	modular(T a,T b):val(0){*this+=a;*this/=b;}

	modular& operator+=(modular const& b){
		val+=b.val;if(val>=MOD)val-=MOD;return *this;
	}
	modular& operator-=(modular const& b){
		val-=b.val;if(val<0)val+=MOD;return *this;
	}
	modular& operator*=(modular const& b){
		val=(long long)val*b.val%MOD;return *this;
	}
  
	friend modular mpow(modular a,long long x){
		modular ret=1;while(x){if(x&1)ret*=a;a*=a;x>>=1;}
		return ret;
	}
	friend modular inv(modular a){return mpow(a,MOD-2);}
	modular& operator/=(modular const& b){return *this*=inv(b);}
  
	friend modular operator+(modular a,modular const b){return a+=b;}
	friend modular operator-(modular a,modular const b){return a-=b;}
	friend modular operator-(modular const a){return 0-a;}
	friend modular operator*(modular a,modular const b){return a*=b;}
	friend modular operator/(modular a,modular const b){return a/=b;}
	friend ostream& operator<<(ostream& o,modular const& a){return o<<a.val;}
	friend bool operator==(modular const& a,modular const& b){
		return a.val==b.val;
	}
	friend bool operator!=(modular const& a,modular const& b){
		return a.val!=b.val;
	}
};

// Change as necessary
const int M=1000000007;
using mint=modular<int,M>;

// *****************************************************************************
