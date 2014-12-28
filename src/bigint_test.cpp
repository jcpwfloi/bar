#include "bigint.h"
#include <cstdio>

using namespace bar;

int main() {
	BigInt a("11111");
	BigInt b("22222");
	(a + b).print();
	return 0;
}