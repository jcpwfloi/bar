#include "parser.h"

bar::memnode *mem;

#ifndef BAR_INIT_MEM
	#define BAR_INIT_MEM 1024
#endif

void bar::init() {
	mem = NULL;
}

#undef BAR_INIT_MEM

void bar::assignMem(const char* s) {
}

void bar::disposeMem(const char* s) {
}

bar::memnode* findMem(const char* s) {
	return NULL;
}

void bar::parse(const char* s) {
}
