all:
	g++ rt.cpp Vector.cpp Sphere.cpp Light.cpp -lm -o rt
run:
	./rt < spheres.txt > out.ppm
