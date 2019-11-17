#include <err.h>
#include <histedit.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "complete.h"

#define ARRAY_SIZE(X) (sizeof(X) / sizeof(X[0]))

static char *completions[] = {
    "föö",
    "fööbar",
    "fööbaz",
};

static void
compfunc(const char *input, size_t inlen)
{
	size_t i;

	for (i = 0; i < ARRAY_SIZE(completions); i++)
		if (!strncmp(input, completions[i], inlen))
			addcomp(completions[i]);
}

int
main(void)
{
	int num;
	static EditLine *el;
	const char *line;

	setlocale(LC_CTYPE, "");
	if (!(el = el_init("tabcomp-example", stdin, stdout, stderr)))
		errx(EXIT_FAILURE, "el_init failed");

	/* Initialize word completions */
	initcomp(compfunc, 1);

	/* Bind completion function to tab key */
	el_set(el, EL_ADDFN, "complete", "Complete input", complete);
	el_set(el, EL_BIND, "^I", "complete", NULL);

	while ((line = el_gets(el, &num)) && num >= 0)
		printf("%s", line);
	if (num == -1)
		err(EXIT_FAILURE, "el_gets failed");

	return EXIT_SUCCESS;
}
