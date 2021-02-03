/*
Libraries for fields, doubly-linked lists and red-black trees.
Copyright (C) 2001 James S. Plank

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

---------------------------------------------------------------------------
Please see http://www.cs.utk.edu/~plank/plank/classes/cs360/360/notes/Libfdr/
for instruction on how to use this library.

Jim Plank
plank@cs.utk.edu
http://www.cs.utk.edu/~plank

Associate Professor
Department of Computer Science
University of Tennessee
203 Claxton Complex
1122 Volunteer Blvd.
Knoxville, TN 37996-3450

     865-974-4397
Fax: 865-974-4404
*/
#include <stdio.h>
#include "fields.h"

#define talloc(ty, sz) (ty *) malloc (sz * sizeof(ty))
#define strdup(s) ((char *) strcpy(talloc(char, strlen(s)+1), s))

static IS make_inputstruct(char *filename, char *key)
                         /* "f" for regular file or stdin if filename is NULL */
                         /* "p" if filename is a command for popen */
{
  IS is;
  int file;
  
  if (strcmp(key, "f") == 0) {
    file = 1;
  } else if (strcmp(key, "p") == 0) {
    file = 0;
  } else {
    return NULL;
  }

  is = talloc(struct inputstruct, 1);

  is->text1[MAXLEN-1] = '\0';
  is->NF = 0;
  is->line = 0;
  if (filename == NULL) {
    is->name = "stdin";
    is->f = stdin;
  } else {
    is->name = filename;
    is->file = file;
    if (file) {
      is->f = fopen(filename, "r");
    } else {
      is->f = popen(filename, "r");
    }
    if (is->f == NULL) {
      free(is);
      return NULL;
    }
  }
  return is;
}

  

IS new_inputstruct(char *filename)   /* use NULL for stdin.  Calls malloc */
{
  return make_inputstruct(filename, "f");
}

IS pipe_inputstruct(char *command)
{
  return make_inputstruct(command, "p");
}

int get_line(IS is)
{
  int i, len;
  int f;
  char *tmp;
  char lastchar;
  char *line;

  is->NF = 0;

  if (fgets(is->text1, MAXLEN-1, is->f) == NULL) {
    is->NF = -1;
    return -1;
  }

  is->line++;
  strcpy(is->text2, is->text1);

  line = is->text2;
  lastchar = ' ';
  for (i = 0; line[i] != '\0' && i < MAXLEN-1; i++) {
    if (isspace(line[i])) {
      lastchar = line[i];
      line[i] = '\0';
    } else {
      if (isspace(lastchar)) {
        is->fields[is->NF] = line+i;
        is->NF++;
      }
      lastchar = line[i];
    }
  }
  return is->NF;
}

void jettison_inputstruct(IS is)
{
  if (is->f != stdin) {
    if (is->file) {
      fclose(is->f);
    } else {
      pclose(is->f);
    }
  }
  free(is);
  return;
} 
