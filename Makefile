CXXFLAGS=-std=c++2b -Wall -Wextra \
	-I${HOME}/calculisto/iapws/include \
	-I${HOME}/calculisto/array/include \
	-I${HOME}/calculisto/root_finding/include \


LDLIBS+=-lfmt

supcrt25: supcrt25.cpp sprons92.hpp format_strings.hpp
