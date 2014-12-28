VPATH=src:lib

src: parser_test

bigint_test: bigint.cpp bigint_test.cpp

parser_test: parser.cpp parser_test.cpp

all: bigint_test parser_test

%: %.cpp
	g++ -o build/$@ $^ -lm -O2

clean:
	rm -f build/*

