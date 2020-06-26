#include <stdio.h>
void cough(int n);

int main(void)
{
  cough(5);
}

void cough(int n) {
  for(int i = 0; i < n; i++)
  printf("cough\n");
}
