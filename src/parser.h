#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

namespace bar {
	class memnode {
	public:
		memnode();
		~memnode();
		std::vector<short int> data;
	};
	void init();
	void assignMem(const char* s);
	void disposeMem(const char* s);
	memnode* findMem(const char* s);
	void parse(const char* s);
	void leave();
}

