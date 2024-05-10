build:
	mkdir -p target
	g++ src/main.cpp -o target/main

run: build
	target/main

clean:
	rm -rf target
