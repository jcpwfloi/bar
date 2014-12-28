VPATH=src:lib

src: bigint_test

bigint_test: bigint.cpp bigint_test.cpp
	g++ -o build/$@ $^ -lm -O2

%: %.cpp
	g++ -o build/$@ $< -lm -O2

clean:
	rm -f build/*

