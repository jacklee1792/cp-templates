// Z-FUNCTION ******************************************************************

// Return a vector z such that for all i, z[i] = LCP(a[0...], a[i...])
// Uses z[0] = 0

template<class Iter>
vector<int> zfunc(Iter first,Iter last){
	int n=distance(first,last);
	vector<typename iterator_traits<Iter>::value_type> a(n);
	vector<int> z(n);
	for(int i=0;i<n;i++){
		a[i]=*(first++);
	}
	int l=0,r=0;
	for(int i=1;i<n;i++){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&a[z[i]]==a[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}

// *****************************************************************************
