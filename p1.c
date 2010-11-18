/* Analyzing the stack - part 1 - p1.c
   Copyright (C) 2010 Xabier Guitián <xguitian@gmail.com>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA */

int main(int argc, char **argv)
{
  cleanstack();
  f1(313, 1, 2, 3);//, 4); //Analyzing the impact of parameter values in the stack, and some recursivity control.
  printf ("Function pointers: f1: %p - cleanstack: %p - main: %p\n",&f1,&cleanstack,&main);
  return 656; // Random value
}

// Clean the stack pushing markers to tell which memory address is unused
int cleanstack() 
{
  int cs[500];
  int csp;
  
  for (csp=0; csp<520; csp++)
  {
    cs[csp]=999999999;
  }
}

// Recursive function to analyze the stack
int f1(int param1, int recLvl, int other, int another)//, int last) 
{
  unsigned int a[20];
  int j=666;
  int i;
  int z=10;
  int *ret;

  for (i=0; i<20; i++)
  {
    a[i] = recLvl*111;
  }

  if (recLvl < 3)
  { // Recursivity
    f1(param1+10, recLvl+1, j+1, j+3);//, j+5);
  }
  else
  {
    for (j=0; j<300; j++)
    { // Printing stack (pointer - hex value - dec value)
      printf("%p -  %#10x  -  %d\n", &a[j-40], a[j-40], a[j-40]);
    }
  }
  
  printf("f1 level %d\n", recLvl);
  return j;
}
