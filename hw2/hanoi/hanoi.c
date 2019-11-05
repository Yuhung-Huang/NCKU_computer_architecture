
volatile char* tx = (volatile char*) 0x40002000;
const char* show = "Move sheet from ";
const char* to = " to "; 
const char* blank= "\n";
char *d;
int n=3;
int x=0;
void main(){
	hanoi(n,'A','B','C');
}
void hanoi(int n,char A,char B,char C){
	if(n==1){
		while(*show){
			*tx = *show;
			show++;
			x++;
		}
		while(x){
			show--;
			x--;
		}

		d = &A;
		*tx = *d;
		while(*to){
			*tx = *to;
			to++;
			x++;
		}
		while(x){
			to--;
			x--;
		}

		d = &C;
		*tx = *d;
		*tx = *blank;
		
	}
	else{
		hanoi(n-1,A,C,B);
		hanoi(1,A,B,C);
		hanoi(n-1,B,A,C);
	}
}
