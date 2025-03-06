#include <stdlib.h>
#include <string.h>

#include "set.h"

int main(int argc, char **argv) {
	Set* set = set_new(4);

	/* strdup() ensures that set_free() works */
	/* elements inserted into set() must be heap allocated */
	set_add(set, strdup("a"));
	set_add(set, strdup("ab"));
	set_add(set, strdup("abc"));
	set_add(set, strdup("abcd"));

	set_add(set, strdup("abcde"));
	set_add(set, strdup("abcdef"));
	set_add(set, strdup("abcdefg"));
	set_add(set, strdup("abcdefgh"));

	/* inserting same element multiple times */
	char* str1 = strdup("I");
	set_add(set, str1);
	set_add(set, str1);
	set_add(set, str1);

	set_print(set);

	/* stack allocated strings are compared with heap allocated strings! */
	if (set_find(set, "a")) { printf("%s found!\n", "a"); }
	if (!set_find(set, "cba")) { printf("%s not found!\n", "cba"); }

	char* str2 = strdup("II");
	if (set_find(set, str1)) { printf("%s found!\n", str1); }
	if (!set_find(set, str2)) { printf("%s not found!\n", str2); }
	free(str2);

	set_free(set);
	return EXIT_SUCCESS;
}
