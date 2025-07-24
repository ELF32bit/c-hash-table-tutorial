#include <stdlib.h>
#include <string.h>

#include "set.h"

int main(int argc, char **argv) {
	Set* set = set_new(4);

	/* set() will duplicate inserted strings on the heap */
	set_add(set, "a");
	set_add(set, "ab");
	set_add(set, "abc");
	set_add(set, "abcd");

	set_add(set, "1");
	set_add(set, "12");
	set_add(set, "123");
	set_add(set, "");

	/* inserting same string multiple times */
	char* str1 = "while"; char* str2 = "while";
	set_add(set, str1);
	set_add(set, str1);
	set_add(set, str2);
	set_add(set, str2);

	/* printing set() */
	set_print(set);

	/* stack allocated strings are compared with heap allocated strings! */
	if (set_find(set, "abc")) { printf("'%s' found!\n", "abc"); }
	if (!set_find(set, "cba")) { printf("'%s' not found!\n", "cba"); }

	set_free(set);
	return EXIT_SUCCESS;
}
