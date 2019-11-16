#include <err.h>
#include <histedit.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include "complete.h"

static void
compfunc(const char *input, size_t inlen)
{
	if (inlen >= 1 && input[0] == 'f') {
		addcomp("föö");
		addcomp("fööbar");
		addcomp("fööbaz");
	}
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
