#include "bigint.h"

bar::BigInt::BigInt(long long x) {
	if (x < 0) flag = 1, x = -x;
	for (; x; x /= 1000) this -> data.push_back(x % 1000);
}

bar::BigInt::BigInt(int x) {
	if (x < 0) flag = 1, x = -x;
	for (; x; x /= 1000) this -> data.push_back(x % 1000);
}

bar::BigInt::BigInt(const char* s) {
	int len = strlen(s), temp, st;
	if ((int)this -> data.size()) {
		this -> data.clear();
		this -> data.resize((len / 3) + 2);
	}
	if (s[0] == '-') flag = false, st = 2; else flag = true, st = 1;
	for (int i = len; i >= st; i -= 3) {
		//printf("DEBUG: i %d\n", i);
		temp = 0;
		for (int j = 3; j > 0; -- j) {
			if (!(i - j >= st - 1)) continue;
			temp = temp * 10 + (s[i - j] - '0');
		}
		this -> data.push_back(temp);
	}
	//for (int i = 0; i < this -> data.size(); ++ i) printf("%d\n", this -> data[i]);
}

bar::BigInt::~BigInt() {
	if ((int)this -> data.size()) {
		this -> data.clear();
		this -> data.resize(0);
	}
}

bar::BigInt::BigInt() {
	if ((int)this -> data.size()) {
		this -> data.clear();
		this -> data.resize(0);
	}
}

void bar::BigInt::maintain() {
	std::vector<int>::iterator i = this -> data.begin();
	int res;
	while (i != this -> data.end()) {
		res = *i / 1000;
		*i %= 1000;
		if (res) {
			if (i == this -> data.end()) {
				this -> data.push_back(res);
			} else {
				++ i;
				*i += res;
				continue;
			}
		}
		++ i;
	}
}

void bar::BigInt::print() {
	if (!this -> data.size()) {
		puts("0");
		return;
	}
	std::vector<int>::iterator i = this -> data.end();
	-- i;
	printf("%d", *i);
	while (i != this -> data.begin()) {
		-- i;
		printf("%03d", *i);
	}
	puts("");
}

int bar::comp(BigInt &a, BigInt &b) {
	if ((int)a.data.size() < (int)b.data.size()) return -1;
	if ((int)a.data.size() > (int)b.data.size()) return 1;
	for (int i = 0; i < (int)a.data.size(); ++ i) {
		if (a.data[i] < b.data[i]) return -1;
		if (a.data[i] > b.data[i]) return 1;
	}
	return 0;
}

bool bar::BigInt::operator < (bar::BigInt &x) {
	if (this -> flag && x.flag) return bar::comp(*this, x) == -1;
	if (!this -> flag && !x.flag) return bar::comp(*this, x) == 1;
	if (!this -> flag && x.flag) return true;
	if (this -> flag && !x.flag) return false;
	return false;
}

bool bar::BigInt::operator > (bar::BigInt &x) {
	if (this -> flag && x.flag) return bar::comp(*this, x) == 1;
	if (!this -> flag && !x.flag) return bar::comp(*this, x) == -1;
	if (!this -> flag && x.flag) return false;
	if (this -> flag && !x.flag) return true;
	return false;
}

bool bar::BigInt::operator == (bar::BigInt &x) {
	return bar::comp(*this, x) == 0;
}

//TODO have the flag processed
bar::BigInt bar::BigInt::operator + (bar::BigInt &x) {
	bar::BigInt ans;
	int data1, data2;
	for (int i = 0; i < std::max((int)this -> data.size(), (int)x.data.size()); ++ i) {
		if (i < (int)this -> data.size()) data1 = this -> data[i]; else data1 = 0;
		if (i < (int)x.data.size()) data2 = x.data[i]; else data2 = 0;
		//printf("%d, %d, %d\n", i, data1, data2);
		ans.data.push_back(data1 + data2);
	}
	ans.maintain();
	return ans;
}

bar::BigInt bar::BigInt::operator - (bar::BigInt &x) {
	return BigInt(1LL * 0);
}

