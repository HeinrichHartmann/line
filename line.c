#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage %s <line number>\n", argv[0]);
    return 1;
  }
  int l = atoi(argv[1]);
  if (l < 1) {
    printf("Error. Line number must be >=1");
    return 1;
  }

  char * line = NULL;
  size_t linecap = 0;
  ssize_t linelen;
  for(int i=0; i<l; i++){
    linelen = getline(&line, &linecap, stdin);
    if (linelen == -1) return 1; // error
  }
  fwrite(line, linelen, 1, stdout);
  return 0;
}
