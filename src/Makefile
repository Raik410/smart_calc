CC = gcc
CFLAGS = -Wall -Werror -Wextra -fprofile-exclude-files=unit_tests/tests.c -fprofile-arcs -ftest-coverage
ALL_FUNCTIONS = calc_functions/*.c
ALL_FUNCTIONS_OBJECT = *.o
LIBNAME = calculator.a
CALCULATOR_TESTS_FOLDER = unit_tests/*.c credit_calc/*.c
LIBS = -lcheck -lsubunit -lm
GCOV_FLAGS = -fprofile-exclude-files=unit_tests/tests.c -fprofile-arcs -ftest-coverage

all:
	make install

$(LIBNAME):
	$(CC) $(CFLAGS) -c $(ALL_FUNCTIONS)
	ar rcs $(LIBNAME) $(ALL_FUNCTIONS_OBJECT)
	rm -rf *.o

install_package:
	sudo apt-get install libvulkan-dev

install:
	cd Qt_calculator/ && mkdir -p build && cd build && cmake .. -DCMAKE_PREFIX_PATH=/opt/Qt/6.6.1/gcc_64 && make


open:
ifeq ($(shell uname), Linux)
	chmod +x Qt_calculator/build/calculator
	cd Qt_calculator/build/ && ./calculator
else ifeq ($(shell uname), Darwin)
	chmod +x Qt_calculator/build/calculator.app/Contents/MacOS/calculator
	cd Qt_calculator/build/calculator.app/Contents/MacOS/ && ./calculator
else
	@echo "Unsupported Operating System."
endif


uninstall:
	rm -rf Qt_calculator/build

main:
	@$(CC) $(CFLAGS) main.c $(ALL_FUNCTIONS) -o main -lm
	@./main
#	@rm main

clang-check:
	clang-format -n ../src/**.c ../src/**.h calc_functions/*.c calc_functions/*.h unit_tests/*.c Qt_calculator/*.cpp Qt_calculator/*.c Qt_calculator/*.h

clang:
	clang-format -i ../src/**.c ../src/**.h calc_functions/*.c calc_functions/*.h unit_tests/*.c Qt_calculator/*.cpp Qt_calculator/*.c Qt_calculator/*.h

test: $(LIBNAME)
	@$(CC) $(CFLAGS) $(CALCULATOR_TESTS_FOLDER) $(LIBNAME) $(LIBS) -o test
	@./test
#	@make clean

gcov_report: test
	gcov calc_functions/*.c
	~/.local/bin/gcovr -r . --html --html-details --exclude calc_functions/stack.c -o calculator.html

main_none_remove:
	@$(CC) $(CFLAGS) main.c $(ALL_FUNCTIONS) -o main -lm
	@./main

clean:
	@rm -rf *.o
	@rm -f main
	@rm -f test
	@rm -f ./a.out *.gcda *.gcno
	@rm -f *.css *.html
	@rm -f calculator.a
	@rm -f about.pdf about.log about.aux
	@rm -f calculator.zip

open_gcovr:
	@echo "OPEN REPORT..."
	xdg-open calculator.html

dist:
	zip -r calculator.zip ../../C7_SmartCalc_v1.0-1/

dvi_package:
	sudo apt install texlive-latex-base

dvi:
	# pdflatex about.tex && evince about.pdf &
	open about.pdf
	

