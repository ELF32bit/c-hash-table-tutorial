#include <stdlib.h>
#include <string.h>

#include "set.h"

int main(int argc, char **argv) {
	Set* set = set_new(4);

	set_add(set, strdup("a"));
	set_add(set, strdup("ab"));
	set_add(set, strdup("abc"));
	set_add(set, strdup("abcd"));

	set_add(set, strdup("abcde"));
	set_add(set, strdup("abcdef"));
	set_add(set, strdup("abcdefg"));
	set_add(set, strdup("abcdefgh"));

	char* str1 = strdup("I");
	set_add(set, str1);
	set_add(set, str1);
	set_add(set, str1);

	set_print(set);

	if (set_find(set, "a")) { printf("%s found!\n", "a"); }
	if (!set_find(set, "cba")) { printf("%s not found!\n", "cba"); }
	if (set_find(set, str1)) { printf("%s found!\n", str1); }

	char* str2 = strdup("II");
	if (!set_find(set, str2)) { printf("%s not found!\n", str2); }
	free(str2);

	set_free(set);
	return EXIT_SUCCESS;
}
