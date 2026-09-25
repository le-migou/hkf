.PHONY: check clean

CXXFLAGS=-g \
					-std=c++26 -Wall -Wextra -Wconversion -Wshadow \
					-I../git_submodules/calculisto/auto_diff/include/ \
					-I../git_submodules/calculisto/array/include/ \
					-I../git_submodules/calculisto/iapws/include/ \
					-I../git_submodules/calculisto/root_finding/include/ \
					-I../git_submodules/calculisto/finite_difference/include/ \

LDLIBS+=-lfmt

LINK.o=${LINK.cc}

tests: \
	tests.o \
	test_born.o \
	test_dielectric_constant_sverjensky_2014.o \
	test_eos_h2o_zhang_duan_2005.o \
	test_hkf.o \
	test_supcrt92.o \

check: tests
	./tests


test_born.o:                                test_born.cpp                                 ../include/calculisto/hkf/born.hpp
test_dielectric_constant_sverjensky_2014.o: test_dielectric_constant_sverjensky_2014.cpp  ../include/calculisto/hkf/dielectric_constant_sverjensky_2014.hpp
test_eos_h2o_zhang_duan_2005.o:             test_eos_h2o_zhang_duan_2005.cpp              ../include/calculisto/hkf/eos_h2o_zhang_duan_2005.hpp
test_hkf.o:                                 test_hkf.cpp                                  ../include/calculisto/hkf/hkf.hpp
test_supcrt92.o:                            test_supcrt92.cpp                             ../include/calculisto/hkf/supcrt92.hpp

clean:
	rm -fr *.o tests
