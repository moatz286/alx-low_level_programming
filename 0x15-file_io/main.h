#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef UNISTD_H
#define UNISTD_H
#include <unistd.h>
#endif

#ifndef _MAIN_H_
#define _MAIN_H_

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif

