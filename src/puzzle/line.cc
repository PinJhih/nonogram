#include "puzzle/line.h"

#include <cstdio>

typedef long long LL;

char Line::buffer[64];

Line::Line() {
	Line(1);
}

Line::Line(int i) {
	index = i;
	for (int i = 0; i < BOARD_SIZE; i++) {
		s[i] = U;
		buffer[i * 2 + 1] = ' ';
	}
	buffer[49] = '\n';
	buffer[50] = '\0';
}

Line::Line(const Line& l) {
	index = l.index;
	for (int i = 0; i < BOARD_SIZE; i++) {
		s[i] = l.s[i];
	}
}

Byte Line::get(int i) {
	if (i == 0)
		return 0;
	return s[i - 1];
}

void Line::set(int i, Byte c) {
	s[i - 1] = c;
}

void Line::print() {
	for (int i = 0; i < 25; i++) {
		if (s[i] == U)
			buffer[i * 2] = 'U';
		else
			buffer[i * 2] = s[i] + '0';
	}
	printf("%s", Line::buffer);
}

Byte Line::getIndex() {
	return index;
}
