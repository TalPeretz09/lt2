# Compile the main BMI program
bmi:
	g++ -std=c++11 Code/bmi.cpp Code/main.cpp -o bmi

# Run the main BMI program using test data
test: bmi
	echo "A7B3 6 13 12 5 9\nCC2E 7 10 3 5 11\n" >> study.dat
	./bmi study.dat cats.txt
	cat cats.txt

# Compile and run unit tests using doctest
test_bmi:
	g++ -std=c++11 test/test_bmi.cpp Code/bmi.cpp -o test/test_bmi
	./test/test_bmi

# Clean all generated files
clean:
	rm -f bmi study.dat cats.txt test/test_bmi

