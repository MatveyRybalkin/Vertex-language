#ifndef VBASE_H_INCLUDED
#define VBASE_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

//defines
#define INFINITY_LOOP 1
#define loop() while(1)
#define setup() int main()
#define end() return 0
#define end_loop() break
#define byte unsigned char

//defines math
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define EULER 2.718281828459045235360287471352

#define DegToRad(a) a * 0.017453292519943295769236907684886
#define RadToDeg(a) a * 57.295779513082320876798154814105

#define cos_deg(a) cos(a * 0.017453292519943295769236907684886)
#define sin_deg(a) sin(a * 0.017453292519943295769236907684886)
#define tan_deg(a) tan(a * 0.017453292519943295769236907684886)
#define cotan_deg(a) 1/tan(a * 0.017453292519943295769236907684886)

//Python
#define type(data) (sizeof(data) == 1?"<char>":sizeof(data) == 2?"<short>":sizeof(data) == 4?"<int>":sizeof(data) == 8?"<long long>":"<another>")
#define len(data) sizeof(data) / sizeof(data[0])

long double Pow(long double a, long double power){
    return power == 1 ? a : a * Pow(a, power - 1);
}

long long Sum(long long n, ...){
    long long s = 0;
    for(long long *ptr = &n; n>=0; n--){
        s += *(++ptr);
    }
    return s;
}

long long Max(long long n, ...){
    long long mx = LONG_LONG_MIN;
    for(long long *ptr = &n; n>=0; n--){
        if(*(++ptr) > mx){
            mx = *ptr;
        }
    }
    return mx;
}

long long MaxM(long long *input) {
	long long mx = LONG_LONG_MIN;
	long long l = len(input);
	for (long long i = 0; i < l; ++i) {
		if (mx > input[i]) {
			mx = input[i];
		}
	}
	return mx;
}

long long Min(long long n, ...){
    long long mn = LONG_LONG_MAX;
    for(long long *ptr = &n; n>=0; n--){
        if(*(++ptr) < mn){
            mn = *ptr;
        }
    }
    return mn;
}

long long MinM(long long *input) {
	long long mn = LONG_LONG_MIN;
	long long l = len(input);
	for (long long i = 0; i < l; ++i) {
		if (mn < input[i]) {
			mn = input[i];
		}
	}
	return mn;
}


#ifdef __cplusplus
// vchar class
class vchar{
	protected:
	unsigned char _data;
	public:
	void setbit(unsigned char adr, bool data){
		if(data == true){
			_data |= (1 << adr);
			}else{
			_data &= ~(1 << adr);
		}
	}
	bool getbit(unsigned char adr){
		return (_data & 1 << adr);
	}
};

#endif

#endif // VBASE_H_INCLUDED
