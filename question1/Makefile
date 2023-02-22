.default: all

PROGRAMS=question1

all: $(PROGRAMS)

clean:
	rm -rf $(PROGRAMS) src/*.o *.dSYM

$(PROGRAMS): src/question1.o src/Patient.o src/PatientAdmission.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

src/%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^

# disable all warnings
CXXFLAGS += -w