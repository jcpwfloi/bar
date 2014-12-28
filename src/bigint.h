#include <vector>
#include <climits>
#include <cstring>
#include <cstdio>

namespace bar {
	class BigInt {
	public: 
		std::vector<int> data;
		bool flag;
		BigInt();
		~BigInt();
		BigInt(int x);
		BigInt(long long x);
		BigInt(const char* s);
		void maintain();
		void print();
		bool operator < (BigInt& x);
		bool operator > (BigInt& x);
		bool operator == (BigInt& x);
		bool operator <= (BigInt& x) { return !(*this > x); }
		bool operator >= (BigInt& x) { return !(*this < x); }
		BigInt operator + (BigInt& x);
		BigInt operator - (BigInt& x);
		BigInt operator * (BigInt& x);
		BigInt operator / (BigInt& x);
	};
	int comp(BigInt &a, BigInt &b);
	BigInt absAdd(BigInt &a, BigInt &b);
}
