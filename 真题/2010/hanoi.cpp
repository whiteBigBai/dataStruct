#include <stdio.h>


void move(char a,int n,char b){
    printf("move(%c,%d,%c)\n",a,n,b);
}

void hanoi( int n, char x, char y, char z )
{
	if ( n == 1 )
		move( x, 1, z );
	else{
        printf("hanoi(%d,%c,%c,%c)\n",n-1,x,z,y);
		hanoi( n - 1, x, z, y );
		move( x, n, z );
        printf("hanoi(%d,%c,%c,%c)\n",n-1,y,x,z);
		hanoi( n - 1, y, x, z );
	}
}



int main(int argc, char **argv){
    char a='a';
    char b='b';
    char c='c';
    hanoi(3,a,b,c);
}