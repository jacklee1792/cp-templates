// ROLLING HASH *************************************************************************

// make_ptps: make point power array from list of CT sets of points, mods, and size
//   -> O(size * CT)
// rhash: precalculate prefix hashess
//   -> O(size * CT)
// subhash: get subhash of a rhash struct
//   -> O(1)

template<class T,int CT=1>
struct rhash {
	array<vector<long long>,CT> pre;
	array<vector<long long>,CT> ptps;
	array<long long,CT> mods;
	rhash(T a,array<vector<long long>,CT> ptps,array<long long,CT> mods){
		for(int i=0;i<CT;i++){
			pre[i].resize(a.size());
			pre[i][0]=a[0];
			for(int j=1;j<(int)a.size();j++){
				pre[i][j]=a[j]*ptps[i][j]%mods[i];
				pre[i][j]=pre[i][j]+pre[i][j-1]%mods[i];
			}
		}
		this->ptps=ptps;
		this->mods=mods;
	}
	array<long long,CT> subhash(int l,int r){
		array<long long,CT> ret;
		for(int i=0;i<CT;i++){
			ret[i]=pre[i][r];
			if(l>0)ret[i]=((ret[i]-pre[i][l-1])%mods[i]+mods[i])%mods[i];
			ret[i]=ret[i]*ptps[i][ptps[i].size()-1-r]%mods[i];
		}
		return ret;
	}
};

template<int CT>
array<vector<long long>,CT> make_ptps(array<long long,CT> pts,array<long long,CT> mods,int sz){
	array<vector<long long>,CT> ptps;
	for(int i=0;i<CT;i++){
		ptps[i].resize(sz);
		ptps[i][0]=1;
		for(int j=1;j<sz;j++){
			ptps[i][j]=ptps[i][j-1]*pts[i]%mods[i];
		}
	}
	return ptps;
}

// POINT CHOICE: RANDOM AND ODD, MAX(A) < P < MOD
// MODULO CHOICE: 1000000123, 1000000321, 2147483647

// **************************************************************************************
