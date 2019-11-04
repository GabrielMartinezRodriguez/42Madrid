#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "hola que taal";
  memset (str,'-',5);
  puts (str);
  return 0;
}
