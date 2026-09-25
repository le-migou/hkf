CXXFLAGS=-std=c++2b -Wall -Wextra -g \
	-I${HOME}/calculisto/iapws/include \
	-I${HOME}/calculisto/array/include \
	-I${HOME}/calculisto/root_finding/include \
	-I${HOME}/calculisto/auto_diff/include \
	-I${HOME}/calculisto/finite_difference/include \


LDLIBS+=-lfmt


supcrt25: supcrt25.cpp sprons92.hpp format_strings.hpp
